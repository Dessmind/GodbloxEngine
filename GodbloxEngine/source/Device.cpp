#include "Device.h"

void Device::init()
{

}

void Device::update()
{

}

void Device::render()
{

}

void Device::destroy()
{
	// SAFE_RELEASE es una macro que libera el recurso y lo pone en nullptr para evitar errores.
	SAFE_RELEASE(m_device);
}


// Esta función crea una "vista de renderizado", que es como una pantalla donde la GPU dibuja.
HRESULT
Device::CreateRenderTargetView(ID3D11Resource* pResource,
	const D3D11_RENDER_TARGET_VIEW_DESC* pDesc,
	ID3D11RenderTargetView** ppRTView)
{
	HRESULT hr = S_OK;

	// Verifica si los punteros no son nulos antes de intentar crear la vista de renderizado.
	if (pResource != nullptr || ppRTView != nullptr)
	{
		hr = m_device->CreateRenderTargetView(pResource, pDesc, ppRTView);
		MESSAGE("Device", "CreateTexture2D", "OK");
	}
	// Si los punteros son nulos, muestra un error y termina el programa.
	else
	{
		ERROR("Device", "CreateTexture2D", "CHECK FOR CREATION METHOD")
			exit(1);
	}
	return hr;
}


// Esta función crea una textura 2D, que la GPU usa para dibujar o 
// almacenar datos como imágenes.
HRESULT
Device::CreateTexture2D(const D3D11_TEXTURE2D_DESC* pDesc,
	const D3D11_SUBRESOURCE_DATA* pInitialData,
	ID3D11Texture2D** ppTexture2D)
{
	HRESULT hr = S_OK;

	// Verifica si los punteros no son nulos antes de intentar crear 
	// la textura 2D.
	if (pDesc != nullptr || ppTexture2D != nullptr)
	{
		hr - m_device->CreateTexture2D(pDesc, pInitialData, ppTexture2D);
		MESSAGE("Device", "CreateTexture2D", "OK")
	}
	// Si los punteros son nulos, muestra un error y termina el programa.
	else
	{
		ERROR("Device", "CreateTexture2D", "CHECK FOR CREATION METHOD")
			exit(1);
	}

	return hr;
}


// Esta función crea una "vista de profundidad y stencil", que ayuda a 
// manejar la profundidad en la escena.
HRESULT
Device::CreateDepthStencilView(ID3D11Resource* pResource,
	const D3D11_DEPTH_STENCIL_VIEW_DESC* pDesc,
	ID3D11DepthStencilView** ppDepthStencilView)
{
	HRESULT hr = S_OK;

	// Verifica si el recurso de profundidad no es nulo; si lo es, muestra 
	// un error y termina.
	if (pResource == nullptr)
	{
		ERROR("Device", "CreateDepthStencilView", "CHECK FOR ID3D11Resource* pResource")
			exit(1);
	}
	// Verifica si la vista de profundidad y stencil no es nula; si lo es, 
	// muestra un error y termina.
	else if (ppDepthStencilView == nullptr)
	{
		ERROR("Device", "CreateDepthStencilView", "CHECK FOR ID3D11DepthStencilView** ppDepthStencilView")
			exit(1);
	}
	// Si todo está bien, crea la vista de profundidad y stencil.
	else
	{
		hr = m_device->CreateDepthStencilView(pResource,
			pDesc,
			ppDepthStencilView);
		MESSAGE("Device", "CreateDepthStencilView", "OK")
	}

	return E_NOTIMPL;
}


// Esta función crea un "shader de vértices", que es un programa pequeño 
// que procesa cada vértice antes de dibujar.
HRESULT
Device::CreateVertexShader(const void* pShaderBytecode,
	SIZE_T BytecodeLength,
	ID3D11ClassLinkage* pClassLinkage,
	ID3D11VertexShader** ppVertexShader)
{
	HRESULT hr = S_OK;

	// Verifica si el código del shader no es nulo; si lo es, muestra un 
	// error y termina.
	if (pShaderBytecode == nullptr)
	{
		ERROR("Device", "CreateVertexShader", "CHECK FOR const void* pShaderBytecode")
			exit(1);
	}
	// Verifica si la referencia al shader de vértices no es nula; si lo es, 
	// muestra un error y termina.
	else if (ppVertexShader == nullptr)
	{
		ERROR("Device", "CreateVertexShader", "CHECK FOR ID3D11VertexShader** pVertexShader")
			exit(1);
	}
	// Si todo está bien, crea el shader de vértices.
	else
	{
		hr = m_device->CreateVertexShader(pShaderBytecode,
			BytecodeLength,
			pClassLinkage,
			ppVertexShader);
		MESSAGE("Device", "CreateVertexShader", "OK")
	}

	return hr;
}


