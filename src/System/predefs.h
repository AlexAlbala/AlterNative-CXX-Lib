#pragma once
//tell boehm gc to activate the thread support
#ifndef GC_THREADS
#define GC_THREADS
#endif

//Be sure to be setted this variable in windows environment... 
//Avoids duplication errors between boost and gc libraries
#if defined(_WIN32) && !defined(WIN32_LEAN_AND_MEAN)
#define WIN32_LEAN_AND_MEAN
#endif