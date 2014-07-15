#include "Random.h"

namespace System {	
	Random::Random() {
 		srand((unsigned int)time(0));
	}

	float Random::NextDouble() {
		float randomValue = (float)rand()/(float)RAND_MAX;
		return randomValue;
	}	
}