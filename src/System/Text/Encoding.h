#include "../String.h"
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
	}
}