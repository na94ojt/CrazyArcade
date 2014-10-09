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
}


void MyGame::DrawGame(HWND hWnd, HDC hdc)
{
	RECT rect;
	GetClientRect(hWnd, &rect);
	HDC memDC = CreateCompatibleDC(hdc);							//핸들 생성

	HBITMAP pOld = (HBITMAP)SelectObject(memDC, this->m_hBackgroundBit);				//원래 기존 상태 저장하고 memDC핸들에 bitmapObject 적용

	TransparentBlt(hdc, rect.left,rect.top, rect.right, rect.bottom, memDC, 0, 0, 800, 600, RGB(255,0,255));				//그림그림

	SelectObject(memDC, pOld);										//원래의 Object로 다시 선택
	DeleteDC(memDC);												//memDC 삭제
}
