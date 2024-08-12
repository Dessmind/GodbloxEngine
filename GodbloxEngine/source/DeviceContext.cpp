#include "DeviceContext.h"

void DeviceContext::destroy()
{
	// SAFE_RELEASE es una macro que libera el recurso y lo pone en nullptr para 
	// evitar errores.
	SAFE_RELEASE(m_deviceContext);
}


void DeviceContext::PSSetShaderResources(unsigned int StartSlot, 
											unsigned int NumViews, 
											ID3D11ShaderResourceView* const* ppShaderResourceViews)
{
	// Verifica si las vistas de recursos del shader no son nulas; si lo son, 
	// muestra un error y termina.
	if (ppShaderResourceViews == nullptr)
	{
		ERROR("DeviceContext", "PSSetShaderResources", "CHECK FOR ID3D11ShaderResourceView* const* ppShaderResourceViews")
		exit(1);
	}
	else
	{
		// Asigna las vistas de recursos al pipeline de píxeles.
		m_deviceContext->PSSetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
	}
}


void DeviceContext::RSSetViewports(unsigned int NumViewports, const D3D11_VIEWPORT* pViewports)
{
	// Verifica si los viewports no son nulos; si lo son, muestra un error y termina.
	if (pViewports == nullptr)
	{
		ERROR("DeviceContext", "RSSetViewports", "CHECK FOR const D3D11_VIEWPORT* pViewports")
			exit(1);
	}
	else
	{
		// Asigna los viewports al pipeline.
		m_deviceContext->RSSetViewports(NumViewports, pViewports);
	}
}


void DeviceContext::IASetInputLayout(ID3D11InputLayout* pInputLayout)
{
	// Verifica si el layout de entrada no es nulo; si lo es, muestra un error 
	// y termina.
	if (pInputLayout == nullptr)
	{
		ERROR("DeviceContext", "IASetLayout", "CHECK FOR ID3D11InputLayout* pInputLayout")
			exit(1);
	}
	else
	{
		// Asigna el layout de entrada al pipeline.
		m_deviceContext->IASetInputLayout(pInputLayout);
	}
}


void DeviceContext::VSSetShader(ID3D11VertexShader* pVertexShader, ID3D11ClassInstance* const* ppClassInstances, unsigned int NumClassInstances)
{
	// Verifica si el shader de vértices no es nulo; si lo es, muestra un error 
	// y termina.
	if (pVertexShader == nullptr)
	{
		ERROR("DeviceContext", "VSSetShader", "CHECK FOR ID3D11VertexShader* pVertexShader")
			exit(1);
	}
	else
	{
		// Asigna el shader de vértices al pipeline.
		m_deviceContext->VSSetShader(pVertexShader, ppClassInstances, NumClassInstances);
	}
}


void DeviceContext::PSSetShader(ID3D11PixelShader* pPixelShader, ID3D11ClassInstance* const* ppClassInstances, unsigned int NumClassInstances)
{
	// Verifica si el shader de píxeles no es nulo; si lo es, muestra un 
	// error y termina.
	if (pPixelShader == nullptr)
	{
		ERROR("DeviceContext", "PSSetShader", "CHECK FOR ID3D11PixelShader* pPixelShader")
			exit(1);
	}
	else
	{
		// Asigna el shader de píxeles al pipeline.
		m_deviceContext->PSSetShader(pPixelShader, ppClassInstances, NumClassInstances);
	}
}


void DeviceContext::UpdateSubresource(ID3D11Resource* pDstResource, unsigned int DstSubresource, const D3D11_BOX* pDstBox, const void* pSrcData, unsigned int SrcRowPitch, unsigned int SrcDepthPitch)
{
	// Copia los datos desde la CPU a la GPU en la ubicación especificada.
	m_deviceContext->UpdateSubresource(pDstResource, DstSubresource, pDstBox, pSrcData, SrcRowPitch, SrcDepthPitch);
}


void DeviceContext::IASetVertexBuffers(unsigned int StartSlot, unsigned int NumBuffers, ID3D11Buffer* const* ppVertexBuffers, const unsigned int* pStrides, const unsigned int* pOffsets)
{
	// Asigna los buffers de vértices al pipeline de entrada.
	m_deviceContext->IASetVertexBuffers(StartSlot, NumBuffers, ppVertexBuffers, pStrides, pOffsets);
}


void DeviceContext::IASetIndexBuffer(ID3D11Buffer* pIndexBuffer, DXGI_FORMAT Format, unsigned int Offset)
{
	// Asigna el buffer de índices al pipeline de entrada.
	m_deviceContext->IASetIndexBuffer(pIndexBuffer, Format, Offset);
}


void DeviceContext::PSSetSamplers(unsigned int StartSlot, unsigned int NumSamplers, ID3D11SamplerState* const* ppSamplers)
{
	// Verifica si los samplers no son nulos; si lo son, muestra un error.
	if (ppSamplers == nullptr)
	{
		ERROR("DeviceContext", "PSSetSamplers", "CHECK FOR ID3D11SamplerState* const* ppSamplers");
	}
	else
	{
		// Asigna los samplers al pipeline de píxeles.
		m_deviceContext->PSSetSamplers(StartSlot, NumSamplers, ppSamplers);
	}
}

// PIPELINE: Un pipeline en gráficos es como una línea de montaje para imágenes. 
// Los datos de gráficos pasan por diferentes "estaciones" en esta línea para ser 
// transformados y combinados. Cada estación hace una parte del trabajo, como ajustar 
// la forma de los objetos, agregar colores, o combinar todos los detalles para formar 
// la imagen final que ves en pantalla.

//Esencialmente, el pipeline toma la información de los objetos 3D y la convierte en 
// la imagen 2D que ves en tu monitor.