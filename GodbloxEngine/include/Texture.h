#pragma once
#include "Prerequisitos.h"

class Device;
class DeviceContext;

class Texture
{
public:
	Texture() = default;
	~Texture() = default;

	/// <summary>
	/// Brief: Crea una textura a partir de una imagen (.dds) desde nuestro ordenador.
	/// </summary>
	/// <param name="device"> El dispositivo que usaremos para crear la textura en memoria. </param> 
	/// <param name="textureName"> El nombre del archivo de la textura que queremos cargar. </param>
	/// <returns> Devuelve un resultado que indica si la creación fue exitosa o no. </returns>
	HRESULT
	init(Device device, std::string textureName);

	/// <summary>
	/// Brief: Crea una textura con dimensiones y formato específicos, sin cargar desde un archivo.
	/// </summary>
	/// <param name="device"> El dispositivo que usaremos para crear la textura en memoria. </param>
	/// <param name="width"> Ancho de la textura en píxeles. </param>
	/// <param name="height"> Alto de la textura en píxeles. </param>
	/// <param name="Format"> Formato de la textura, que define cómo se almacenan los colores. </param>
	/// <param name="BindFlags"> Especifica cómo se usará la textura, como para renderizar o para la lectura. </param>
	void init(Device device, 
				unsigned int width, 
				unsigned int height, 
				DXGI_FORMAT Format, 
				unsigned int BindFlags);

	/// <summary>
	/// Brief: Actualiza los datos de la textura con nueva información.
	/// </summary>
	void update();

	/// <summary>
	/// Brief: Envía la textura al dispositivo de renderizado para que se use en la visualización.
	/// </summary>
	/// <param name="deviceContext"> El contexto del dispositivo que maneja la renderización. </param>
	/// <param name="StartSlot"> El punto de inicio donde se asignará la textura en el pipeline de renderizado. </param>
	/// <param name="NumViews"> Número de vistas de la textura a configurar. </param>
	void render(DeviceContext& deviceContext, unsigned int StartSlot, unsigned int NumViews);

	/// <summary>
	/// Brief: Libera los recursos usados por la textura y limpia la memoria.
	/// </summary>
	void destroy();



public:
	// Puntero a una textura 2D de Direct3D 11. Usado para almacenar la textura en la memoria del GPU.
	ID3D11Texture2D* m_texture = nullptr;

	// Puntero a una vista de recurso de shader para la textura. Permite que el shader acceda a la textura cargada desde una imagen.
	ID3D11ShaderResourceView* m_textureFromImg;
};