#include <Windows.h>
#include <tchar.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

LRESULT WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPCTSTR lpcCmdLine, int nCmdShow) {
	LPCTSTR CLASS_NAME = _T("�ҵĵ�һ��Win32����");
	WNDCLASS myWindow;
	myWindow.cbClsExtra = 0;
	myWindow.cbWndExtra = 0;
	myWindow.hbrBackground = CreateSolidBrush(RGB(255, 255, 255)); //������ɫ
	myWindow.hCursor = LoadCursor(NULL, IDC_ARROW); //�����ʽ
	myWindow.hIcon = LoadIcon(NULL, IDI_APPLICATION);//ͼ��
	myWindow.hInstance = hInstance; //���̾��
	myWindow.lpfnWndProc = WndProc; //
	myWindow.lpszClassName = CLASS_NAME;
	myWindow.style = CS_HREDRAW | CS_VREDRAW;
	myWindow.lpszMenuName = NULL;
	//ע�ᴰ��
	if (!RegisterClass(&myWindow)) {
		MessageBox(NULL, _T("����ע��ʧ�ܣ�"), _T("����"), MB_OK | MB_ICONERROR);
		return 0;
	}
	//��������
	HWND hwnd;
	hwnd = CreateWindowEx(NULL, CLASS_NAME, _T("Hello World!"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, NULL, NULL, hInstance, NULL);
	if (hwnd == NULL) {
		MessageBox(NULL, _T("create����ʧ�ܣ�"), _T("����"), MB_OK | MB_ICONERROR);
		return 0;
	}
	//��ʾ����
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	//��Ϣѭ��
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	HDC hdc;
	RECT rect;
	PAINTSTRUCT ps;
	switch (uMsg)
	{
	case WM_CREATE:
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &rect);
		DrawText(hdc, _T("Hello World!"), -1, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		EndPaint(hwnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
}