#pragma once
#include "MyBlock.h"
class SolidBlock :
	public MyBlock
{
public:
	SolidBlock(MYPOSITION tilePos, MYPOSITION startPos, MYPOSITION sizePos, HBITMAP hBitmap);
	virtual ~SolidBlock();
};

