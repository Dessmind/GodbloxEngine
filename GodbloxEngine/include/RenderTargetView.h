#pragma once
#include "Prerequisitos.h"
#include "Texture.h"
#include "DepthStencilView.h"
class RenderTargetView
{
public:
	RenderTargetView() = default;
	~RenderTargetView() = default;

	void
	init(Device device, Texture backBuffer, DXGI_FORMAT Format);

	void
	update();

	void
	render(DeviceContext& deviceContext,
					DepthStencilView& depthStencilView,
					unsigned int numViews,
					float ClearColor[4]);

	void destroy();
public:
	ID3D11RenderTargetView* m_renderTargetView = nullptr;


private:

};

