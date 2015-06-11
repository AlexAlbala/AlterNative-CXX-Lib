#pragma once

namespace System{
	namespace Threading{
		class Interlocked{
		public:
			static int CompareExchange(int* location1, int value, int comaparand){
				if((*location1) == comparand)
					*location1 = value;
			}
		};
	}
}