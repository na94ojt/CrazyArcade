#pragma once
#include "stdafx.h"
#include "MyKeyboard.h"
#include "MyKeyboard.h"

class MyGame
{
public:
	MyGame(HWND hWnd, HINSTANCE hInst);				//생성자 : 각종 크기와 좌표, 비트맵 핸들을 초기화한다.
	virtual ~MyGame();
private:
	MyKeyboard m_keyboard;							//동시 키 입력 지원을 위한 키보드 객체
	CBitmap m_hBackgroundBit;						//게임화면을 감싸고 있는 인터페이스 사진 비트맵 객체
	CBitmap m_hBackgroundFieldBit;					//게임 화면 필드 사진 비트맵 객체
	CBitmap m_hHardBlockBit;						//게임에서 안깨지는 블록 사진 비트맵 객체
	MYPOSITION m_start_interface;					//게임화면을 감싸고 있는 인터페이스의 그리기 시작 위치
	MYPOSITION m_start_Game;						//게임화면의 그리기 시작 위치
	MYPOSITION m_size_interface;					//게임화면을 감싸고 있는 인터페이스의 크기 (=그리기 목표지점)
	MYPOSITION m_size_Game;							//게임화면의 크기 (=그리기 목표지점)

public:
	void DrawGame(HWND hWnd, HDC hdc);				//게임 화면을 종합적으로 그려주는 메소드
	void KeyDown(int key);							//키를 눌렀을 때 m_keyboard의 KeyDown메소드를 사용하기 위한 캡슐(?) (키보드 버퍼에 키 저장)
	void KeyUp(int key);							//키에서 손을 땟을 때 m_keyboard의 KeyUp메소드를 사용하기 위한 캡슐(?) (키보드 버퍼에서 키 삭제)
	void CheckKey();								//실시간으로 키보드 버퍼를 검사하기 위한 메소드
};

