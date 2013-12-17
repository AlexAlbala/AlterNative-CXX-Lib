#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "TextReader.h"
#include "../Object.h"
#include "../String.h"
#include "../GC.h"
#include "../Array.h"

using namespace std;

namespace System{
	namespace IO{
		class StreamReader : public TextReader
		{
		private:
			ifstream* file;
		public:	
			StreamReader(String* path);
			StreamReader(const char* path);
			~StreamReader(void);
			virtual String* ReadLine();
			virtual String* ReadToEnd();
			virtual int Peek();
			virtual int Read();
			virtual int Read(Array<char>* buffer, int index, int count);
			virtual void Dispose(bool disposing);
			virtual void Close();
		};
	}
}

