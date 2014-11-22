#pragma once
#include "stdafx.h"
#include "MyCharacter.h"

class MyCharacter
{
public:
	MyCharacter(int x, int y);			//생성자, 캐릭터의 초기 위치, 폭탄 갯수, 폭탄 파워, 스피드 설정
	virtual ~MyCharacter();
	void MoveLeft();					//왼쪽으로 이동
	void MoveRight();					//오른쪽으로 이동
	void MoveUp();						//위로 이동
	void MoveDown();					//아래로 이동
	MYPOSITION GetRealPos();			//실제 좌표 반환 메소드
	MYPOSITION GetTilePos();			//타일 좌표 반환 메소드

private:
	MYPOSITION m_real_pos;				//실제 좌표 객체
	MYPOSITION m_tile_pos;				//타일 좌표 객체
	int m_speed;						//스피드
	int m_quan_bomb;					//사용할 수 있는 폭탄의 갯수 (폭탄 클래스를 만들어서 배열로 만들자)
	int m_power_bomb;					//폭탄의 파워 (폭탄 클래스를 만들고 폭탄의 속성으로 만들자)

	void SetTilePos();					//타일좌표 설정 메소드
};

