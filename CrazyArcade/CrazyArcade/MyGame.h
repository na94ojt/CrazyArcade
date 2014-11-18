#pragma once
class MyGame
{
public:
	MyGame(HWND hWnd, HINSTANCE hInst);
	virtual ~MyGame();
private:
	CBitmap m_hBackgroundBit;
	CBitmap m_hBackgroundFieldBit;
	CBitmap m_hHardBlockBit;
	int m_startX_interface;
	int m_startY_interface;
	int m_startX_Game;
	int m_startY_Game;
	int m_width_interface;
	int m_height_interface;
	int m_width_Game;
	int m_height_Game;

public:
	void DrawGame(HWND hWnd, HDC hdc);
};

