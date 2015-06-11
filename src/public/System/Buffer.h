#pragma once
#include <System/System.h>

namespace System{
	class Buffer : public virtual Object{
	public:
		static void InternalBlockCopy(Array<char>* src, int srcOffset, Array<char>* dst, int dstOffset, int count);
		static void BlockCopy(Array<char>* src, int srcOffset, Array<char>* dst, int dstOffset, int count);
	};
}