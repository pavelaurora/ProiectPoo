#pragma once
#include<iostream>
class IException
{
public:
	IException(char* message);
	~IException();
	char* message = nullptr;
};

