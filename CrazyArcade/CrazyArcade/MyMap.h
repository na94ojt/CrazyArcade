#pragma once
#include "MyGameGlobal.h"

class MyMap
{
private:
	int m_map[13][53];
	HBITMAP m_hInterface;
	HBITMAP m_hMap;

public:
	MyMap();
	virtual ~MyMap();

	int GetMapInfo(MYPOSITION pos) const;
	void SetMapInfo(MYPOSITION pos, int data);
};

