#pragma once
#include<iostream>
#include<vector>

enum FileMode
{
	read,
	write,
	append
};

int ConvertArrayToInt(char* array);
void AddIntToArray(char* buffer, int integer);
char* ConvertBytesToString(char* buffer, int size);
FILE* OpenFile(char* file, FileMode mode);
char* ReadFile(char* filename, int &readSize);

