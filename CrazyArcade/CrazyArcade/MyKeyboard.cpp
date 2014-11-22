#include "stdafx.h"
#include "MyKeyboard.h"


MyKeyboard::MyKeyboard()
{
	ZeroMemory(this->m_key, sizeof(this->m_key));
}


MyKeyboard::~MyKeyboard()
{
}

void MyKeyboard::KeyDown(int key)
{
	int i;

	if (0 == this->FindKey(key))
	{
		for (i = 0; i < sizeof(this->m_key) / sizeof(int); i++)
		{
			if (0 == this->m_key[i])
			{
				this->m_key[i] = key;
			}
		}
	}
}

void MyKeyboard::KeyUp(int key)
{
	int index = FindKey(key);

	if (-1 != index)
	{
		this->m_key[index] = 0;
	}

}

int MyKeyboard::FindKey(int key)
{
	int i;

	for (i = 0; i < sizeof(this->m_key) / sizeof(int); i++)
	{
		if (key == this->m_key[i])
		{
			return i;
		}
	}

	return 0;
}