#include <cstdint>
#include "WinApp.h"
#include "DirectXCommon.h"


const wchar_t kWindowTitle[] = { L"CG2" };

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	
	//初期化
	WinApp::CreateWindowView(kWindowTitle);
	DirectXCommon::DirectXInitialization();
	

	MSG msg{};
	// ウィンドウのxが押されるまでループ
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			// ゲームの処理
		}
	}
	return 0;
}