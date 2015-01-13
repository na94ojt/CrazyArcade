#include "stdafx.h"
#include "MyObject.h"
#include "KDC.h"


MyObject::MyObject(MYPOSITION tilePos, MYPOSITION startPos, MYPOSITION sizePos, HBITMAP hBitmap, int Type)
: m_startPos(startPos), m_sizePos(sizePos), m_ColorKey(RGB(255, 0, 255)), m_hBitmap(hBitmap), m_MaxCount(0), m_Loop(0), m_Index(0), m_Type(Type), m_ActionIndex(0)
{
	/*
	���� ������ �����ڴ�.
	�̴ϼȶ������� ������� �ʱ�ȭ�ϰ�,
	�迭 ������� �Ʒ��� ���� 0���� �ʱ�ȭ �Ͽ���.
	*/
	SetTilePos(tilePos);
	ZeroMemory(m_ActionSIndex, sizeof(m_ActionSIndex));
	ZeroMemory(m_ActionSize, sizeof(m_ActionSize));
}
MyObject::~MyObject()
{
	/*
	�� ������� �Ҹ���
	*/
}

MYPOSITION MyObject::GetRealPos()
{
	/*
	���� �������� ��ȯ
	*/
	return m_realPos;
}
MYPOSITION MyObject::GetTilePos()
{
	/*
	Ÿ�� �������� ��ȯ
	�Ƹ� �浹�˻翡 �ַ� ������ ������ �����Ѵ�.
	�׸��� �������� ������ ��, ��ź�� �������� ��, ���� ������ �� ��� ������ ������ ������ �� ����.
	*/
	return m_tilePos;
}
MYPOSITION MyObject::GetSizePos()
{
	/*
	ũ�⸦ ��ȯ
	*/
	return m_sizePos;
}
void MyObject::SetRealPos(MYPOSITION pos)
{
	/*
	���ڷ� �޾ƿ� pos�� m_realPos�� ���������ν� ���� ��ǥ ����
	�� ���� ��ǥ�� ���� 15ĭ ���� 13ĭ�� Ÿ�Ϸ� �̷���� ũ������ �����̵� �ʿ���
	��� Ÿ�Ͽ� ������ ����� �� Ÿ�� ��ǥ ����
	*/
	m_realPos = pos;
	m_tilePos = { m_realPos.x / 15, m_realPos.y / 13 };
}
void MyObject::SetTilePos(MYPOSITION pos)
{
	/*
	���ڷ� �޾ƿ� pos�� m_tilePos�� ���������ν� Ÿ�� ��ǥ ����
	�� Ÿ�� ��ǥ�� ũ�⸦ ���ؼ� Ÿ����ǥ�� ������ǥ�� ��� �� ����
	*/
	m_tilePos = pos;
	m_realPos = { m_tilePos.x*m_sizePos.x, m_tilePos.y*m_sizePos.y };
}

int MyObject::AddAction(int aindex, int sindex, int size)
{
	if (MAX_ACTION <= aindex) return -1;

	m_ActionSIndex[aindex] = sindex;
	m_ActionSize[aindex] = size;

	return 0;
}
void MyObject::RunAction(int aindex, int loop)
{
	m_ActionIndex = aindex;
	m_Index = 0;
	m_Loop = loop;
	m_MaxCount = m_ActionSize[aindex];
}
void MyObject::NextFrame()
{

	if (-1 == m_Loop)
	{
		m_Index++;
		if (m_MaxCount <= m_Index)
		{
			m_Index = 0;
		}
	}
	else if (0 < m_Loop)
	{
		m_Index++;
		if (m_MaxCount <= m_Index)
		{
			m_Loop--;
			m_Index = 0;
		}
	}
}
void MyObject::Draw(HDC hdc) const
{
	int sx, sy;

	sx = sy = 0;
	if (0 == m_Type) //������ 
	{
		sx = m_Index*m_sizePos.x + m_ActionSIndex[m_ActionIndex] * m_sizePos.x;
	}
	else
	{
		//������ 
		sy = m_Index*m_sizePos.y + m_ActionSIndex[m_ActionIndex] * m_sizePos.y;
	}

	KDC::DrawBitMapTrans(hdc, m_startPos.x + m_realPos.x, m_startPos.y + m_realPos.y, m_sizePos.x, m_sizePos.y, m_hBitmap, sx, sy, sx + 40, sy + 40, m_ColorKey);
}

bool MyObject::NextFrameEx()
{
	if (-1 == m_Loop)
	{
		m_Index++;
		if (m_MaxCount <= m_Index)
		{
			m_Index = 0;
		}
		return true;
	}
	else if (0 < m_Loop)
	{
		m_Index++;
		if (m_MaxCount <= m_Index)
		{
			m_Loop--;
			m_Index = 0;
		}
		return true;
	}
	return false;
}