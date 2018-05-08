#include "Utils.h"


int ConvertArrayToInt(char * array)
{
	int integer = 0;
	memcpy(&integer, array, 4);
	return integer;
}

void AddIntToArray(char * buffer, int integer)
{
	memcpy(buffer, &integer, 4);
}

char * ConvertBytesToString(char * buffer, int size)
{
	char* nbyte = new char[size + 1];
	nbyte[size] = NULL;
	memcpy(nbyte, buffer, size);
	return nbyte;
}

FILE * OpenFile(char * file, FileMode mode)
{
	FILE* f = nullptr;
	if (mode == FileMode::read)
		f = fopen(file, "rb");
	else if (mode == FileMode::write)
		f = fopen(file, "wb");
	else
		f = fopen(file, "w+");
	if (f == NULL)
		return nullptr;
	else
		return f;
}


char * ReadFile(char * filename, int & readSize)
{
	char* buffer;
	FILE* f = OpenFile(filename, FileMode::read);
	if (f != nullptr)
	{
		fseek(f, SEEK_END, 0);
		readSize = ftell(f);
		fseek(f, SEEK_SET, 0);
		buffer = new char[readSize];
		fread(buffer, sizeof(char), readSize, f);
		return buffer;
	}
	else
		return nullptr;
	
}
