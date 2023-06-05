#include<WinApp.h>

// ウィンドウプロシージャ
LRESULT CALLBACK WinApp::WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	// メッセージに応じてゲーム固有の処理を行う
	switch (msg)
	{
		// ウィンドウが破棄された
	case WM_DESTROY:
		// OSに対して、アプリの終了を伝える
		PostQuitMessage(0);
		return 0;
	}
	// 標準のメッセージ処理を行う
	return DefWindowProc(hwnd, msg, wparam, lparam);
}

void WinApp::CreateWindowView(const wchar_t* title)
{
	// ウィンドウプロシージャ
	wc_.lpfnWndProc = WindowProc;
	// クラス名
	wc_.lpszClassName = L"CG2WindowClass";
	// インスタンスハンドル
	wc_.hInstance = GetModuleHandle(nullptr);
	// カーソル
	wc_.hCursor = LoadCursor(nullptr, IDC_ARROW);
	// ウィンドウ登録
	RegisterClass(&wc_);

	// ウィンドウサイズの構造体にクライアント領域を入れる
	RECT wtc = { 0, 0, kWindowWidth_, kWindowHeight_ };

	// クライアント領域を元に実際のサイズにwrcを変更してもらう
	AdjustWindowRect(&wtc, WS_OVERLAPPEDWINDOW, false);

	// ウィンドウの生成
	hwnd_ = CreateWindow(
		wc_.lpszClassName,     // クラス名
		title,                // タイトルバーの名前
		WS_OVERLAPPEDWINDOW,  // ウィンドウスタイル
		CW_USEDEFAULT,		  // 表示X座標
		CW_USEDEFAULT,		  // 表示Y座標
		wtc.right - wtc.left, // ウィンドウ横幅
		wtc.bottom - wtc.top, // ウィンドウ縦幅
		nullptr,			  // 親ウィンドウハンドル
		nullptr,			  // メニューハンドル
		wc_.hInstance,		  // インスタンスハンドル
		nullptr				  // オプション
	);
	// ウィンドウの表示
	ShowWindow(hwnd_, SW_SHOW);
}
HWND WinApp::hwnd_;