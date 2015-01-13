#pragma once
#include "MyGameGlobal.h"

#define MAX_ACTION  10
class MyObject
{
private:
	MYPOSITION m_realPos;				//������ǥ ����ü
	MYPOSITION m_tilePos;				//Ÿ����ǥ ����ü : ������ǥ�� ���� ������ �ٲ��� �ϹǷ� ���� Setter�Լ��� ���� �ʰ�, ������ǥ�� ����� �� �Բ� ���õȴ�.
	MYPOSITION m_sizePos;				//��ü�� ũ�� : ȭ�鿡 �׸��� �׷����� ũ���̴�. �����ڿ��� �ʱ�ȭ�ϰ� �ٽ� �������� �����Ƿ� Setter()�� ����
	MYPOSITION m_startPos;				//������ ���� ��ǥ
	
	HBITMAP m_hBitmap;					//��Ʈ�� �ڵ� : ����, �����ڿ��� �ʱ�ȭ�ϰ� �ٽ� �������� �����Ƿ� Setter()�� ����
	COLORREF m_ColorKey;				//TransBitmapBlt() ���� �ʿ��� ����ȭ ��ų ���� Ű��, �̰� ���� ���� ��ȫ���� ���� ���Ƿ� Setter()�� ���� Getter()�� ����

	//////////////////////////////////////
	//////�ִϸ��̼ǿ� �ʿ��� �����///////
	/////////////////////////////////////
	int m_MaxCount;					/////
	int m_Index;					/////
	int m_Type; // 0:����, 1:����	/////
	int m_Loop;						/////
	int m_ActionIndex;				/////
	int m_ActionSIndex[MAX_ACTION];	/////
	int m_ActionSize[MAX_ACTION];	/////
	//////////////////////////////////////
	//////////////////////////////////////

public:
	MyObject(MYPOSITION tilePos, MYPOSITION startPos, MYPOSITION sizePos, HBITMAP hBitmap, int Type);		//������ : ������� ��Ʈ�� ���ҽ� �ڵ��̶� �ִϸ��̼�(���η� �Ǵ� ���η�)Ÿ���� �Է¹ް� ����
	virtual ~MyObject();											//�Ҹ��� : ���� �Ҹ��� �͵� ����

	//Getter
	MYPOSITION GetRealPos();
	MYPOSITION GetTilePos();
	MYPOSITION GetSizePos();
	//Setter
	void SetRealPos(MYPOSITION pos);
	void SetTilePos(MYPOSITION pos);

	void Draw(HDC hdc) const;										//��Ʈ�� ���ҽ��� ũ�⿡ ���� ȭ�鿡 �׷��ش�.
	void RunAction(int aindex, int loop);							//�׼ǽ��� : ĳ���ʹ� Ű�� ���� ��, �������� ������ ��, ��ź�� �������� �� ȣ���ϸ� �ǰ���
	void NextFrame();												//�׼��� ���۵� ��ü�� ���� �������� �ѱ�, Ÿ�̸ӿ��ٰ� �ϸ� �ǰ���
	bool NextFrameEx();												//�׼��� ���۵� ��ü�� ��� true�� ��ȯ�ϰ�, �ƴҰ�� false�� ��ȯ, �������� ���� ����

	int AddAction(int aindex, int sindex, int size);				//�׼��� �߰�, ĳ������ ��� �׼��� 4��(���⺰ �ȱ�)�̹Ƿ� 4�� ȣ���ؾ߰���, �������� �Ѱ���
};

