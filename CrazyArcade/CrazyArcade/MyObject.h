#pragma once
#include "MyGameGlobal.h"

#define MAX_ACTION  10
class MyObject
{
private:
	MYPOSITION m_realPos;				//리얼좌표 구조체
	MYPOSITION m_tilePos;				//타일좌표 구조체 : 리얼좌표가 변할 때마다 바뀌어야 하므로 따로 Setter함수를 갖지 않고, 리얼좌표가 변경될 때 함께 세팅된다.
	MYPOSITION m_sizePos;				//객체의 크기 : 화면에 그림이 그려지는 크기이다. 생성자에서 초기화하고 다시 설정되지 않으므로 Setter()가 없음
	MYPOSITION m_startPos;				//게임의 시작 좌표
	
	HBITMAP m_hBitmap;					//비트맵 핸들 : 사진, 생성자에서 초기화하고 다시 설정되지 않으므로 Setter()가 없음
	COLORREF m_ColorKey;				//TransBitmapBlt() 에서 필요한 투명화 시킬 색의 키값, 이건 보통 내가 분홍색을 자주 쓰므로 Setter()도 없고 Getter()도 없음

	//////////////////////////////////////
	//////애니메이션에 필요한 멤버들///////
	/////////////////////////////////////
	int m_MaxCount;					/////
	int m_Index;					/////
	int m_Type; // 0:가로, 1:세로	/////
	int m_Loop;						/////
	int m_ActionIndex;				/////
	int m_ActionSIndex[MAX_ACTION];	/////
	int m_ActionSize[MAX_ACTION];	/////
	//////////////////////////////////////
	//////////////////////////////////////

public:
	MyObject(MYPOSITION tilePos, MYPOSITION startPos, MYPOSITION sizePos, HBITMAP hBitmap, int Type);		//생성자 : 사이즈랑 비트맵 리소스 핸들이랑 애니메이션(세로로 또는 가로로)타입을 입력받고 세팅
	virtual ~MyObject();											//소멸자 : 딱히 소멸할 것도 없음

	//Getter
	MYPOSITION GetRealPos();
	MYPOSITION GetTilePos();
	MYPOSITION GetSizePos();
	//Setter
	void SetRealPos(MYPOSITION pos);
	void SetTilePos(MYPOSITION pos);

	void Draw(HDC hdc) const;										//비트맵 리소스와 크기에 따라서 화면에 그려준다.
	void RunAction(int aindex, int loop);							//액션시작 : 캐릭터는 키를 누를 때, 아이템은 나왔을 때, 폭탄은 놓아졌을 때 호출하면 되겠음
	void NextFrame();												//액션이 시작된 객체를 다음 동작으로 넘김, 타이머에다가 하면 되겠음
	bool NextFrameEx();												//액션이 시작된 객체일 경우 true를 반환하고, 아닐경우 false를 반환, 나머지는 위와 같음

	int AddAction(int aindex, int sindex, int size);				//액션을 추가, 캐릭터의 경우 액션이 4개(방향별 걷기)이므로 4번 호출해야겠음, 나머지는 한개씩
};

