#pragma once
#include <windows.h>
#include <cstdint>

class WinApp {
public:

	// ウィンドウサイズ
	static const int kWindowWidth = 1280; // 横幅
	static const int kWindowHeight = 720; // 縦幅

	/// ウィンドウプロシージャ
	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
	const wchar_t*  title = L"CG2";
	static void CreateWindowView(const wchar_t* title = L"CG2");
	
private:
	// ウィンドウクラス
	static inline WNDCLASS wc{};

	static HWND hwnd;
};