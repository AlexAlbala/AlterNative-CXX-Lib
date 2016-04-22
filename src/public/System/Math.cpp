#include "Math.h"
#include <math.h>

namespace System {

	double Math::Max(double val1, double val2){		
		return val1 > val2 ? val1 : val2;
	}
	
    double Math::Min(double val1, double val2){		
		return val1 > val2 ? val2 : val1;
	}

	double Math::Sqrt(double val){
		return sqrt(val);
	}

    double Math::Floor(double val) {
        return floor(val);
    }

    double Math::Pow(double a, double b) {
        return pow(a,b);
    }

    double Math::Log(double d) {
        return log(d);
    }

    double Math::Log(double d, double base) {
        return log(d)/log(base);
    }

    double Math::Sin(double d) {
        return sin(d);
    }
    
    double Math::Cos(double d) {
        return cos(d);
    }
    
    double Math::Tan(double d) {
        return tan(d);
    }

}
