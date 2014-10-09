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
	HDC memDC = CreateCompatibleDC(hdc);							//�ڵ� ����

	HBITMAP pOld = (HBITMAP)SelectObject(memDC, this->m_hBackgroundBit);				//���� ���� ���� �����ϰ� memDC�ڵ鿡 bitmapObject ����

	TransparentBlt(hdc, rect.left,rect.top, rect.right, rect.bottom, memDC, 0, 0, 800, 600, RGB(255,0,255));				//�׸��׸�

	SelectObject(memDC, pOld);										//������ Object�� �ٽ� ����
	DeleteDC(memDC);												//memDC ����
}
