//#include <windows.h>
//#include <stdlib.h>
//#include <string.h>
//#include <tchar.h>
//
//
//
//const char g_szClassName[] = "PuyoPuyo";
//
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
//{
//	switch (msg)
//	{
//	case WM_CLOSE:
//		DestroyWindow(hwnd);
//		break;
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		break;
//	default:
//		return DefWindowProc(hwnd, msg, wParam, lParam);
//		break;
//
//		return 0;
//	}
//}
//
//
//
//
////mwindows registration and creation
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) 
//{
//	//variables 
//	WNDCLASSEX wc;
//	HWND hwnd;
//	MSG Msg;
//
//	wc.cbSize = sizeof(WNDCLASSEX);
//	wc.style = 0;
//	wc.lpfnWndProc = WndProc;
//	wc.cbWndExtra = 0;
//	wc.cbClsExtra = 0;
//	wc.hInstance = hInstance;
//	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
//	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
//	wc.lpszClassName = (LPCWSTR)g_szClassName;
//	wc.lpszMenuName = NULL;
//	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
//
//	//Exception
//	if (!RegisterClassEx(&wc))
//	{
//
//		MessageBox(NULL, (LPCWSTR)L"Window Registration Failed!", (LPCWSTR)L"Error!",
//		MB_ICONEXCLAMATION | MB_OK);
//		return 0;
//	}
//
//	//Windows Creation
//	hwnd = CreateWindowEx(
//		WS_EX_CLIENTEDGE,
//		(LPCWSTR)g_szClassName,
//		(LPCWSTR)L"PoyoPoyo",
//		WS_OVERLAPPEDWINDOW,
//		CW_USEDEFAULT, 
//		CW_USEDEFAULT,
//		240,
//		120,
//		NULL,NULL,
//		hInstance, NULL	
//		);
//
//	if (hwnd == NULL) 
//	{
//		MessageBox(NULL, (LPCWSTR)L"Window Creation Failed!", (LPCWSTR)L"Error!",
//			MB_ICONEXCLAMATION | MB_OK);
//		return 0;
//	}
//
//	ShowWindow(hwnd, nCmdShow);
//	UpdateWindow(hwnd);
//
//
//	//caught all inputs 
//	while (GetMessage(&Msg, NULL, 0, 0) > 0)
//	{
//		TranslateMessage(&Msg);
//		DispatchMessage(&Msg);
//	}
//	return Msg.wParam;
//
//};
//
