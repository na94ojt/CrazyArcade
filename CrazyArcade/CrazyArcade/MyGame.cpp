#include "stdafx.h"
#include "Resource.h"
#include "MyGame.h"

MyGame::MyGame(HWND hWnd, HINSTANCE hInst)
{
	RECT rect;																						//윈도우즈의 크기를 저장할 RECT 객체

	GetClientRect(hWnd, &rect);																		//윈도우즈의 크기를 가져와 rect에 저장

	//인터페이스 크기 초기화
	this->m_size_interface.y = rect.bottom;															
	this->m_size_interface.x = rect.bottom * 4 / 3;

	//인터페이스 그리기 시작 지점 초기화
	this->m_start_interface.x = rect.right/2 - this->m_size_interface.x/2;
	this->m_start_interface.y = 0;

	//게임화면 그리기 시작 지점 초기화
	this->m_start_Game.x = this->m_start_interface.x + (this->m_size_interface.x * 20 / 800);
	this->m_start_Game.y = this->m_start_interface.y + (this->m_size_interface.y * 40 / 600);

	//게임화면 크기 초기화
	this->m_size_Game.x = this->m_size_interface.x * 3 / 4;
	this->m_size_Game.y = this->m_size_interface.y * 13 / 15;

	//각종 비트맵 핸들 초기화
	this->m_hBackgroundBit.LoadBitmapW(IDB_BACKGROUND);
	this->m_hBackgroundFieldBit.LoadBitmapW(IDB_BACKGROUNDFIELD);
	this->m_hHardBlockBit.LoadBitmapW(IDB_HARDBLOCK);
}


MyGame::~MyGame()
{
}

void MyGame::DrawGame(HWND hWnd, HDC hdc)
{
	HDC memDC = CreateCompatibleDC(hdc);							//메모리 DC
	HBITMAP pOld;													//이전에 들어 있던 object를 저장할 객체
	
	//인터페이스 그림
	pOld = (HBITMAP)SelectObject(memDC, this->m_hBackgroundBit);
	TransparentBlt(hdc, this->m_start_interface.x, this->m_start_interface.y, this->m_size_interface.x, this->m_size_interface.y, memDC, 0, 0, 800, 600, RGB(255,0,255));

	//게임 화면 필드 그림
	SelectObject(memDC, this->m_hBackgroundFieldBit);
	TransparentBlt(hdc, this->m_start_Game.x, this->m_start_Game.y, this->m_size_Game.x, this->m_size_Game.y, memDC, 0, 0, 600, 520, RGB(255, 0, 255));


	//그리기 끝냄
	SelectObject(memDC, pOld);
	DeleteDC(memDC);
}

void MyGame::KeyDown(int key)
{
	this->m_keyboard.KeyDown(key);
}

void MyGame::KeyUp(int key)
{
	this->m_keyboard.KeyUp(key);
}

void MyGame::CheckKey()
{
	if (0 != this->m_keyboard.FindKey(VK_LEFT))
	{
		
	}
	if (0 != this->m_keyboard.FindKey(VK_RIGHT))
	{

	}
	if (0 != this->m_keyboard.FindKey(VK_UP))
	{

	}
	if (0 != this->m_keyboard.FindKey(VK_DOWN))
	{

	}
}