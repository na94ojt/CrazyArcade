#include "stdafx.h"
#include "MyGame.h"
#include "Resource.h"


MyGame::MyGame()
{
}


MyGame::~MyGame()
{
}


void MyGame::LoadBit(HINSTANCE hInst)
{
	this->m_hBackgroundBit = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BACKGROUND));
	this->m_hBackgroundFieldBit = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BACKGROUNDFIELD));
	this->m_hHardBlockBit = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_HARDBLOCK));
}


void MyGame::DrawGame(HWND hWnd, HDC hdc)
{
	RECT rect;
	int startx, starty, endx, endy, width, height;
	GetClientRect(hWnd, &rect);

	startx = rect.right * 20 / 800;
	starty = rect.bottom * 40 / 600;
	endx = rect.right * 620 / 800;
	endy = rect.bottom * 560 / 600;

	width = (endx - startx) / 15;
	height = (endy - starty) / 13;

	HDC memDC = CreateCompatibleDC(hdc);							//핸들 생성

	HBITMAP pOld = (HBITMAP)SelectObject(memDC, this->m_hBackgroundBit);				//원래 기존 상태 저장하고 memDC핸들에 bitmapObject 적용
	TransparentBlt(hdc, rect.left, rect.top, rect.right, rect.bottom, memDC, 0, 0, 800, 600, RGB(255, 0, 255));				//그림그림
	
	pOld = (HBITMAP)SelectObject(memDC, this->m_hBackgroundFieldBit);
	TransparentBlt(hdc, startx, starty, endx, endy, memDC, 0, 0, 600, 520, RGB(255, 0, 255));

	pOld = (HBITMAP)SelectObject(memDC, this->m_hHardBlockBit);
	TransparentBlt(hdc, startx, starty, startx + width, starty + height, memDC, 0, 0, 40, 40, RGB(255, 0, 255));
	
	SelectObject(memDC, pOld);										//원래의 Object로 다시 선택
	DeleteDC(memDC);												//memDC 삭제
}