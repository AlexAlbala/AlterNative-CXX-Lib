#pragma once
#include "../IDisposable.h"
namespace System{
	namespace IO{
		class Stream : public IDisposable
		{
		public:
			void Dispose();
			virtual void Dispose(bool disposing);
			virtual void Close();
			

			virtual bool getCanRead() = 0;
			virtual bool getCanSeek() = 0;
			virtual bool getCanTimeout() = 0;
			virtual bool getCanWrite() = 0;

			virtual long long getLength() = 0;

			virtual long long getPosition() = 0;
			virtual void setPosition(long long value) = 0;

			virtual int getReadTimeout();
			virtual void setReadTimeout(int value);


			virtual int getWriteTimeout();
			virtual void setWriteTimeout(int value);
		};
	}
}