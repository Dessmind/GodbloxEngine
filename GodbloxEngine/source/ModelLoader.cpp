#include "ModelLoader.h"

ModelLoader::ModelLoader() 
  : lSdkManager(nullptr), lScene(nullptr)
{
  // Inicialization SDK manager - FBX
  lSdkManager = FbxManager::Create();
  if (!lSdkManager)
  {
    ERROR("ModelLoader", "Create::()", "Unable to create FBX Manager!");
  }
  else
  {
    MESSAGE("ModelLoader", "ModelLoader", "Autodesk FBX SDK version " << lSdkManager->GetVersion());
  }

  // Crear IOSettings object
  FbxIOSettings* ios = FbxIOSettings::Create(lSdkManager, IOSROOT);
  lSdkManager->SetIOSettings(ios);

  // Create new scene SDK
  lScene = FbxScene::Create(lSdkManager, "myScene");
}

ModelLoader::~ModelLoader()
{
  if (lSdkManager) lSdkManager->Destroy();
}

bool 
ModelLoader::LoadModel(const std::string& filePath)
{
  FbxImporter* lImporter = FbxImporter::Create(lSdkManager, "");

  if (!lImporter->Initialize(filePath.c_str(), -1, lSdkManager->GetIOSettings()))
  {
    MESSAGE("ModelLoader", "LoadModel", "Unable to initialize FBX importer for file: " << filePath.c_str())
      ERROR("ModelLoader", "LoadModel", "Error returned: " << lImporter->GetStatus().GetErrorString());
    return false;
  }

  // Import the scene
  if (!lImporter->Import(lScene))
  {
    ERROR("ModelLoader", "lImporter->Import", "Unable to import the FBX Scene from file: " << filePath.c_str());
    lImporter->Destroy();
    return false;
  }

  // Destroy the importer
  lImporter->Destroy();
  MESSAGE("ModelLoader", "LoadModel", "Successfully imported the FBX scene from file: " << filePath.c_str());

  return true;
}

void 
ModelLoader::ProcessNode(FbxNode* node)
{
  // Process all the nodes meshes
  if (node->GetNodeAttribute())
  {
    if (node->GetNodeAttribute()->GetAttributeType() == FbxNodeAttribute::eMesh)
    {
      ProcessMesh(node->GetMesh());
    }
  }

  for (int i = 0; i < node->GetChildCount(); i++)
  {
    ProcessNode(node->GetChild(i));
  }
}

void 
ModelLoader::ProcessMesh(FbxMesh* mesh)
{
  int polygonCount = mesh->GetPolygonCount();
  vertices.reserve(polygonCount * 3);
  indices.reserve(polygonCount * 3);

  // Get the UV set name
  const char* uvSetName = nullptr;
  FbxStringList uvSetNameList;
  mesh->GetUVSetNames(uvSetNameList);
  if (uvSetNameList.GetCount() > 0)
  {
    uvSetName = uvSetNameList.GetStringAt(0);
  }
  else
  {
    ERROR("ModelLoader", "ProcessMesh", "No UV set found in the mesh")
    return;
  }

  // Get vertices and indices
  for (int i = 0; i < polygonCount; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      SimpleVertex vertex;

      // Get vertex position
      int controlPointIndex = mesh->GetPolygonVertex(i, j);
      FbxVector4 pos = mesh->GetControlPointAt(controlPointIndex);
      vertex.Pos = XMFLOAT3(static_cast<float>(pos[0]),
                            static_cast<float>(pos[1], 
                            static_cast<float>(pos[2]));

      // Get texture coordinates
      FbxVector4 texCoord;
      bool unmapped;
      mesh->GetPolygonVertexUV(i, j, uvSetName, texCoord, unmapped);
      vertex.Tex = XMFLOAT2(static_cast<float>(texCoord[0]), 
                            static_cast<float>(texCoord[1]));

      // Add the vertex to the list
      vertices.push_back(vertex);
      indices.push_back(vertices.size() - 1);
    }
  }
}

