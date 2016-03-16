#pragma once
#include "Object.h"
#include "String.h"

namespace System {
	class Console : public Object
	{
	public:

		static void Write(char* txt);
		static void Write(char txt);
		static void Write(int i);
		static void Write(long l);
		static void Write(bool b);
		static void Write(float f);
		static void Write(double d);
		static void Write(String* s);

		static void WriteLine(char* txt);
		static void WriteLine(char txt);
		static void WriteLine(int i);
		static void WriteLine(long l);
		static void WriteLine(bool b);
		static void WriteLine(float f);
		static void WriteLine(double d);
		static void WriteLine(Object* o);
		static void WriteLine(Array<char>* c);
		static void WriteLine(String* s);
		static void WriteLine();

		static String* ReadLine();
	};
}
