#include "stdafx.h"
#include "GameHandler.h"
#include "resource.h"
#include "KDC.h"


GameHandler::GameHandler()
{
}


GameHandler::~GameHandler()
{
}

void GameHandler::InitGame(HDC hdc, HINSTANCE hInst, RECT rect)
{
	this->m_hdc = hdc;
	this->m_hInst = hInst;

	this->m_size_Screen.x = rect.right;
	this->m_size_Screen.y = rect.bottom;

	//�������̽� ũ�� �ʱ�ȭ
	this->m_size_interface.y = rect.bottom;
	this->m_size_interface.x = rect.bottom * 4 / 3;

	//�������̽� �׸��� ���� ���� �ʱ�ȭ
	this->m_start_interface.x = rect.right / 2 - this->m_size_interface.x / 2;
	this->m_start_interface.y = 0;

	//����ȭ�� �׸��� ���� ���� �ʱ�ȭ
	this->m_start_Game.x = this->m_start_interface.x + (this->m_size_interface.x * 20 / 800);
	this->m_start_Game.y = this->m_start_interface.y + (this->m_size_interface.y * 40 / 600);

	//����ȭ�� ũ�� �ʱ�ȭ
	this->m_size_Game.x = this->m_size_interface.x * 3 / 4;
	this->m_size_Game.y = this->m_size_interface.y * 13 / 15;

	//������Ʈ ũ�� �ʱ�ȭ
	this->m_size_Object.x = this->m_size_Game.x / 15;
	this->m_size_Object.y = this->m_size_Game.y / 13;

	//��Ʈ�� �ڵ� �ʱ�ȭ
	this->m_hBackground = KDC::OpenImageFromRC(this->m_hInst, IDB_BACKGROUND);
	this->m_hinterface = KDC::OpenImageFromRC(this->m_hInst, IDB_INTERFACE);
	this->m_hMap = KDC::OpenImageFromRC(this->m_hInst, IDB_MAP);
	HBITMAP hSolidBlock = KDC::OpenImageFromRC(this->m_hInst, IDB_SOLIDBLOCK);
	HBITMAP hItemBlock = KDC::OpenImageFromRC(this->m_hInst, IDB_ITEMBLOCK);

	//�ʿ� �ִ� ������Ʈ ����(�ָ�����, �����ۺ��, ������(?))
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (SOLIDBLOCK == this->m_map.GetMapInfo({ j, i }))
			{
				SolidBlock object({ j, i }, this->m_start_Game, this->m_size_Object, hSolidBlock);
				this->m_solidblocks.push_back(object);
			}
			else if (ITEMBLOCK == this->m_map.GetMapInfo({ j, i }))
			{
				ItemBlock object({ j, i }, this->m_start_Game, this->m_size_Object, hItemBlock);
				this->m_itemblocks.push_back(object);
			}
		}
	}
}

void GameHandler::Paint()
{
	//���̶� �������̽� �׸���
	KDC::DrawBitMap(this->m_hdc, 0, 0, this->m_size_Screen.x, this->m_size_Screen.y, this->m_hBackground, 0, 0, 40, 40);
	KDC::DrawBitMapTrans(this->m_hdc, this->m_start_interface.x, this->m_start_interface.y, this->m_size_interface.x, this->m_size_interface.y, this->m_hinterface, 0, 0, 800, 600, RGB(255, 0, 255));
	KDC::DrawBitMapTrans(this->m_hdc, this->m_start_Game.x, this->m_start_Game.y, this->m_size_Game.x, this->m_size_Game.y, this->m_hMap, 0, 0, 600, 520, RGB(255,0,255));

	//������Ʈ�� Draw
	for (int i = 0; i < this->m_solidblocks.size(); i++)	//SolidBlock �׸�
	{
		this->m_solidblocks[i].Draw(this->m_hdc);
	}
	for (int i = 0; i < this->m_itemblocks.size(); i++)		//ItemBlock �׸�
	{
		this->m_itemblocks[i].Draw(this->m_hdc);
	}	
}