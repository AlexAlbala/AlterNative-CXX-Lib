#pragma once
#include <stdio.h>
#include "../String.h"
#include "FileStream.h"
#include <fstream>
#include <exception>
#include "../Text/Encoding.h"
#include "../Exception/SystemException/ArgumentException/ArgumentNullException.h"

namespace System{
	namespace IO{
		class File : public virtual Object{
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