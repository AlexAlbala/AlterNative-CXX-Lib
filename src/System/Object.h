#pragma once
#include "../gc/include/gc_cpp.h"

namespace System{
	
	//Forward declarations
	template<typename T>
	class Box_T;

	//Forward declarations
	class String;
	
	class Object : public gc_cleanup
	{		
	public:
		Object(void);
		~Object(void);
		virtual String* ToString(void);
		
		//boost::mutex mutex;
	};
}

#include "String.h"

namespace System{

	template <typename T>
	class Box_T : public Object {
	private:
		T data;
	public:	
		Box_T(T t) : data(t) {
		}

		Box_T(T* t) : data(*t) {
		}

		operator T () {
			return data;
		}

		operator T& () {
			return data;
		}

		operator Box_T<T>* () {
			return new Box_T<T>(data);
		}

		operator Box_T<T>& () {
			return Box_T<T>(data);
		}

		T operator =(Box_T<T>  other){
			return data;
		}

		Box_T<T>& operator =(T other){
			return Box_T<T>(other);
		}

		virtual String* ToString(){
			String* s = new String(data);
			return s;
		}
	};
}
