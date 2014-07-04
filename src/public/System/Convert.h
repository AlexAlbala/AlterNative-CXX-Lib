#pragma once

namespace System{
	class String;

	class Convert{
	public:
		static char ToChar(int value);



		static int ToInt32(String* value);
		static float ToSingle(String* value);
		static double ToDouble(String* value);
		static long long ToInt64(String* value);
	};
}