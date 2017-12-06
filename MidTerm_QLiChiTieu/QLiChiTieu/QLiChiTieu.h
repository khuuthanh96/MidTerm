#pragma once

#include "resource.h"
#include "QuanLi.h"



CQuanLi ChiTieu;

void ClearBox(HWND hMoTa, HWND hSoTien)
{
	SetWindowText(hMoTa, L"");
	SetWindowText(hSoTien, L"");
}