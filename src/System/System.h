#pragma once

//tell boehm gc to activate the thread support
#ifndef GC_THREADS
#define GC_THREADS
#endif
#include "predefs.h"
#include "Object.h"
#include "String.h"
#include "Exception.h"
#include "Array.h"
#include "GC.h"
#include "support.h"