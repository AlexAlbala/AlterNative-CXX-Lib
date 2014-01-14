#pragma once
#include "System.h"

namespace System
{
	class IDisposable : public virtual Object
	{
	public:
		virtual void Dispose() = 0;
	};
}