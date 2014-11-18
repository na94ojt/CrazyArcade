#include "stdafx.h"
#include "MyGame.h"
#include "Resource.h"


MyGame::MyGame(HWND hWnd, HINSTANCE hInst)
: m_startX_interface(0), m_startY_interface(0), m_startX_Game(0), m_startY_Game(0), m_width_interface(0), m_height_interface(0), m_width_Game(0), m_height_Game(0)
{
	RECT rect;
	int startx;
	int starty;

	GetClientRect(hWnd, &rect);	

	this->m_height_interface = rect.bottom;
	this->m_width_interface = rect.bottom * 4 / 3;

	this->m_startX_interface = rect.right/2 - this->m_width_interface/2;
	this->m_startY_interface = 0;
	
	this->m_startX_Game = this->m_startX_interface + (this->m_width_interface * 20 / 800);
	this->m_startY_Game = this->m_startY_interface + (this->m_height_interface * 40 / 600);

	this->m_width_Game = this->m_width_interface * 3 / 4;
	this->m_height_Game = this->m_height_interface * 13 / 15;

	this->m_hBackgroundBit.LoadBitmapW(IDB_BACKGROUND);
	this->m_hBackgroundFieldBit.LoadBitmapW(IDB_BACKGROUNDFIELD);
	this->m_hHardBlockBit.LoadBitmapW(IDB_HARDBLOCK);
}


MyGame::~MyGame()
{
}

void MyGame::DrawGame(HWND hWnd, HDC hdc)
{
	/*
	HDC memDC = CreateCompatibleDC(hdc);							//핸들 생성

	HBITMAP pOld = (HBITMAP)SelectObject(memDC, this->m_hBackgroundBit);				//원래 기존 상태 저장하고 memDC핸들에 bitmapObject 적용
	TransparentBlt(hdc, rect.left, rect.top, rect.right, rect.bottom, memDC, 0, 0, 800, 600, RGB(255, 0, 255));				//그림그림
	
	pOld = (HBITMAP)SelectObject(memDC, this->m_hBackgroundFieldBit);
	TransparentBlt(hdc, startx, starty, endx, endy, memDC, 0, 0, 600, 520, RGB(255, 0, 255));

	pOld = (HBITMAP)SelectObject(memDC, this->m_hHardBlockBit);
	TransparentBlt(hdc, startx, starty, startx + width, starty + height, memDC, 0, 0, 40, 40, RGB(255, 0, 255));
	
	SelectObject(memDC, pOld);										//원래의 Object로 다시 선택
	DeleteDC(memDC);												//memDC 삭제
	*/
	RECT rect;
	HDC memDC = CreateCompatibleDC(hdc);
	HBITMAP pOld = (HBITMAP)SelectObject(memDC, this->m_hBackgroundBit);

	TransparentBlt(hdc, this->m_startX_interface, this->m_startY_interface, this->m_width_interface, this->m_height_interface, memDC, 0, 0, 800, 600, RGB(255,0,255));

	pOld = (HBITMAP)SelectObject(memDC, this->m_hBackgroundFieldBit);
	TransparentBlt(hdc, this->m_startX_Game, this->m_startY_Game, this->m_width_Game, this->m_height_Game, memDC, 0, 0, 600, 520, RGB(255, 0, 255));

	SelectObject(memDC, pOld);
	DeleteDC(memDC);
	
	
}