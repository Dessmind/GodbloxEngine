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


// Crea una "vista de renderizado" que b�sicamente es donde la GPU dibuja 
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

// Crea una "vista de profundidad y stencil", que ayuda a manejar qu� objetos 
// est�n delante o detr�s en la escena.
HRESULT
CreateDepthStencilView(ID3D11Resource* pResource,
												const D3D11_DEPTH_STENCIL_VIEW_DESC* pDesc,
												ID3D11DepthStencilView** ppDepthStencilView);

// Crea un "shader de v�rtices", que es un peque�o programa que se encarga de 
// procesar cada v�rtice antes de que se dibuje en la pantalla.
HRESULT
CreateVertexShader(const void* pShaderBytecode,
										SIZE_T BytecodeLength,
										ID3D11ClassLinkage* pClassLinkage,
										ID3D11VertexShader** ppVertexShader);

// Define el formato de los datos de los v�rtices para que el shader de v�rtices
//  sepa c�mo interpretarlos.
HRESULT 
CreateInputLayout(const D3D11_INPUT_ELEMENT_DESC* pInputElementDescs,
									UINT NumElements,
									const void* pShaderBytecodeWithInputSignature,
									SIZE_T BytecodeLength,
									ID3D11InputLayout** ppInputLayout);

// Crea un "shader de p�xeles", que decide el color de cada p�xel despu�s de que 
// se haya procesado la geometr�a.
HRESULT 
CreatePixelShader(const void* pShaderBytecode,
									SIZE_T BytecodeLength,
									ID3D11ClassLinkage* pClassLinkage,
									ID3D11PixelShader** ppPixelShader);

// Crea un "buffer" que es un espacio en la memoria de la GPU donde se guardan 
// datos como los v�rtices o colores.
HRESULT 
CreateBuffer(const D3D11_BUFFER_DESC* pDesc,
							const D3D11_SUBRESOURCE_DATA* pInitialData,
							ID3D11Buffer** ppBuffer);

// Crea un "estado de muestreo", que decide c�mo se ven las texturas cuando se 
// aplican a los objetos (por ejemplo, si se ven borrosas o n�tidas).
HRESULT 
CreateSamplerState(const D3D11_SAMPLER_DESC* pSamplerDesc,
										ID3D11SamplerState** ppSamplerState);



public:
	ID3D11Device* m_device = nullptr;
};