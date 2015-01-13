#pragma once
#include "MyBlock.h"
#include "MyGameGlobal.h"

class ItemBlock :
	public MyBlock
{
private:
	int m_item;
public:
	ItemBlock(MYPOSITION tilePos, MYPOSITION startPos, MYPOSITION sizePos, HBITMAP hBitmap);
	virtual ~ItemBlock();
	int GetItemInfo() const;
};

