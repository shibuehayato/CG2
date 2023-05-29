#include <cstdint>
#include "WinApp.h"

typedef struct Vector4
{
	float x;
	float y;
	float z;
	float w;
} Vector4;

WinApp* window_ = new WinApp();

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	WinApp::CreateWindowView(window_->title);

	MSG msg{};

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{

		}
	}
	return 0;
}