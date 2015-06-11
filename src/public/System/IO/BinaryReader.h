#pragma once
#include <System/System.h>
#include <System/IDisposable.h>
#include "Stream.h"
#include "Decoder.h"
#include <System/Text/Encoding.h>
#include <System/Exception/SystemException/ArgumentException/ArgumentNullException.h>
#include <System/Exception/SystemException/ArgumentException.h>
#include "UnicodeEncoding.h"
#include "MemoryStream.h"
#include <System/Exception/SystemException/IO/IOException.h>
#include <System/Exception/SystemException/IO/IOException/EndOfStreamException.h>
#include <System/Exception/ObjectDisposedException.h>
#include <System/Text/StringBuilder.h>
#include "StringBuilderCache.h"
#include <System/Exception/SystemException/ArgumentException/ArgumentOutOfRangeException.h>
#include <System/Buffer.h>
#include "FormatException.h"
#include "DecoderNLS.h"
#include "SeekOrigin.h"

using namespace System::Runtime::InteropServices;
using namespace System;
using namespace System::Text;
using namespace System::Runtime;
using namespace System::Security;
namespace System {
	namespace IO {
		//Attribute: __DynamicallyInvokable*
		//Attribute: ComVisible*(true)
		class BinaryReader : public virtual IDisposable, public virtual Object{
			private:
				Stream* m_stream;
			private:
				Array<char>* m_buffer;
			private:
				Decoder* m_decoder;
			private:
				Array<char>* m_charBytes;
			private:
				Array<char>* m_singleChar;
			private:
				Array<char>* m_charBuffer;
			private:
				int m_maxCharsSize;
			private:
				bool m_2BytesPerChar;
			private:
				bool m_isMemoryStream;
			private:
				bool m_leaveOpen;
			private:
				int MaxCharBytesSize;
			public:
			virtual Stream* getBaseStream();
				//Ignored empty method declaration
			//Attribute: __DynamicallyInvokable*
			//Attribute: TargetedPatchingOptOut*(new String("Performance critical to inline across NGen image boundaries"))
			public:
				BinaryReader(Stream* input);
			//Attribute: __DynamicallyInvokable*
			//Attribute: TargetedPatchingOptOut*(new String("Performance critical to inline this type of method across NGen image boundaries"))
			public:
				BinaryReader(Stream* input, Encoding* encoding);
			//Attribute: __DynamicallyInvokable*
			public:
				BinaryReader(Stream* input, Encoding* encoding, bool leaveOpen);
			//Attribute: TargetedPatchingOptOut*(new String("Performance critical to inline this type of method across NGen image boundaries"))
			public:
			virtual void Close();
			//Attribute: __DynamicallyInvokable*
			public:
			virtual void Dispose(bool disposing);
			//Attribute: __DynamicallyInvokable*
			//Attribute: TargetedPatchingOptOut*(new String("Performance critical to inline this type of method across NGen image boundaries"))
			public:
				void Dispose();
			//Attribute: __DynamicallyInvokable*
			public:
			virtual int PeekChar();
			//Attribute: __DynamicallyInvokable*
			public:
			virtual int Read();
			//Attribute: __DynamicallyInvokable*
			//Attribute: TargetedPatchingOptOut*(new String("Performance critical to inline across NGen image boundaries"))
			public:
			virtual bool ReadBoolean();
			//Attribute: __DynamicallyInvokable*
			public:
			virtual char ReadByte();
			//Attribute: __DynamicallyInvokable*
			//Attribute: CLSCompliant*(false)
			//Attribute: TargetedPatchingOptOut*(new String("Performance critical to inline across NGen image boundaries"))
			public:
			virtual short ReadSByte();
			//Attribute: __DynamicallyInvokable*
			public:
			virtual char ReadChar();
			//Attribute: __DynamicallyInvokable*
			//Attribute: TargetedPatchingOptOut*(new String("Performance critical to inline across NGen image boundaries"))
			public:
			virtual short ReadInt16();
			//Attribute: __DynamicallyInvokable*
			//Attribute: CLSCompliant*(false)
			public:
			virtual ushort ReadUInt16();
			//Attribute: __DynamicallyInvokable*
			public:
			virtual int ReadInt32();
			//Attribute: __DynamicallyInvokable*
			//Attribute: CLSCompliant*(false)
			public:
			virtual uint ReadUInt32();
			//Attribute: __DynamicallyInvokable*
			public:
			virtual long ReadInt64();
			//Attribute: __DynamicallyInvokable*
			//Attribute: CLSCompliant*(false)
			public:
			virtual ulong ReadUInt64();
			//Attribute: __DynamicallyInvokable*
			//Attribute: SecuritySafeCritical*
			public:
			virtual float ReadSingle();
			//Attribute: __DynamicallyInvokable*
			//Attribute: SecuritySafeCritical*
			public:
			virtual double ReadDouble();
			//Attribute: __DynamicallyInvokable*
			public:
			virtual float ReadDecimal();
			//Attribute: __DynamicallyInvokable*
			public:
			virtual String* ReadString();
			//Attribute: __DynamicallyInvokable*
			//Attribute: SecuritySafeCritical*
			public:
			virtual int Read(Array<char>* buffer, int index, int count);
			//Attribute: __DynamicallyInvokable*
			//Attribute: SecuritySafeCritical*
			public:
			virtual Array<char>* ReadChars(int count);
			//Attribute: __DynamicallyInvokable*
			public:
			virtual Array<char>* ReadBytes(int count);
			//Attribute: __DynamicallyInvokable*
			public:
			virtual void FillBuffer(int numBytes);
			//Attribute: __DynamicallyInvokable*
			public:
			    int Read7BitEncodedInt();
			//Attribute: SecurityCritical*
			private:
				int InternalReadChars(Array<char>* buffer, int index, int count);
			private:
				int InternalReadOneChar();
		};
	}
}