#pragma once
#include <Windows.h>
#include <cstdint>

class WinApp {
public:

	// ウィンドウクラス
	static inline WNDCLASS wc_{};

	/// ウィンドウプロシージャ
	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

	HWND GetHwnd() const { return hwnd_; }
	static void CreateWindowView(const wchar_t* title = L"CG2");
	
private:

	// ウィンドウサイズ
	static const int kWindowWidth_ = 1280; // 横幅
	static const int kWindowHeight_ = 720; // 縦幅

	//ウィンドウオブジェクト
	static HWND hwnd_;
};