// Esta función define cómo se organizan los datos de los vértices para que 
// el shader de vértices sepa cómo leerlos.
HRESULT Device::CreateInputLayout(const D3D11_INPUT_ELEMENT_DESC* pInputElementDescs,
	UINT NumElements,
	const void* pShaderBytecodeWithInputSignature,
	SIZE_T BytecodeLength,
	ID3D11InputLayout** ppInputLayout)
{
	HRESULT hr = S_OK;

	// Verifica si la descripción de los elementos de entrada no es nula; 
	// si lo es, muestra un error y termina.
	if (pInputElementDescs == nullptr)
	{
		ERROR("Device", "CreateInputLayout", "CHECK FOR const D3D11_INPUT_ELEMENT_DESC* pInputElementDescs")
			exit(1);
	}
	// Verifica si el bytecode del shader no es nulo; si lo es, muestra un 
	// error y termina.
	else if (pShaderBytecodeWithInputSignature == nullptr)
	{
		ERROR("Device", "CreateInputLayout", "CHECK FOR const void* pShaderBytecodeWithInputSignature")
			exit(1);
	}
	// Verifica si la referencia al diseño de entrada no es nula; si lo es, 
	// muestra un error y termina.
	else if (ppInputLayout == nullptr)
	{
		ERROR("Device", "CreateInputLayout", "CHECK FOR  ID3D11InputLayout** ppInputLayout")
			exit(1);
	}
	// Si todo está bien, crea el diseño de entrada.
	else
	{
		hr = m_device->CreateInputLayout(pInputElementDescs,
			NumElements,
			pShaderBytecodeWithInputSignature,
			BytecodeLength,
			ppInputLayout);
		MESSAGE("Device", "CreateInputLayout", "OK")
	}
	return hr;
}


// Esta función crea un "shader de píxeles", que decide el color final de 
// cada píxel en la pantalla.
HRESULT Device::CreatePixelShader(const void* pShaderBytecode,
	SIZE_T BytecodeLength,
	ID3D11ClassLinkage* pClassLinkage,
	ID3D11PixelShader** ppPixelShader)
{
	HRESULT hr = S_OK;

	// Verifica si el código del shader no es nulo; si lo es, muestra un 
	// error y termina.
	if (pShaderBytecode == nullptr)
	{
		ERROR("Device", "CreatePixelShader", "CHECK FOR const void* pShaderBytecode")
			exit(1);
	}
	// Verifica si la referencia al shader de píxeles no es nula; si lo es, 
	// muestra un error y termina.
	else if (ppPixelShader == nullptr)
	{
		ERROR("Device", "CreatePixelShader", "CHECK FOR ID3D11PixelShader** ppPixelShader")
			exit(1);
	}
	// Si todo está bien, crea el shader de píxeles.
	else
	{
		hr = m_device->CreatePixelShader(pShaderBytecode,
			BytecodeLength,
			pClassLinkage,
			ppPixelShader);

		MESSAGE("Device", "CreatePixelShader", "OK")
	}
	return hr;
}


// Esta función crea un "buffer", que es un espacio en la memoria de la GPU para guardar datos.
HRESULT Device::CreateBuffer(const D3D11_BUFFER_DESC* pDesc,
	const D3D11_SUBRESOURCE_DATA* pInitialData,
	ID3D11Buffer** ppBuffer)
{
	HRESULT hr = S_OK;

	// Verifica si la descripción del buffer no es nula; si lo es, muestra un error y termina.
	if (pDesc == nullptr)
	{
		ERROR("Device", "CreateBuffer", "CHECK FOR const D3D11_BUFFER_DESC* pDesc")
			exit(1);
	}
	// Verifica si la referencia al buffer no es nula; si lo es, muestra un error y termina.
	else if (ppBuffer == nullptr)
	{
		ERROR("Device", "CreateBuffer", "CHECK FOR ID3D11Buffer** ppBuffer")
			exit(1);
	}
	// Si todo está bien, crea el buffer.
	else
	{
		hr = m_device->CreateBuffer(pDesc,
			pInitialData,
			ppBuffer);

		MESSAGE("Device", "CreateBuffer", "OK")
	}
	return hr;
}


// Esta función crea un "estado de muestreo", que decide cómo se ven las texturas aplicadas a los objetos.
HRESULT Device::CreateSamplerState(const D3D11_SAMPLER_DESC* pSamplerDesc,
	ID3D11SamplerState** ppSamplerState)
{
	HRESULT hr = S_OK;

	// Verifica si la descripción del muestreo no es nula; si lo es, muestra un error y termina.
	if (pSamplerDesc == nullptr)
	{
		ERROR("Device", "CreateSamplerState", "CHECK FOR const D3D11_BUFFER_DESC* pDesc")
			exit(1);
	}
	// Verifica si la referencia al estado de muestreo no es nula; si lo es, muestra un error y termina.
	else if (ppSamplerState == nullptr)
	{
		ERROR("Device", "CreateSamplerState", "CHECK FOR ID3D11Buffer** ppBuffer")
			exit(1);
	}
	// Si todo está bien, crea el estado de muestreo.
	else
	{
		hr = m_device->CreateSamplerState(pSamplerDesc, ppSamplerState);
		MESSAGE("Device", "CreateSamplerState", "OK")
	}
	return hr;
}
