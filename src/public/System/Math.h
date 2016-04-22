#pragma once
#include "Object.h"
#include "String.h"

namespace System {
	class Math : public Object
	{
	public:
		static double Max(double val1, double val2);
		static double Min(double val1, double val2);
		static double Sqrt(double val);
        static double Floor(double val);
        static double Pow(double a, double b);
        static double Log(double d);
        static double Log(double d, double base);
		static double Sin(double val);
		static double Cos(double val);
		static double Tan(double val);
	};
}
