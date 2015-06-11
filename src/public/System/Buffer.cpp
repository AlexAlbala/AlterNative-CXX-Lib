#include "Buffer.h"

namespace System{
	void Buffer::InternalBlockCopy(Array<char>* src, int srcOffset, Array<char>* dst, int dstOffset, int count){
		BlockCopy(src, srcOffset, dst, dstOffset, count);
	}

	void Buffer::BlockCopy(Array<char>* src, int srcOffset, Array<char>* dst, int dstOffset, int count){
#ifdef HIGH_PERF
		assert(src != null);
		assert(dst != null);
		assert(src->getLength() > (srcOffset + count));
		assert(dst->getLength() > (dstOffset + count));
		assert(srcOffset >= 0 && dstOffset >= 0 && count >= 0);
#else
		if(src == null){
			throw new ArgumentNullException(new String("src is null"));
		}
		if(dst == null){
			throw new ArgumentNullException(new String("src is null"));
		}
		if(src->getLength() < (srcOffset + count)){
			throw new ArgumentException(new String("src length < offset + count"));
		}
		if(dst->getLength() < (dstOffset + count)){
			throw new ArgumentException(new String("dst length < offset + count"));
		}
#endif
		memcpy(((char*)(*dst)) + dstOffset, ((char*)(*src)) + srcOffset, count);
	}
}