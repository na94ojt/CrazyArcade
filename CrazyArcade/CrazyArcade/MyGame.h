#pragma once
#include "stdafx.h"
#include "MyKeyboard.h"
#include "MyKeyboard.h"

class MyGame
{
public:
	MyGame(HWND hWnd, HINSTANCE hInst);				//������ : ���� ũ��� ��ǥ, ��Ʈ�� �ڵ��� �ʱ�ȭ�Ѵ�.
	virtual ~MyGame();
private:
	MyKeyboard m_keyboard;							//���� Ű �Է� ������ ���� Ű���� ��ü
	CBitmap m_hBackgroundBit;						//����ȭ���� ���ΰ� �ִ� �������̽� ���� ��Ʈ�� ��ü
	CBitmap m_hBackgroundFieldBit;					//���� ȭ�� �ʵ� ���� ��Ʈ�� ��ü
	CBitmap m_hHardBlockBit;						//���ӿ��� �ȱ����� ��� ���� ��Ʈ�� ��ü
	MYPOSITION m_start_interface;					//����ȭ���� ���ΰ� �ִ� �������̽��� �׸��� ���� ��ġ
	MYPOSITION m_start_Game;						//����ȭ���� �׸��� ���� ��ġ
	MYPOSITION m_size_interface;					//����ȭ���� ���ΰ� �ִ� �������̽��� ũ�� (=�׸��� ��ǥ����)
	MYPOSITION m_size_Game;							//����ȭ���� ũ�� (=�׸��� ��ǥ����)

public:
	void DrawGame(HWND hWnd, HDC hdc);				//���� ȭ���� ���������� �׷��ִ� �޼ҵ�
	void KeyDown(int key);							//Ű�� ������ �� m_keyboard�� KeyDown�޼ҵ带 ����ϱ� ���� ĸ��(?) (Ű���� ���ۿ� Ű ����)
	void KeyUp(int key);							//Ű���� ���� ���� �� m_keyboard�� KeyUp�޼ҵ带 ����ϱ� ���� ĸ��(?) (Ű���� ���ۿ��� Ű ����)
	void CheckKey();								//�ǽð����� Ű���� ���۸� �˻��ϱ� ���� �޼ҵ�
};

