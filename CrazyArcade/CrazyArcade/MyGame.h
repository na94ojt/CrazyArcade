#pragma once
class MyGame
{
public:
	MyGame();
	virtual ~MyGame();
private:
	HBITMAP m_hBackgroundBit;
	HBITMAP m_hBackgroundFieldBit;
	HBITMAP m_hHardBlockBit;
public:
	void LoadBit(HINSTANCE hInst);
	void DrawGame(HWND hWnd, HDC hdc);
};

