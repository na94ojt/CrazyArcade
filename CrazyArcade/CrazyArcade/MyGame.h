#pragma once
class MyGame
{
public:
	MyGame();
	virtual ~MyGame();
private:
	HBITMAP m_hBackgroundBit;
public:
	void LoadBit(HINSTANCE hInst);
	void DrawGame(HWND hWnd, HDC hdc);
};

