#pragma once
#include "System.h"

namespace System{
	
	class TimeSpan : public virtual Object
	{
	public:	
		long TotalMilliseconds;

		TimeSpan();
		
	};
}