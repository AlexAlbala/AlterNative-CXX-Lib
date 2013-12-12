#include "../System.h"

namespace System{
	namespace Text{
		class Encoding : public Object, public gc_cleanup {
			public : 
				class UTF8
				{
				public:
					static Array<byte>* GetBytes(String* value);
					static String* GetString(byte* bytes);
					static String* GetString(Array<byte>* bytes);
				};

		};

		class UTF8Encoding : public Object, public gc_cleanup {
		public:
			String* GetString(Array<byte>* input);
			Array<byte>* GetBytes(String* input);
		};
	}
}
