#include "Texture.h"
#include "Device.h"
#include "DeviceContext.h"


HRESULT
Texture::init(Device device, std::string textureName)
{
	if (device.m_device == nullptr)
	{
		ERROR("Texture", "init", "CHECK FOR Device device on texture loading method")
		exit(1);
	}
	HRESULT hr = S_OK;

	hr = D3DX11CreateShaderResourceViewFromFile(device.m_device,
		textureName.c_str(),
		nullptr,
		nullptr,
		&m_textureFromImg,
		nullptr);

	if (FAILED(hr))
	{
		ERROR("Texture", "init", "Error in data from paramas [Check for string textureName -> Verify correct texture Name")
		exit(1);
	}

	return hr;
}

void Texture::init(Device device,
	unsigned int width,
	unsigned int height,
	DXGI_FORMAT Format,
	unsigned int BindFlags)

{
	if (device.m_device == nullptr)
	{
		ERROR("Texture", "init", "CHECK FOR Device device on texture loading method")
			exit(1);
	}
	else if (width <= 0 || height <= 0)
	{
		ERROR("Texture", "init", "CHECK FOR unsigned int width OR unsigned int height")
		exit(1);
	}
	HRESULT hr = S_OK;

	D3D11_TEXTURE2D_DESC desc;
	memset(&desc, 0, sizeof(desc));
	desc.Width = width;
	desc.Height = height;
	desc.MipLevels = 1;
	desc.ArraySize = 1;
	desc.Format = Format;
	desc.SampleDesc.Count = 1;
	desc.SampleDesc.Quality = 0;
	desc.Usage = D3D11_USAGE_DEFAULT;
	desc.BindFlags = BindFlags;
	desc.CPUAccessFlags = 0;
	desc.MiscFlags = 0;
	
	hr = device.CreateTexture2D(&desc, nullptr, &m_texture);
	 
	if (m_texture == nullptr)
	{
		ERROR("Texture", "init", "Error in data drom params [CHECK FOR m_texture]")
		exit(1);
	}
	else if (FAILED(hr))
	{
		ERROR("Texture", "init", "Error in data drom resource [CHECK FOR CreateTexture2D]")
		exit(1);
	}
}

void 
Texture::update() { }

void 
Texture::render(DeviceContext& deviceContext,
				unsigned int StartSlot,
				unsigned int NumViews)
{
	if (m_textureFromImg != nullptr)
	{
		ID3D11ShaderResourceView* nullSRV[] = { nullptr };
		deviceContext.PSSetShaderResources(StartSlot, NumViews, nullSRV);
		deviceContext.PSSetShaderResources(StartSlot, NumViews, &m_textureFromImg);
	}
}

void 
Texture::destroy()
{
	if (m_texture != nullptr)
	{
		SAFE_RELEASE(m_texture);
	}
	else if (m_textureFromImg != nullptr)
	{
		SAFE_RELEASE(m_textureFromImg);
	}
}








//	HRESULT hr = S_OK;
//	switch (extensionType)
//	{
//	case DDS:
//		hr = D3DX11CreateShaderResourceViewFromFile(device.m_device, 
//			textureName.c_str(),
//			nullptr, 
//			nullptr, 
//			&m_textureFromImg, 
//			nullptr);
//
//		if (FAILED(hr))
//		{
//			ERROR("Texture", "init", "Error in data from paramas [Check for string textureName -> Verify correct texture Name")
//		}break;
//	case PNG:
//		int width, height, channels;
//		//Cargar la imagen
//		unsigned char* data = stbi_load(textureName.c_str(), &width, &height, &channels, 4); // 4 for RGBA
//		if (!data)
//		{
//			ERROR("Texture", "stbi_load", "Error al cargar la imagen" << stbi_failure_reason())
//				return E_FAIL;
//		}
//
//
//		D3D11_TEXTURE2D_DESC texturesDesc = {};
//		texturesDesc.Width = width;
//		texturesDesc.Height = height;
//		texturesDesc.MipLevels = 1;
//		texturesDesc.ArraySize = 1;
//		texturesDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
//		texturesDesc.SampleDesc.Count = 1;
//		texturesDesc.Usage = D3D11_USAGE_DEFAULT;
//		texturesDesc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
//
//
//		D3D11_SUBRESOURCE_DATA initData = {};
//		initData.pSysMem = data;
//		initData.SysMemPitch = width * 4;
//
//		ID3D11Texture2D* texture = nullptr;
//		hr = device.CreateTexture2D(&texturesDesc, &initData, &texture);
//		if (FAILED(hr))
//		{
//			stbi_image_free(data);
//			return hr;
//		}
//
//		//Descripción del recurso de la textura
//		D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc = {};
//		srvDesc.Format = texturesDesc.Format;
//		srvDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
//		srvDesc.Texture2D.MipLevels = 1;
//		hr = device.m_device->CreateShaderResourceView(texture, &srvDesc, &m_textureFromImg);
//		texture->Release();
//		stbi_image_free(data);
//		break;
//	}
//
//
//}
//
//void Texture::init(Device device,
//	unsigned int width,
//	unsigned int height,
//	DXGI_FORMAT Format,
//	unsigned int BindFlags)
//{
//
//	if (device.m_device == nullptr)
//	{
//		ERROR("Texture", "init", "CHECK FOR Device device on texture loading method")
//			exit(1);
//	}
//	else if (width <= 0 || height <= 0)
//	{
//		ERROR("Texture", "init", "CHECK FOR unsigned int width or unsigned int height")
//			exit(1);
//	}
//
//	HRESULT hr = S_OK;
//
//	D3D11_TEXTURE2D_DESC desc;
//	memset(&desc, 0, sizeof(desc));
//	desc.Width = width;
//	desc.Height = height;
//	desc.MipLevels = 1;
//	desc.ArraySize = 1;
//	desc.Format = Format;
//	desc.SampleDesc.Count = 1;
//	desc.SampleDesc.Quality = 0;
//	desc.Usage = D3D11_USAGE_DEFAULT;
//	desc.BindFlags = BindFlags;
//	desc.CPUAccessFlags = 0;
//	desc.MiscFlags = 0;
//
//	hr = device.CreateTexture2D(&desc, nullptr, &m_texture);
// 
//	if (m_texture == nullptr)
//	{
//		ERROR("Texture", "init", "Error in data drom params [CHECK FOR m_texture]")
//		exit(1);
//	}
//	else if (FAILED(hr))
//	{
//		ERROR("Texture", "init", "Error in data drom resource [CHECK FOR CreateTexture2D]")
//		exit(1);
//	}
//}
//
//void Texture::update()
//{
//}
//
//void Texture::render(DeviceContext& deviceContext,
//	unsigned int StartSlot,
//	unsigned int NumViews)
//{
//	if (m_textureFromImg != nullptr)
//	{
//		ID3D11ShaderResourceView* nullSRV[] = { nullptr };
//		deviceContext.PSSetShaderResources(StartSlot, NumViews, nullSRV);
//		deviceContext.PSSetShaderResources(StartSlot, NumViews, &m_textureFromImg);
//	}
//}
//
//void Texture::destroy()
//{
//	if (m_texture != nullptr)
//	{
//		SAFE_RELEASE(m_texture);
//	}
//	else if (m_textureFromImg != nullptr)
//	{
//		SAFE_RELEASE(m_textureFromImg);
//	}
//}