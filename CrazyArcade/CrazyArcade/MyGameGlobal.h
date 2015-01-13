#ifndef _MYGAMEGLOBAL_H_
#define _MYGAMEGLOBAL_H_

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

//Object
#define SOLIDBLOCK		1
#define ITEMBLOCK		2
#define BOMB			3
#define ITEM			4

//ITEM
#define MAXITEM			4
#define NOITEM			0
#define SPEED			1
#define POWER			2
#define BOMB			3

typedef struct
{
	int x;
	int y;
}MYPOSITION;

#endif