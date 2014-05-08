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

#define an_init_sync()						boost::mutex __an_mtx
#define an_sync()							__an_mtx.lock()
#define an_end_sync()						__an_mtx.unlock()

#define an_lock(x)							x->mutex.lock()
#define an_end_lock(x)						x->mutex.unlock()
//#define an_destroy_lock()					__win_destroy_lock(x)