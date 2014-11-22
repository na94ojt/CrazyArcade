#include "stdafx.h"
#include "MyCharacter.h"


MyCharacter::MyCharacter(int x, int y)
{
	this->m_real_pos = { x, y };
	this->SetTilePos();
}


MyCharacter::~MyCharacter()
{
}

void MyCharacter::MoveLeft()
{
	this->m_real_pos.x -= this->m_speed;
}

void MyCharacter::MoveRight()
{
	this->m_real_pos.x += this->m_speed;
}

void MyCharacter::MoveUp()
{
	this->m_real_pos.y -= this->m_speed;
}

void MyCharacter::MoveDown()
{
	this->m_real_pos.y += this->m_speed;
}

MYPOSITION MyCharacter::GetRealPos()
{
	return this->m_real_pos;
}

MYPOSITION MyCharacter::GetTilePos()
{
	return this->m_tile_pos;
}

void MyCharacter::SetTilePos()
{
	
}