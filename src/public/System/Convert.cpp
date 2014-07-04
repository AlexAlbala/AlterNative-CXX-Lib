#include "Convert.h"
#include <System/Exception/SystemException/ArgumentException/ArgumentOutOfRangeException.h>

//#include "Object.h"
using namespace std;

namespace System{
	char Convert::ToChar(int value)
	{
		if(value < 0 || value > 65535)
		{
			throw new ArgumentOutOfRangeException(new String("Argument must be between 0 and 65535"), new String("value"));
		}
		return (char)value;
	}

	int Convert::ToInt32(String* value)
	{
		return atoi(*value);
	}

	float Convert::ToSingle(String* value)
	{
		return (float)atof(*value);
	}

	double Convert::ToDouble(String* value)
	{
		return atof(*value);
	}

	long long Convert::ToInt64(String* value)
	{
		return atol(*value);
	}
}