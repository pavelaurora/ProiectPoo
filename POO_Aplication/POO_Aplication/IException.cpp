#include "IException.h"



IException::IException(char* message)
{
	this->message = _strdup(message);
}


IException::~IException()
{
	if (message != nullptr)
	{
		delete[]message;
		message = nullptr;
	}
}
