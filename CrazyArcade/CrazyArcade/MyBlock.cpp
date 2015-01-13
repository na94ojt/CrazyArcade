#include "stdafx.h"
#include "MyBlock.h"


MyBlock::MyBlock(MYPOSITION tilePos, MYPOSITION startPos, MYPOSITION sizePos, HBITMAP hBitmap)
:MyObject(tilePos, startPos, sizePos, hBitmap, 0)
{
}


MyBlock::~MyBlock()
{
}
