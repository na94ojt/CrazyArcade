#pragma once
#include "MyObject.h"
class MyBlock :
	public MyObject
{
public:
	MyBlock(MYPOSITION tilePos, MYPOSITION startPos, MYPOSITION sizePos, HBITMAP hBitmap);
	virtual ~MyBlock();
};

