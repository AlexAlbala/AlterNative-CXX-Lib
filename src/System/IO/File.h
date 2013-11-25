#pragma once
#include <stdio.h>
#include "../GC.h"
#include "../String.h"
#include "FileStream.h"
#include <fstream>
#include <exception>
#include "../Text/Encoding.h"
#include "../exceptions/systemException/argumentException/ArgumentNullException.h"

namespace System{
	namespace IO{
		class File : public virtual gc_cleanup{
		private:
			static String* InternalReadAllText(String* path, bool checkHost);
			static void InternalWriteAllText(String* path, String* contents, bool checkHost);

		public:
			static bool Exists(String* path);
			static void Delete(String* path);
			static FileStream* OpenRead(String* path);
			static FileStream* Create(String* path);
			static String* ReadAllText(String* path);
			static void WriteAllText(String* path, String* contents);
		};
	}
}