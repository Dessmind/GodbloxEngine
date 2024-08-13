#pragma once
#include "Prerequisitos.h"

class 
Device
{
public:
	Device() = default;
	~Device() = default;

	void 
	init();

	void 
	update();

	void 
	render();

	void 
	destroy();


// Crea una "vista de renderizado" que básicamente es donde la GPU dibuja 
// en la pantalla.
HRESULT
CreateRenderTargetView(ID3D11Resource* pResource,
												const D3D11_RENDER_TARGET_VIEW_DESC* pDesc,
												ID3D11RenderTargetView** ppRTView);

// Crea una textura 2D (como una imagen) que la GPU puede usar para dibujar 
// o almacenar datos.
HRESULT
CreateTexture2D(const D3D11_TEXTURE2D_DESC* pDesc,
								const D3D11_SUBRESOURCE_DATA* pInitialData,
								ID3D11Texture2D** ppTexture2D);

// Crea una "vista de profundidad y stencil", que ayuda a manejar qué objetos 
// están delante o detrás en la escena.
HRESULT
CreateDepthStencilView(ID3D11Resource* pResource,
												const D3D11_DEPTH_STENCIL_VIEW_DESC* pDesc,
												ID3D11DepthStencilView** ppDepthStencilView);

// Crea un "shader de vértices", que es un pequeño programa que se encarga de 
// procesar cada vértice antes de que se dibuje en la pantalla.
HRESULT
CreateVertexShader(const void* pShaderBytecode,
										SIZE_T BytecodeLength,
										ID3D11ClassLinkage* pClassLinkage,
										ID3D11VertexShader** ppVertexShader);

// Define el formato de los datos de los vértices para que el shader de vértices
//  sepa cómo interpretarlos.
HRESULT 
CreateInputLayout(const D3D11_INPUT_ELEMENT_DESC* pInputElementDescs,
									UINT NumElements,
									const void* pShaderBytecodeWithInputSignature,
									SIZE_T BytecodeLength,
									ID3D11InputLayout** ppInputLayout);

// Crea un "shader de píxeles", que decide el color de cada píxel después de que 
// se haya procesado la geometría.
HRESULT 
CreatePixelShader(const void* pShaderBytecode,
									SIZE_T BytecodeLength,
									ID3D11ClassLinkage* pClassLinkage,
									ID3D11PixelShader** ppPixelShader);

// Crea un "buffer" que es un espacio en la memoria de la GPU donde se guardan 
// datos como los vértices o colores.
HRESULT 
CreateBuffer(const D3D11_BUFFER_DESC* pDesc,
							const D3D11_SUBRESOURCE_DATA* pInitialData,
							ID3D11Buffer** ppBuffer);

// Crea un "estado de muestreo", que decide cómo se ven las texturas cuando se 
// aplican a los objetos (por ejemplo, si se ven borrosas o nítidas).
HRESULT 
CreateSamplerState(const D3D11_SAMPLER_DESC* pSamplerDesc,
										ID3D11SamplerState** ppSamplerState);



public:
	ID3D11Device* m_device = nullptr;
};