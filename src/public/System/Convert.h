#pragma once

namespace System{
	class String;

	class Convert{
	public:
		static char ToChar(int value);
		static int ToInt32(String* value);
	};
}