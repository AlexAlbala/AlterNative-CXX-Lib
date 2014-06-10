#pragma once
#include <System/Convert.h>


namespace System{
	struct ValueType
	{
	public:
		//ToString
		//GetHashCode
	};

	struct Int : ValueType
	{
	public:
		static int Parse(String* text)
		{
			return System::Convert::ToInt32(text);
		}
	};

	struct Int32 : Int
	{};
}

