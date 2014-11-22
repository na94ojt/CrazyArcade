#pragma once
#include "stdafx.h"
#include "MyCharacter.h"

class MyCharacter
{
public:
	MyCharacter(int x, int y);			//������, ĳ������ �ʱ� ��ġ, ��ź ����, ��ź �Ŀ�, ���ǵ� ����
	virtual ~MyCharacter();
	void MoveLeft();					//�������� �̵�
	void MoveRight();					//���������� �̵�
	void MoveUp();						//���� �̵�
	void MoveDown();					//�Ʒ��� �̵�
	MYPOSITION GetRealPos();			//���� ��ǥ ��ȯ �޼ҵ�
	MYPOSITION GetTilePos();			//Ÿ�� ��ǥ ��ȯ �޼ҵ�

private:
	MYPOSITION m_real_pos;				//���� ��ǥ ��ü
	MYPOSITION m_tile_pos;				//Ÿ�� ��ǥ ��ü
	int m_speed;						//���ǵ�
	int m_quan_bomb;					//����� �� �ִ� ��ź�� ���� (��ź Ŭ������ ���� �迭�� ������)
	int m_power_bomb;					//��ź�� �Ŀ� (��ź Ŭ������ ����� ��ź�� �Ӽ����� ������)

	void SetTilePos();					//Ÿ����ǥ ���� �޼ҵ�
};

