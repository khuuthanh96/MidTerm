#pragma once
#include <CommCtrl.h>

#include <fcntl.h> //_O_WTEXT
#include <io.h>    //_setmode()
#include <locale>
#include <codecvt> //possible C++11?

#include <fstream>
#include <ObjIdl.h>
#include <gdiplus.h>
#include <windowsx.h>
#include <vector>
#define MAX_LOADSTRING 100
#pragma comment (lib, "Gdiplus.lib")
#pragma comment(lib, "ComCtl32.lib")

using namespace Gdiplus;
using namespace std;

enum LoaiCT{
	AnUong,
	DiChuyen,
	NhaCua,
	XeCo,
	NhuYeuPham,
	DichVu
};

typedef struct ThongTin{
	wchar_t MoTa[300];
	long SoTien;
};

class CQuanLi
{
	vector<ThongTin> DsAnUong, 
	DsDiChuyen, 
	DsNhaCua, 
	DsXeCo, 
	DsNhuYeuPham, 
	DsDichVu;
public:
	CQuanLi();
	~CQuanLi();
	void Them(LoaiCT, ThongTin);
	void Xem(HWND);
	void LuuFile(char*);
	void DocFile(char*);
	void VeBieuDo(Graphics*);
};

