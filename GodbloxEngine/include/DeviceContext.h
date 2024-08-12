#pragma once
#include "Prerequisitos.h"


class DeviceContext
{
public:
	DeviceContext() = default;
	~DeviceContext() = default;

	void init();

	void update();

	void render();

	void destroy();

	// Establece las vistas de recursos del shader en el pipeline de p�xeles.
	void PSSetShaderResources(unsigned int StartSlot, 
								unsigned int NumViews, 
								ID3D11ShaderResourceView* const* ppShaderResourceViews);

	// Establece los viewports (regiones de la pantalla donde se dibujan los 
	// gr�ficos).
	void RSSetViewports(unsigned int NumViewports, 
						const D3D11_VIEWPORT* pViewports);

	// Establece el layout de entrada (c�mo los datos de v�rtices est�n 
	// organizados en la memoria).
	void IASetInputLayout(ID3D11InputLayout* pInputLayout);

	// Establece el shader de v�rtices (programa que procesa los v�rtices) 
	// en el pipeline.
	void VSSetShader(ID3D11VertexShader* pVertexShader, 
					ID3D11ClassInstance* const* ppClassInstances, 
					unsigned int NumClassInstances);

	// Establece el shader de p�xeles (programa que procesa los p�xeles) en 
	// el pipeline.
	void PSSetShader(ID3D11PixelShader* pPixelShader, 
					ID3D11ClassInstance* const* ppClassInstances, 
					unsigned int NumClassInstances);

	// Actualiza los datos en un recurso de la GPU (como una textura o un 
	// buffer).
	void UpdateSubresource(ID3D11Resource* pDstResource, 
							unsigned int DstSubresource, 
							const D3D11_BOX* pDstBox, 
							const void* pSrcData, 
							unsigned int SrcRowPitch, 
							unsigned int SrcDepthPitch);

	// Establece los buffers de v�rtices (donde se almacenan los datos de 
	// v�rtices) en el pipeline de entrada.
	void IASetVertexBuffers(unsigned int StartSlot, 
							unsigned int NumBuffers, 
							ID3D11Buffer* const* ppVertexBuffers, 
							const unsigned int* pStrides, 
							const unsigned int* pOffsets);

	// Establece el buffer de �ndices (donde se almacenan los �ndices que 
	// definen la geometr�a) en el pipeline de entrada.
	void IASetIndexBuffer(ID3D11Buffer* pIndexBuffer, 
							DXGI_FORMAT Format, 
							unsigned int Offset);

	// Establece los samplers (que controlan c�mo se muestrean las texturas) 
	// en el pipeline de p�xeles.
	void PSSetSamplers(unsigned int StartSlot, 
						unsigned int NumSamplers, 
						ID3D11SamplerState* const* ppSamplers);

public:
	ID3D11DeviceContext* m_deviceContext = nullptr;
};

// PIPELINE: Un pipeline en gr�ficos es como una l�nea de montaje para im�genes. 
// Los datos de gr�ficos pasan por diferentes "estaciones" en esta l�nea para ser 
// transformados y combinados. Cada estaci�n hace una parte del trabajo, como ajustar 
// la forma de los objetos, agregar colores, o combinar todos los detalles para formar 
// la imagen final que ves en pantalla.

//Esencialmente, el pipeline toma la informaci�n de los objetos 3D y la convierte en 
// la imagen 2D que ves en tu monitor.