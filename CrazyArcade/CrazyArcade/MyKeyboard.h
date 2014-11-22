#pragma once
class MyKeyboard
{
public:
	MyKeyboard();
	virtual ~MyKeyboard();
	void KeyDown(int key);
	void KeyUp(int key);
	int FindKey(int key);

private:
	int m_key[20];
};

