// Test_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Valera3D.h"

int _tmain(int argc, _TCHAR* argv[])
{
	CObject* obj = new CObject();
	obj->setName("aaa");
	std::string a = obj->getName();
	int b = 0;

	CObject* obj1(obj);
	
	return 0;
	
}

