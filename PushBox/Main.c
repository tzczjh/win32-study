#include <Windows.h>
#include <tchar.h>

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

LRESULT WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPCTSTR lpcCmdLine, int nCmdShow) {
	LPCTSTR CLASS_NAME = "PushBox";

	WNDCLASS myWindow;
	myWindow.cbClsExtra = 0;
	myWindow.cbWndExtra = 0;
	myWindow.hbrBackground = CreateSolidBrush(RGB(0, 0, 0));
	myWindow.hCursor = LoadCursor(NULL, IDC_ARROW);
	myWindow.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	myWindow.hInstance = hInstance;
	myWindow.lpfnWndProc = WindowProc;
	myWindow.lpszClassName = CLASS_NAME;
	myWindow.lpszMenuName = NULL;
	myWindow.style = CS_VREDRAW | CS_HREDRAW;

	if (!RegisterClass(&myWindow)) {
		MessageBox(NULL, _T("´°¿Ú×¢²áÊ§°Ü£¡"), _T("´íÎó"), MB_OK | MB_ICONERROR);
		return 0;
	}

	HWND hwnd = CreateWindow(CLASS_NAME,
		CLASS_NAME,
		WS_OVERLAPPEDWINDOW^WS_THICKFRAME,
		GetSystemMetrics(SM_CXFULLSCREEN) / 2 - 400,
		GetSystemMetrics(SM_CYFULLSCREEN) / 2 - 300,
		800,
		600,
		NULL,
		NULL,
		hInstance,
		NULL);
	if (hwnd == NULL) {
		MessageBox(NULL, _T("´°¿Ú´´½¨Ê§°Ü£¡"), _T("´íÎó"), MB_OK | MB_ICONERROR);
		return 0;
	}

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}


LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	PAINTSTRUCT ps;
	switch (uMsg)
	{
	case WM_CREATE:
		return 0;
	case WM_PAINT:
		BeginPaint(hwnd, &ps);
		LOGFONT logFont;
		ZeroMemory(&logFont, sizeof(LOGFONT));
		logFont.lfCharSet = GB2312_CHARSET;
		logFont.lfHeight = -50;
		HFONT hFont = CreateFontIndirect(&logFont);
		SelectObject(ps.hdc, hFont);
		SetTextColor(ps.hdc, RGB(255, 255, 255));
		SetBkColor(ps.hdc, RGB(0, 0, 0));
		DrawText(ps.hdc, _T("µÚ1¹Ø"), -1, &(ps.rcPaint), DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		EndPaint(hwnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_KEYDOWN:
		return 0;
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
}