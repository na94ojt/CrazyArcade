#pragma once
#include "MyMap.h"
#include "MyGameGlobal.h"
#include "SolidBlock.h"
#include "ItemBlock.h"

class GameHandler
{
private:
	HDC m_hdc;								//dc �ڵ�
	HINSTANCE m_hInst;						//instance �ڵ�
	MyMap m_map;							//��

	vector <SolidBlock> m_solidblocks;		//Solidblock ��ü ���� ����
	vector <ItemBlock> m_itemblocks;		//ItemBlock ��ü ���� ����

	//ũ�� �� ��ġ ������
	MYPOSITION m_size_Screen;
	MYPOSITION m_size_interface;
	MYPOSITION m_start_interface;
	MYPOSITION m_size_Game;
	MYPOSITION m_start_Game;
	MYPOSITION m_size_Object;

	//��Ʈ�� �ڵ��
	HBITMAP m_hBackground;
	HBITMAP m_hinterface;
	HBITMAP m_hMap;

public:
	GameHandler();
	virtual ~GameHandler();
	void InitGame(HDC hdc, HINSTANCE hInst, RECT rect);
	void Paint();
};