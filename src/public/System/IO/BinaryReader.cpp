#include "BinaryReader.h"
namespace System {
	namespace IO {
		Stream* BinaryReader::getBaseStream(){
			return this->m_stream;
		}
		//Attribute: __DynamicallyInvokable*
		//Attribute: TargetedPatchingOptOut*(new String("Performance critical to inline across NGen image boundaries"))
		BinaryReader::BinaryReader(Stream* input) : BinaryReader(input, new UTF8Encoding(), false){
			MaxCharBytesSize = 128;
		}
		//Attribute: __DynamicallyInvokable*
		//Attribute: TargetedPatchingOptOut*(new String("Performance critical to inline this type of method across NGen image boundaries"))
		BinaryReader::BinaryReader(Stream* input, Encoding* encoding) : BinaryReader(input, encoding, false){
		}
		//Attribute: __DynamicallyInvokable*
		BinaryReader::BinaryReader(Stream* input, Encoding* encoding, bool leaveOpen){
			if (input == null){
				throw new ArgumentNullException(new String("input"));
			}
			if (encoding == null) {
				throw new ArgumentNullException(new String("encoding"));
			}
			if (!input->getCanRead()) {
				throw new ArgumentException(new String("Stream not readable"));
			}
			this->m_stream = input;
			this->m_decoder = encoding->GetDecoder();
			this->m_maxCharsSize = encoding->GetMaxCharCount(128);
			int num = encoding->GetMaxByteCount(1);
			if (num < 16) {
				num = 16;
			}
			this->m_buffer = new Array<char>(num);
			this->m_2BytesPerChar = is_inst_of<UnicodeEncoding*>(encoding);
			this->m_isMemoryStream = this->m_stream->GetType() == /*ERROR: Cannot translate: System.NotImplementedException: typeOfExpression: --> TODO: --> http://www.boost.org/doc/libs/1_55_0/doc/html/typeof/tuto.html. Node: ICSharpCode.NRefactory.CSharp.TypeOfExpression*/;
			this->m_leaveOpen = leaveOpen;
		}
		//Attribute: TargetedPatchingOptOut*(new String("Performance critical to inline this type of method across NGen image boundaries"))
		void BinaryReader::Close(){
			this->Dispose(true);
		}
		//Attribute: __DynamicallyInvokable*
		void BinaryReader::Dispose(bool disposing){
			if (disposing){
				Stream* stream = this->m_stream;
				this->m_stream = null;
				if ((stream != null) && !this->m_leaveOpen){
					stream->Close();
				}
			}
			this->m_stream = null;
			this->m_buffer = null;
			this->m_decoder = null;
			this->m_charBytes = null;
			this->m_singleChar = null;
			this->m_charBuffer = null;
		}
		//Attribute: __DynamicallyInvokable*
		//Attribute: TargetedPatchingOptOut*(new String("Performance critical to inline this type of method across NGen image boundaries"))
		void BinaryReader::Dispose(){
			this->Dispose(true);
		}
		//Attribute: __DynamicallyInvokable*
		int BinaryReader::PeekChar(){
			if (this->m_stream == null){
				//__Error::FileNotOpen();
				throw new ObjectDisposedException(new String("File not open"));
			}
			if (!this->m_stream->getCanSeek()) {
				return -1;
			}
			long long position = this->m_stream->getPosition();
			int result = this->Read();
			this->m_stream->setPosition(position);
			return result;
		}
		//Attribute: __DynamicallyInvokable*
		int BinaryReader::Read(){
			if (this->m_stream == null){
				throw new ObjectDisposedException(new String("File not open"));
			}
			return this->InternalReadOneChar();
		}
		//Attribute: __DynamicallyInvokable*
		//Attribute: TargetedPatchingOptOut*(new String("Performance critical to inline across NGen image boundaries"))
		bool BinaryReader::ReadBoolean(){
			this->FillBuffer(1);
			return *(this->m_buffer->GetData(0)) != 0;
		}
		//Attribute: __DynamicallyInvokable*
		char BinaryReader::ReadByte(){
			if (this->m_stream == null){
				throw new ObjectDisposedException(new String("File not open"));
			}
			int num = this->m_stream->ReadByte();
			if (num == -1) {
				throw new EndOfStreamException(new String("End Of File"));
			}
			return (char)(num);
		}
		//Attribute: __DynamicallyInvokable*
		//Attribute: CLSCompliant*(false)
		//Attribute: TargetedPatchingOptOut*(new String("Performance critical to inline across NGen image boundaries"))
		short BinaryReader::ReadSByte(){
			this->FillBuffer(1);
			return (short)(this->m_buffer->GetData(0));
		}
		//Attribute: __DynamicallyInvokable*
		char BinaryReader::ReadChar(){
			int num = this->Read();
			if (num == -1){
				throw new EndOfStreamException(new String("End Of File"));
			}
			return (char)(num);
		}
		//Attribute: __DynamicallyInvokable*
		//Attribute: TargetedPatchingOptOut*(new String("Performance critical to inline across NGen image boundaries"))
		short BinaryReader::ReadInt16(){
			this->FillBuffer(2);
			return (short)((int)(this->m_buffer->GetData(0)) | ((int)(this->m_buffer->GetData(1)) << 8));
		}
		//Attribute: __DynamicallyInvokable*
		//Attribute: CLSCompliant*(false)
		ushort BinaryReader::ReadUInt16(){
			this->FillBuffer(2);
			return (ushort)((int)(this->m_buffer->GetData(0)) | ((int)(this->m_buffer->GetData(1)) << 8));
		}
		//Attribute: __DynamicallyInvokable*
		int BinaryReader::ReadInt32(){
			if (this->m_isMemoryStream){
				if (this->m_stream == null){
					throw new ObjectDisposedException(new String("File not open"));
				}
				MemoryStream* memoryStream = as_cast<MemoryStream*>(this->m_stream);
				return memoryStream->InternalReadInt32();
			}
			this->FillBuffer(4);
			return (((int)(this->m_buffer->GetData(0)) | ((int)(this->m_buffer->GetData(1)) << 8)) | ((int)(this->m_buffer->GetData(2)) << 16)) | ((int)(this->m_buffer->GetData(3)) << 24);
		}
		//Attribute: __DynamicallyInvokable*
		//Attribute: CLSCompliant*(false)
		uint BinaryReader::ReadUInt32(){
			this->FillBuffer(4);
			return (uint)((((int)(this->m_buffer->GetData(0)) | ((int)(this->m_buffer->GetData(1)) << 8)) | ((int)(this->m_buffer->GetData(2)) << 16)) | ((int)(this->m_buffer->GetData(3)) << 24));
		}
		//Attribute: __DynamicallyInvokable*
		long BinaryReader::ReadInt64(){
			this->FillBuffer(8);
			uint num = (uint)((((int)(this->m_buffer->GetData(0)) | ((int)(this->m_buffer->GetData(1)) << 8)) | ((int)(this->m_buffer->GetData(2)) << 16)) | ((int)(this->m_buffer->GetData(3)) << 24));
			uint num2 = (uint)((((int)(this->m_buffer->GetData(4)) | ((int)(this->m_buffer->GetData(5)) << 8)) | ((int)(this->m_buffer->GetData(6)) << 16)) | ((int)(this->m_buffer->GetData(7)) << 24));
			return (long)(((ulong)(num2) << 32) | (ulong)(num));
		}
		//Attribute: __DynamicallyInvokable*
		//Attribute: CLSCompliant*(false)
		ulong BinaryReader::ReadUInt64(){
			this->FillBuffer(8);
			uint num = (uint)((((int)(this->m_buffer->GetData(0)) | ((int)(this->m_buffer->GetData(1)) << 8)) | ((int)(this->m_buffer->GetData(2)) << 16)) | ((int)(this->m_buffer->GetData(3)) << 24));
			uint num2 = (uint)((((int)(this->m_buffer->GetData(4)) | ((int)(this->m_buffer->GetData(5)) << 8)) | ((int)(this->m_buffer->GetData(6)) << 16)) | ((int)(this->m_buffer->GetData(7)) << 24));
			return ((ulong)(num2) << 32) | (ulong)(num);
		}
		//Attribute: __DynamicallyInvokable*
		//Attribute: SecuritySafeCritical*
		float BinaryReader::ReadSingle(){
			this->FillBuffer(4);
			uint num = (uint)((((int)(this->m_buffer->GetData(0)) | ((int)(this->m_buffer->GetData(1)) << 8)) | ((int)(this->m_buffer->GetData(2)) << 16)) | ((int)(this->m_buffer->GetData(3)) << 24));
			return *(float*)(&num);
		}
		//Attribute: __DynamicallyInvokable*
		//Attribute: SecuritySafeCritical*
		double BinaryReader::ReadDouble(){
			this->FillBuffer(8);
			uint num = (uint)((((int)(this->m_buffer->GetData(0)) | ((int)(this->m_buffer->GetData(1)) << 8)) | ((int)(this->m_buffer->GetData(2)) << 16)) | ((int)(this->m_buffer->GetData(3)) << 24));
			uint num2 = (uint)((((int)(this->m_buffer->GetData(4)) | ((int)(this->m_buffer->GetData(5)) << 8)) | ((int)(this->m_buffer->GetData(6)) << 16)) | ((int)(this->m_buffer->GetData(7)) << 24));
			ulong num3 = ((ulong)(num2) << 32) | (ulong)(num);
			return *(double*)(&num3);
		}
		//Attribute: __DynamicallyInvokable*
		float BinaryReader::ReadDecimal(){
			this->FillBuffer(16);
			float result;
			try{
				result = Float::ToDecimal(this->m_buffer);
			}
			catch (ArgumentException* innerException) {
				throw new IOException(new String("Arg_DecBitCtor"), innerException);
			}
			return result;
		}
		//Attribute: __DynamicallyInvokable*
		String* BinaryReader::ReadString(){
			if (this->m_stream == null){
				throw new ObjectDisposedException(new String("File not open"));
			}
			int num = 0;
			int num2 = this->Read7BitEncodedInt();
			if (num2 < 0) {
				String* arg_33_0 = new String("IO.IO_InvalidStringLen_Len");
				Array<Object>* array = new Array<Object>(1);
				array->SetData(0, BOX<int>(num2));
				throw new IOException(Environment::GetResourceString(arg_33_0, array));
			}
			if (num2 == 0) {
				return String::Empty;
			}
			if (this->m_charBytes == null) {
				this->m_charBytes = new Array<char>(128);
			}
			if (this->m_charBuffer == null) {
				this->m_charBuffer = new Array<char>(this->m_maxCharsSize);
			}
			StringBuilder* stringBuilder = null;
			int chars;
			while (true) {
				int count = (num2 - num) > 128 ? 128 : num2 - num;
				int num3 = this->m_stream->Read(this->m_charBytes, 0, count);
				if (num3 == 0) {
					throw new EndOfStreamException(new String("End Of File"));
				}
				chars = this->m_decoder->GetChars(this->m_charBytes, 0, num3, this->m_charBuffer, 0);
				if ((num == 0) && (num3 == num2)) {
					break;
				}
				if (stringBuilder == null) {
					stringBuilder = StringBuilderCache::Acquire(num2);
				}
				stringBuilder->Append(this->m_charBuffer, 0, chars);
				num += num3;
				if (num >= num2) {
					goto Block_11;
				}
			}
			return new String(this->m_charBuffer, 0, chars);
			Block_11:
			return StringBuilderCache::GetStringAndRelease(stringBuilder);
		}
		//Attribute: __DynamicallyInvokable*
		//Attribute: SecuritySafeCritical*
		/*int BinaryReader::Read(Array<char>* buffer, int index, int count){
			if (buffer == null){
				throw new ArgumentNullException(new String("buffer"),new String("Argument null"));
			}
			if (index < 0) {
				throw new ArgumentOutOfRangeException(new String("index"), new String("Argument out of range. Need non negative number"));
			}
			if (count < 0) {
				throw new ArgumentOutOfRangeException(new String("count"), new String("Argument out of range. Need non negative number"));
			}
			if ((buffer->Length - index) < count) {
				throw new ArgumentException(new String("Invalid offset length"));
			}
			if (this->m_stream == null) {
				__Error::FileNotOpen();
			}
			return this->InternalReadChars(buffer, index, count);
		}*/
		//Attribute: __DynamicallyInvokable*
		//Attribute: SecuritySafeCritical*
		Array<char>* BinaryReader::ReadChars(int count){
			if (count < 0){
				throw new ArgumentOutOfRangeException(new String("count"), new String("Argument out of range. Need non negative number"));
			}
			if (this->m_stream == null) {
				throw new ObjectDisposedException(new String("File not open"));
			}
			if (count == 0) {
				return new Array<char>(0);
			}
			Array<char>* array = new Array<char>(count);
			int num = this->InternalReadChars(array, 0, count);
			if (num != count) {
				Array<char>* array2 = new Array<char>(num);
				Buffer::InternalBlockCopy(array, 0, array2, 0, 2 * num);
				array = array2;
			}
			return array;
		}
		//Attribute: __DynamicallyInvokable*
		int BinaryReader::Read(Array<char>* buffer, int index, int count){
			if (buffer == null){
				throw new ArgumentNullException(new String("buffer"),new String("Argument null"));
			}
			if (index < 0) {
				throw new ArgumentOutOfRangeException(new String("index"), new String("Argument out of range. Need non negative number"));
			}
			if (count < 0) {
				throw new ArgumentOutOfRangeException(new String("count"), new String("Argument out of range. Need non negative number"));
			}
			if ((buffer->Length - index) < count) {
				throw new ArgumentException(new String("Invalid offset length"));
			}
			if (this->m_stream == null) {
				throw new ObjectDisposedException(new String("File not open"));
			}
			return this->m_stream->Read(buffer, index, count);
		}
		//Attribute: __DynamicallyInvokable*
		Array<char>* BinaryReader::ReadBytes(int count){
			if (count < 0){
				throw new ArgumentOutOfRangeException(new String("count"), new String("Argument out of range. Need non negative number"));
			}
			if (this->m_stream == null) {
				throw new ObjectDisposedException(new String("File not open"));
			}
			if (count == 0) {
				return new Array<char>(0);
			}
			Array<char>* array = new Array<char>(count);
			int num = 0;
			do {
				int num2 = this->m_stream->Read(array, num, count);
				if (num2 == 0) {
					break;
				}
				num += num2;
				count -= num2;
			}
			while (count > 0);
			if (num != array->Length) {
				Array<char>* array2 = new Array<char>(num);
				Buffer::InternalBlockCopy(array, 0, array2, 0, num);
				array = array2;
			}
			return array;
		}
		//Attribute: __DynamicallyInvokable*
		void BinaryReader::FillBuffer(int numBytes){
			if ((this->m_buffer != null) && ((numBytes < 0) || (numBytes > this->m_buffer->Length))){
				throw new ArgumentOutOfRangeException(new String("numBytes"), new String("Argument Out Of Range. BinaryReaderFillBuffer"));
			}
			int num = 0;
			if (this->m_stream == null) {
				throw new ObjectDisposedException(new String("File not open"));
			}
			if (numBytes == 1) {
				int num2 = this->m_stream->ReadByte();
				if (num2 == -1) {
					throw new EndOfStreamException(new String("End Of File"));
				}
				this->m_buffer->SetData(0, (char)(num2));
				return;
			}
			do {
				int num2 = this->m_stream->Read(this->m_buffer, num, numBytes - num);
				if (num2 == 0) {
					throw new EndOfStreamException(new String("End Of File"));
				}
				num += num2;
			}
			while (num < numBytes);
		}
		//Attribute: __DynamicallyInvokable*
		int BinaryReader::Read7BitEncodedInt(){
			int num = 0;
			int num2 = 0;
			while (num2 != 35){
				char b = this->ReadByte();
				num = num | (int)(b & 127) << num2;
				num2 += 7;
				if ((b & 128) == 0){
					return num;
				}
			}
			throw new FormatException(Environment::GetResourceString(new String("Format_Bad7BitInt32")));
		}
		//Attribute: SecurityCritical*
		int BinaryReader::InternalReadChars(Array<char>* buffer, int index, int count){
			int i = count;
			if (this->m_charBytes == null){
				this->m_charBytes = new Array<char>(128);
			}
			while (i > 0) {
				int num = i;
				DecoderNLS* decoderNLS = as_cast<DecoderNLS*>(this->m_decoder);
				if (((decoderNLS != null) && decoderNLS->HasState) && (num > 1)) {
					num -= 1;
				}
				if (this->m_2BytesPerChar) {
					num <<= 1;
				}
				if (num > 128) {
					num = 128;
				}
				int num2 = 0;
				Array<char>* array;
				if (this->m_isMemoryStream) {
					MemoryStream* memoryStream = as_cast<MemoryStream*>(this->m_stream);
					num2 = memoryStream->InternalGetPosition();
					num = memoryStream->InternalEmulateRead(num);
					array = memoryStream->InternalGetBuffer();
				}
				else {
					num = this->m_stream->Read(this->m_charBytes, 0, num);
					array = this->m_charBytes;
				}
				if (num == 0) {
					return count - i;
				}
				int chars;
				//Fixed statement ignored
				char*ptr = *array;

				//Start fixed block
				//Fixed statement ignored
				char*ptr2 = *buffer;

				//Start fixed block
				chars = this->m_decoder->GetChars(ptr + ((IntPtr)(num2) / 1), num, ptr2 + (IntPtr)(index), i, false);
				//End fixed block
				//End fixed block
				i -= chars;
				index += chars;
			}
			return count - i;
		}
		int BinaryReader::InternalReadOneChar()
		{
			int num = 0;
			long long num2 = num2 = 0L;
			if (this->m_stream->getCanSeek()) {
				num2 = this->m_stream->getPosition();
			}
			if (this->m_charBytes == null) {
				this->m_charBytes = new Array<char>(128);
			}
			if (this->m_singleChar == null) {
				this->m_singleChar = new Array<char>(1);
			}
			while (num == 0) {
				int num3 = this->m_2BytesPerChar ? 2 : 1;
				int num4 = this->m_stream->ReadByte();
				this->m_charBytes->SetData(0, (char)(num4));
				if (num4 == -1) {
					num3 = 0;
				}
				if (num3 == 2) {
					num4 = this->m_stream->ReadByte();
					this->m_charBytes->SetData(1, (char)(num4));
					if (num4 == -1) {
						num3 = 1;
					}
				}
				if (num3 == 0) {
					return -1;
				}
				try {
					num = this->m_decoder->GetChars(this->m_charBytes, 0, num3, this->m_singleChar, 0);
				}
				catch (Object* ex_C1) {
					if (this->m_stream->getCanSeek()) {
						this->m_stream->Seek(num2 - this->m_stream->getPosition(), SeekOrigin::Current);
					}
					throw;
				}
			}
			if (num == 0) {
				return -1;
			}
			return (int)(this->m_singleChar->GetData(0));
		}

	}
}