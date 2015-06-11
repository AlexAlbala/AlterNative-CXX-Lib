#pragma once

/*********************************************************************************************************/
/*********************************************** GENERAL  ************************************************/
/*********************************************************************************************************/
//#define null									nullptr
#define null									0
#ifndef __linux__
	#ifndef __APPLE__
		#define uint							unsigned int
		#define ushort							unsigned short
	#endif
	#define ulong								unsigned long long
#endif

//#define ASYNC
//#define RELEASE
#define HIGH_PERF

//For asserts if needed
/*#ifdef RELEASE
#define NDEBUG
#endif*/


#include <assert.h>