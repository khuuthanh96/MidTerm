#include "stdafx.h"
#include "QuanLi.h"


CQuanLi::CQuanLi()
{
}


CQuanLi::~CQuanLi()
{
	DsAnUong.clear();
	DsDiChuyen.clear();
	DsDichVu.clear();
	DsXeCo.clear();
	DsNhuYeuPham.clear();
	DsNhaCua.clear();
}

void CQuanLi::Them(LoaiCT loai, ThongTin tt)
{
	switch (loai)
	{
	case AnUong:
		DsAnUong.push_back(tt);
		break;
	case DiChuyen:
		DsDiChuyen.push_back(tt);
		break;
	case NhaCua:
		DsNhaCua.push_back(tt);
		break;
	case XeCo:
		DsXeCo.push_back(tt);
		break;
	case NhuYeuPham:
		DsNhuYeuPham.push_back(tt);
		break;
	case DichVu:
		DsDichVu.push_back(tt);
		break;
	default:
		break;
	}
}

void CQuanLi::Xem(HWND ListView)
{
	ListView_DeleteAllItems(ListView);
	LV_ITEM LvItem;
	LvItem.mask = LVIF_TEXT;
	wchar_t tmp[20]; //biến tạm dùng để lưu số tiền và nạp vào listview
	int dem = 0;

	for (int i = 0; i < this->DsAnUong.size(); i++)
	{
		LvItem.iItem = dem;
		LvItem.pszText = L"Ăn Uống";
		LvItem.iSubItem = 0;

		ListView_InsertItem(ListView, &LvItem);

		ListView_SetItemText(ListView, dem, 1, DsAnUong[i].MoTa);

		wsprintf(tmp, L"%d", DsAnUong[i].SoTien);
		ListView_SetItemText(ListView, dem, 2, tmp);
		dem++;
	}

	for (int i = 0; i < this->DsDiChuyen.size(); i++)
	{
		LvItem.iItem = dem;
		LvItem.pszText = L"Di Chuyển";
		LvItem.iSubItem = 0;

		ListView_InsertItem(ListView, &LvItem);

		ListView_SetItemText(ListView, dem, 1, DsDiChuyen[i].MoTa);

		wsprintf(tmp, L"%d", DsDiChuyen[i].SoTien);
		ListView_SetItemText(ListView, dem, 2, tmp);
		dem++;
	}

	for (int i = 0; i < this->DsNhaCua.size(); i++)
	{
		LvItem.iItem = dem;
		LvItem.pszText = L"Nhà Cửa";
		LvItem.iSubItem = 0;

		ListView_InsertItem(ListView, &LvItem);

		ListView_SetItemText(ListView, dem, 1, DsNhaCua[i].MoTa);

		wsprintf(tmp, L"%d", DsNhaCua[i].SoTien);
		ListView_SetItemText(ListView, dem, 2, tmp);
		dem++;
	}

	for (int i = 0; i < this->DsXeCo.size(); i++)
	{
		LvItem.iItem = dem;
		LvItem.pszText = L"Xe Cộ";
		LvItem.iSubItem = 0;

		ListView_InsertItem(ListView, &LvItem);

		ListView_SetItemText(ListView, dem, 1, DsXeCo[i].MoTa);

		wsprintf(tmp, L"%d", DsXeCo[i].SoTien);
		ListView_SetItemText(ListView, dem, 2, tmp);
		dem++;
	}

	for (int i = 0; i < this->DsNhuYeuPham.size(); i++)
	{
		LvItem.iItem = dem;
		LvItem.pszText = L"Nhu Yếu Phẩm";
		LvItem.iSubItem = 0;

		ListView_InsertItem(ListView, &LvItem);

		ListView_SetItemText(ListView, dem, 1, DsNhuYeuPham[i].MoTa);

		wsprintf(tmp, L"%d", DsNhuYeuPham[i].SoTien);
		ListView_SetItemText(ListView, dem, 2, tmp);
		dem++;
	}

	for (int i = 0; i < this->DsDichVu.size(); i++)
	{
		LvItem.iItem = dem;
		LvItem.pszText = L"Dịch Vụ";
		LvItem.iSubItem = 0;

		ListView_InsertItem(ListView, &LvItem);

		ListView_SetItemText(ListView, dem, 1, DsDichVu[i].MoTa);

		wsprintf(tmp, L"%d", DsDichVu[i].SoTien);
		ListView_SetItemText(ListView, dem, 2, tmp);
		dem++;
	}
}

void CQuanLi::LuuFile(char* tenFile)
{
	std::locale loc(std::locale(), new std::codecvt_utf8<wchar_t>);
	wofstream oFile(tenFile);
	if (!oFile)
		return;

	oFile.imbue(loc);

	oFile << DsAnUong.size() << endl;
	oFile << DsDiChuyen.size() << endl;
	oFile << DsNhaCua.size() << endl;
	oFile << DsXeCo.size() << endl;
	oFile << DsNhuYeuPham.size() << endl;
	oFile << DsDichVu.size() << endl;

	for (int  i = 0; i < DsAnUong.size(); i++)
		oFile << DsAnUong[i].MoTa << endl << DsAnUong[i].SoTien << endl;

	for (int i = 0; i < DsDiChuyen.size(); i++)
		oFile << DsDiChuyen[i].MoTa << endl << DsDiChuyen[i].SoTien << endl;

	for (int i = 0; i < DsNhaCua.size(); i++)
		oFile << DsNhaCua[i].MoTa << endl << DsNhaCua[i].SoTien << endl;

	for (int i = 0; i < DsXeCo.size(); i++)
		oFile << DsXeCo[i].MoTa << endl << DsXeCo[i].SoTien << endl;

	for (int i = 0; i < DsNhuYeuPham.size(); i++)
		oFile << DsNhuYeuPham[i].MoTa << endl << DsNhuYeuPham[i].SoTien << endl;

	for (int i = 0; i < DsDichVu.size(); i++)
		oFile << DsDichVu[i].MoTa << endl << DsDichVu[i].SoTien << endl;

	oFile.close();
}

