#include "stdafx.h"
#include "ItemBlock.h"


ItemBlock::ItemBlock(MYPOSITION tilePos, MYPOSITION startPos, MYPOSITION sizePos, HBITMAP hBitmap)
: MyBlock(tilePos, startPos, sizePos, hBitmap)
{
	this->m_item = rand() % MAXITEM;
}


ItemBlock::~ItemBlock()
{
}

int ItemBlock::GetItemInfo() const
{
	return this->m_item;
}