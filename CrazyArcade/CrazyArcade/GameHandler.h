#pragma once
#include "MyMap.h"
#include "MyGameGlobal.h"
#include "SolidBlock.h"
#include "ItemBlock.h"

class GameHandler
{
private:
	HDC m_hdc;								//dc 핸들
	HINSTANCE m_hInst;						//instance 핸들
	MyMap m_map;							//맵

	vector <SolidBlock> m_solidblocks;		//Solidblock 객체 저장 벡터
	vector <ItemBlock> m_itemblocks;		//ItemBlock 객체 저장 벡터

	//크기 및 위치 정보들
	MYPOSITION m_size_Screen;
	MYPOSITION m_size_interface;
	MYPOSITION m_start_interface;
	MYPOSITION m_size_Game;
	MYPOSITION m_start_Game;
	MYPOSITION m_size_Object;

	//비트맵 핸들들
	HBITMAP m_hBackground;
	HBITMAP m_hinterface;
	HBITMAP m_hMap;

public:
	GameHandler();
	virtual ~GameHandler();
	void InitGame(HDC hdc, HINSTANCE hInst, RECT rect);
	void Paint();
};