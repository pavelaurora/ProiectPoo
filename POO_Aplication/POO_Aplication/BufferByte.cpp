#include "BufferByte.h"


char * BufferByte::Serialize(int value) //int 10
{
	char* buffer = new char[2]; 
	buffer[0] = 0; //tipul int
	AddIntToArray(buffer + 1, value);
	return buffer;
}

char * BufferByte::Serialize(char * buffer, int size, int & retSize) //char 5 "pavel"
{
	char* nBuffer = new char[size + 2];
	retSize = 2 + size;
	nBuffer[0] = 1; //tipul char
	AddIntToArray(nBuffer + 1, size);
	memcpy(nBuffer + 2, buffer, size);
	return nBuffer;
}

void * BufferByte::Deserialize(char * buffer)
{
	if (buffer == nullptr || buffer == NULL)
		throw new IException("Input---NULL!");
	switch (buffer[0])
	{
	case INT_TYPE:
	{
		int* valoare = new int[1];
		valoare[0] = ConvertArrayToInt(buffer + 1);
		return valoare;
	}
	case CHAR_VECTOR_TYPE:
	{
		int lungime = ConvertArrayToInt(buffer + 1);
		return ConvertBytesToString(buffer + 2, lungime);
	}
	default:
		return nullptr;
	}

}
