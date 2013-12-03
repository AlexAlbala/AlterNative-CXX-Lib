#pragma once
#include <boost/thread/mutex.hpp>

/*********************************************************************************************************/
/************************************************ LOCK  **************************************************/
/*********************************************************************************************************/

//TODO: Change this-> use boost synchronization library
/*link: http://www.boost.org/doc/libs/1_54_0/doc/html/thread/synchronization.html*/
//
//
//lock();
//try_lock();
//unlock();

/*#if _WIN32
#define an_init_lock(x)						__win_init_lock(x)
#elif LINUX
#define an_init_lock(x)						 __unix_init_lock(x)
#endif

#if _WIN32
#define an_lock(x)							__win_lock(x)
#elif LINUX
#define an_lock(x)								__unix_lock(x)
#endif

#if _WIN32
#define an_end_lock(x)						__win_end_lock(x)
#elif LINUX
#define an_end_lock(x)							__unix_end_lock(x)
#endif

#if _WIN32
#define an_destroy_lock(x)					__win_destroy_lock(x)
#elif LINUX
#define an_destroy_lock(x)						__unix_destroy_lock(x)
#endif


#define __win_init_lock(x)					0
#define __win_lock(x)						0
#define __win_end_lock(x)					0
#define __win_destroy_lock(x)				0

#define __unix_init_lock(x)					pthread_mutex_init(x, null);
#define __unix_lock(x)						pthread_mutex_lock(x);
#define __unix_end_lock(x)					pthread_mutex_unlock(x);
#define __unix_destroy_lock(x)				pthread_mutex_destroy(x);*/



#define an_init_sync()						boost::mutex __an_mtx
#define an_sync()							__an_mtx.lock()
#define an_end_sync()						__an_mtx.unlock()

#define an_lock(x)							x->mutex.lock()
#define an_end_lock(x)						x->mutex.unlock()
//#define an_destroy_lock()					__win_destroy_lock(x)