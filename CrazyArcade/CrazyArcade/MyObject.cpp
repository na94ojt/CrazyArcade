#include "stdafx.h"
#include "MyObject.h"
#include "KDC.h"


MyObject::MyObject(MYPOSITION tilePos, MYPOSITION startPos, MYPOSITION sizePos, HBITMAP hBitmap, int Type)
: m_startPos(startPos), m_sizePos(sizePos), m_ColorKey(RGB(255, 0, 255)), m_hBitmap(hBitmap), m_MaxCount(0), m_Loop(0), m_Index(0), m_Type(Type), m_ActionIndex(0)
{
	/*
	나는 떠돌이 생성자다.
	이니셜라이저로 멤버들을 초기화하고,
	배열 멤버들은 아래와 같이 0으로 초기화 하였다.
	*/
	SetTilePos(tilePos);
	ZeroMemory(m_ActionSIndex, sizeof(m_ActionSIndex));
	ZeroMemory(m_ActionSize, sizeof(m_ActionSize));
}
MyObject::~MyObject()
{
	/*
	별 쓸모없는 소멸자
	*/
}

MYPOSITION MyObject::GetRealPos()
{
	/*
	리얼 포지션을 반환
	*/
	return m_realPos;
}
MYPOSITION MyObject::GetTilePos()
{
	/*
	타일 포지션을 반환
	아마 충돌검사에 주로 쓰이지 않을까 생각한다.
	그리고 아이템이 나왔을 때, 폭탄이 놓여졌을 때, 게임 시작할 때 블록 세팅할 때에도 유용할 것 같다.
	*/
	return m_tilePos;
}
MYPOSITION MyObject::GetSizePos()
{
	/*
	크기를 반환
	*/
	return m_sizePos;
}
void MyObject::SetRealPos(MYPOSITION pos)
{
	/*
	인자로 받아온 pos를 m_realPos에 대입함으로써 리얼 좌표 설정
	그 리얼 좌표를 가로 15칸 세로 13칸의 타일로 이루어진 크레이지 아케이드 맵에서
	어느 타일에 있을지 계산한 후 타일 좌표 설정
	*/
	m_realPos = pos;
	m_tilePos = { m_realPos.x / 15, m_realPos.y / 13 };
}
void MyObject::SetTilePos(MYPOSITION pos)
{
	/*
	인자로 받아온 pos를 m_tilePos에 대입함으로써 타일 좌표 설정
	그 타일 좌표에 크기를 곱해서 타일좌표의 리얼좌표를 계산 후 설정
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
	if (0 == m_Type) //가로형 
	{
		sx = m_Index*m_sizePos.x + m_ActionSIndex[m_ActionIndex] * m_sizePos.x;
	}
	else
	{
		//세로형 
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