void CQuanLi::DocFile(char* tenFile)
{
	std::locale loc(std::locale(), new std::codecvt_utf8<wchar_t>);
	wifstream iFile(tenFile);
	if (!iFile)
		return;

	iFile.imbue(loc);

	int n[6];
	ThongTin tt;
	for (int i = 0; i < 6; i++)
	{
		iFile >> n[i];
		iFile.get();
	}
	
	for (int i = 0; i < n[0]; i++)
	{
		iFile.getline(tt.MoTa, 300);
		iFile >> tt.SoTien;
		iFile.get();
		DsAnUong.push_back(tt);
	}
	for (int i = 0; i < n[1]; i++)
	{
		iFile.getline(tt.MoTa, 300);
		iFile >> tt.SoTien;
		iFile.get();
		DsDiChuyen.push_back(tt);
	}
	for (int i = 0; i < n[2]; i++)
	{
		iFile.getline(tt.MoTa, 300);
		iFile >> tt.SoTien;
		iFile.get();
		DsNhaCua.push_back(tt);
	}
	for (int i = 0; i < n[3]; i++)
	{
		iFile.getline(tt.MoTa, 300);
		iFile >> tt.SoTien;
		iFile.get();
		DsXeCo.push_back(tt);
	}
	for (int i = 0; i < n[4]; i++)
	{
		iFile.getline(tt.MoTa, 300);
		iFile >> tt.SoTien;
		iFile.get();
		DsNhuYeuPham.push_back(tt);
	}
	for (int i = 0; i < n[5]; i++)
	{
		iFile.getline(tt.MoTa, 300);
		iFile >> tt.SoTien;
		iFile.get();
		DsDichVu.push_back(tt);
	}

	iFile.close();
}

void CQuanLi::VeBieuDo(Graphics* graphic)
{
	SolidBrush* br = new SolidBrush(Color::DimGray);
	graphic->FillRectangle(br, 300, 400, 460, 30);
	
	long tong = 0;
	long tongTungLoai[6] = {0};
	for (int i = 0; i < DsAnUong.size(); i++)
		tongTungLoai[0] += DsAnUong[i].SoTien;

	for (int i = 0; i < DsDiChuyen.size(); i++)
		tongTungLoai[1] += DsDiChuyen[i].SoTien;

	for (int i = 0; i < DsNhaCua.size(); i++)
		tongTungLoai[2] += DsNhaCua[i].SoTien;

	for (int i = 0; i < DsXeCo.size(); i++)
		tongTungLoai[3] += DsXeCo[i].SoTien;

	for (int i = 0; i < DsNhuYeuPham.size(); i++)
		tongTungLoai[4] += DsNhuYeuPham[i].SoTien;

	for (int i = 0; i < DsDichVu.size(); i++)
		tongTungLoai[5] += DsDichVu[i].SoTien;

	//cong tong
	for (int i = 0; i < 6; i++)
	{
		tong += tongTungLoai[i];
	}

	if (tong != 0)
	{
		int x = 300;
		int lamtron = round((((float)tongTungLoai[0] * 100 / tong) * 460) / 100);
		br->SetColor(Color::Chocolate);
		graphic->FillRectangle(br, x, 400, lamtron, 30);
		graphic->FillRectangle(br, 300, 450, 15, 15);

		x += lamtron;
		lamtron = round((((float)tongTungLoai[1] * 100 / tong) * 460) / 100);
		br->SetColor(Color::BurlyWood);
		graphic->FillRectangle(br, x, 400, lamtron, 30);
		graphic->FillRectangle(br, 450, 450, 15, 15);

		x += lamtron;
		lamtron = round((((float)tongTungLoai[2] * 100 / tong) * 460) / 100);
		br->SetColor(Color::BlueViolet);
		graphic->FillRectangle(br, x, 400, lamtron, 30);
		graphic->FillRectangle(br, 600, 450, 15, 15);

		x += lamtron;
		lamtron = round((((float)tongTungLoai[3] * 100 / tong) * 460) / 100);
		br->SetColor(Color::Aquamarine);
		graphic->FillRectangle(br, x, 400, (tongTungLoai[3] * 100 / tong) * 460 / 100, 30);
		graphic->FillRectangle(br, 300, 500, 15, 15);

		x += lamtron;
		lamtron = round((((float)tongTungLoai[4] * 100 / tong) * 460) / 100);
		br->SetColor(Color::Chartreuse);
		graphic->FillRectangle(br, x, 400, lamtron, 30);
		graphic->FillRectangle(br, 450, 500, 15, 15);

		x += lamtron;
		lamtron = round((((float)tongTungLoai[5] * 100 / tong) * 460) / 100);
		br->SetColor(Color::Gold);
		graphic->FillRectangle(br, x, 400, lamtron, 30);
		graphic->FillRectangle(br, 600, 500, 15, 15);
	}
	delete br;
}