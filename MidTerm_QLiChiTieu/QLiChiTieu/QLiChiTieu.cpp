// QLiChiTieu.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "QLiChiTieu.h"
#include "QuanLi.h"
// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name
GdiplusStartupInput gdiplusStarupInput;
ULONG_PTR			gdiplusToken;


// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;
	CoInitialize(NULL);

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_QLICHITIEU, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_QLICHITIEU));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	CoUninitialize();
	return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_QLICHITIEU);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_ICON1));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, L"Quản Lí Chi Tiêu", WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, 800, 600, NULL, NULL, hInstance, NULL);



   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}


//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
HWND hMoTa, hSoTien, btnThem, btnDS, btnTat, hComboBox, hLV;
LoaiCT loai[6] = { AnUong, 
DiChuyen,
NhaCua,
XeCo,
NhuYeuPham,
DichVu };
ThongTin thongtin;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	
	LOGFONT lf;
	GetObject(GetStockObject(DEFAULT_GUI_FONT), sizeof(LOGFONT), &lf);
	HFONT hFont = CreateFont(lf.lfHeight, lf.lfWidth,
		lf.lfEscapement, lf.lfOrientation, lf.lfWeight,
		lf.lfItalic, lf.lfUnderline, lf.lfStrikeOut, lf.lfCharSet,
		lf.lfOutPrecision, lf.lfClipPrecision, lf.lfQuality,
		lf.lfPitchAndFamily, lf.lfFaceName);
	switch (message)
	{
	case WM_CREATE:
	{
					  GdiplusStartup(&gdiplusToken, &gdiplusStarupInput, NULL);
					  HWND text;
					  text = CreateWindow(WC_STATIC, L"Thêm Chi Tiêu", WS_CHILD | WS_VISIBLE | SS_CENTER, 10, 20, 280, 20, hWnd, NULL, hInst, NULL);
					  SendMessage(text, WM_SETFONT, (WPARAM)hFont, TRUE);
					  text = CreateWindow(WC_STATIC, L"Loại Chi Tiêu:", WS_CHILD | WS_VISIBLE | SS_LEFT , 20, 50, 100, 20, hWnd, NULL, hInst, NULL);
					  SendMessage(text, WM_SETFONT, (WPARAM)hFont, TRUE);
					  text = CreateWindow(WC_STATIC, L"Nội Dung:", WS_CHILD | WS_VISIBLE | SS_LEFT, 20, 100, 100, 20, hWnd, NULL, hInst, NULL);
					  SendMessage(text, WM_SETFONT, (WPARAM)hFont, TRUE);
					  text = CreateWindow(WC_STATIC, L"Số Tiền:", WS_CHILD | WS_VISIBLE | SS_LEFT, 20, 280, 100, 20, hWnd, NULL, hInst, NULL);
					  SendMessage(text, WM_SETFONT, (WPARAM)hFont, TRUE);
					
					  text = CreateWindow(WC_STATIC, L"Biểu đồ thống kê:", WS_CHILD | WS_VISIBLE | SS_LEFT, 300, 380, 150, 20, hWnd, NULL, hInst, NULL);
					  SendMessage(text, WM_SETFONT, (WPARAM)hFont, TRUE);
					  
					  text = CreateWindow(WC_STATIC, L"Ăn Uống", WS_CHILD | WS_VISIBLE | SS_LEFT, 320, 450, 150, 20, hWnd, NULL, hInst, NULL);
					  SendMessage(text, WM_SETFONT, (WPARAM)hFont, TRUE);
					  text = CreateWindow(WC_STATIC, L"Di Chuyển", WS_CHILD | WS_VISIBLE | SS_LEFT, 470, 450, 150, 20, hWnd, NULL, hInst, NULL);
					  SendMessage(text, WM_SETFONT, (WPARAM)hFont, TRUE);
					  text = CreateWindow(WC_STATIC, L"Nhà Cửa", WS_CHILD | WS_VISIBLE | SS_LEFT, 620, 450, 150, 20, hWnd, NULL, hInst, NULL);
					  SendMessage(text, WM_SETFONT, (WPARAM)hFont, TRUE);
					  text = CreateWindow(WC_STATIC, L"Xe Cộ", WS_CHILD | WS_VISIBLE | SS_LEFT, 320, 500, 150, 20, hWnd, NULL, hInst, NULL);
					  SendMessage(text, WM_SETFONT, (WPARAM)hFont, TRUE);
					  text = CreateWindow(WC_STATIC, L"Nhu Yếu Phẩm", WS_CHILD | WS_VISIBLE | SS_LEFT, 470, 500, 150, 20, hWnd, NULL, hInst, NULL);
					  SendMessage(text, WM_SETFONT, (WPARAM)hFont, TRUE);
					  text = CreateWindow(WC_STATIC, L"Dịch Vụ", WS_CHILD | WS_VISIBLE | SS_LEFT, 620, 500, 150, 20, hWnd, NULL, hInst, NULL);
					  SendMessage(text, WM_SETFONT, (WPARAM)hFont, TRUE);
					  
					  //khung edit nội dung
					  hMoTa = CreateWindow(WC_EDIT, L"", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL, 20, 120, 250, 150, hWnd, NULL, hInst, NULL);
					  SendMessage(hMoTa, WM_SETFONT, (WPARAM)hFont, TRUE);

					  //khung số tiền
					  hSoTien = CreateWindow(WC_EDIT, L"", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_NUMBER, 20, 300, 250, 20, hWnd, NULL, hInst, NULL);
					  SendMessage(hSoTien, WM_SETFONT, (WPARAM)hFont, TRUE);

					  //combobox loại chi tiêu
					  hComboBox = CreateWindow(WC_COMBOBOX, TEXT(""),
						  CBS_DROPDOWN | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE,
						  20, 70, 250, 150, hWnd, NULL, hInst,
						  NULL);
					  SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)_T("Ăn Uống"));				  
					  SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)_T("Di Chuyển"));
					  SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)_T("Nhà Cửa"));
					  SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)_T("Xe Cộ"));
					  SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)_T("Nhu Yếu Phẩm"));
					  SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)_T("Dịch Vụ"));
					  SendMessage(hComboBox, WM_SETFONT, (WPARAM)hFont, TRUE);

					  //button thêm, xem danh sách, thoát
					  btnThem = CreateWindow(WC_BUTTON, L"THÊM", WS_CHILD | WS_VISIBLE, 20, 330, 250, 40, hWnd, (HMENU)ID_BTNThem, hInst, NULL);
					  SendMessage(btnThem, WM_SETFONT, (WPARAM)hFont, TRUE);

					  btnDS = CreateWindow(WC_BUTTON, L"CẬP NHẬT DANH SÁCH", WS_CHILD | WS_VISIBLE, 20, 380, 250, 40, hWnd, (HMENU)ID_BTNXemDS, hInst, NULL);
					  SendMessage(btnDS, WM_SETFONT, (WPARAM)hFont, TRUE);

					  btnTat = CreateWindow(WC_BUTTON, L"THOÁT", WS_CHILD | WS_VISIBLE, 100, 450, 100, 40, hWnd, (HMENU)ID_BTNTat, hInst, NULL);
					  SendMessage(btnTat, WM_SETFONT, (WPARAM)hFont, TRUE);

					  //List view
					  hLV = CreateWindow(WC_LISTVIEW, L"", WS_CHILD | WS_VISIBLE | WS_BORDER | LVS_REPORT | WS_VSCROLL, 300, 10, 460, 350, hWnd, NULL, hInst, NULL);
					  LVCOLUMNW lvCol;
					  lvCol.mask = LVCF_FMT | LVCF_TEXT | LVCF_WIDTH;
					  lvCol.fmt = LVCFMT_LEFT;
					  lvCol.cx = 110;
					  lvCol.pszText = L"Loại chi tiêu";
					  ListView_InsertColumn(hLV, 0, &lvCol);

					  lvCol.cx = 250;
					  lvCol.pszText = L"Nội dung";
					  ListView_InsertColumn(hLV, 1, &lvCol);

					  lvCol.cx = 100;
					  lvCol.pszText = L"Số tiền (VND)";
					  ListView_InsertColumn(hLV, 2, &lvCol);
					  SendMessage(hLV, WM_SETFONT, (WPARAM)hFont, TRUE);

					  ChiTieu.DocFile("DanhSachChiTieu.txt");
					  ChiTieu.Xem(hLV);
					  InvalidateRect(hWnd, NULL, TRUE);
					  break;
	}
	case WM_CTLCOLORSTATIC:
		SetBkMode((HDC)wParam, TRANSPARENT);
		return (LRESULT)GetStockObject(NULL_BRUSH);
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);

		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			ChiTieu.LuuFile("DanhSachChiTieu.txt");
			PostQuitMessage(0);
			break;
		case ID_BTNThem:
		{
						   int i = SendMessage(hComboBox, CB_GETCURSEL, 0, 0);

						   GetWindowText(hMoTa, thongtin.MoTa, 300);

						   wchar_t tmp[20]; //biến tạm lưu số tiền
						   GetWindowText(hSoTien, tmp, 20);
						   if (!lstrcmp(L"", tmp))
						   {
							   MessageBox(0, L"Error: vui lòng nhập số tiền.", 0, 0);
							   break;
						   }
						   thongtin.SoTien = _wtol(tmp);

						   ChiTieu.Them(loai[i], thongtin);
						   ClearBox(hMoTa, hSoTien);
						   break;
		}
		case ID_BTNXemDS:
		{
							ChiTieu.Xem(hLV);
							InvalidateRect(hWnd, NULL, TRUE);
							break;
		}
		case ID_BTNTat:
			ChiTieu.LuuFile("DanhSachChiTieu.txt");
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}

		
	
		break;
	case WM_PAINT:
	{
					 hdc = BeginPaint(hWnd, &ps);
					 SelectObject(hdc, GetStockObject(DC_PEN));
					 SetDCPenColor(hdc, RGB(204, 207, 212));
					 Rectangle(hdc, 10, 10, 280, 525);
					 Graphics* graphic = new Graphics(hdc);
					 ChiTieu.VeBieuDo(graphic);

					 delete graphic;
					 EndPaint(hWnd, &ps);
					 break;
	}
	case WM_DESTROY:
		ChiTieu.LuuFile("DanhSachChiTieu.txt");
		GdiplusShutdown(gdiplusToken);
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
