#pragma once
#include"Utils.h"
#include"IException.h"

#define INT_TYPE 0
#define CHAR_VECTOR_TYPE 1


class BufferByte
{
public:
	static char* Serialize(int value);
	static char* Serialize(char* buffer, int size, int &retSize);

	static void* Deserialize(char*  buffer);
};

