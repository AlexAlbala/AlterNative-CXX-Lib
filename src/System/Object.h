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
	namespace __Internal__{
		template<typename T>
		class __box_t_base : public Object
		{		
		protected:
			T data;
		public:	
			__box_t_base(T t) : data(t) {
			}

			__box_t_base(T* t) : data(*t) {
			}

			operator T () {
				return data;
			}

			operator T& () {
				return data;
			}

			operator __box_t_base* () {
				return new __box_t_base<T>(data);
			}

			operator __box_t_base& () {
				return __box_t_base<T>(data);
			}

			T operator =(__box_t_base  other){
				return data;
			}

			__box_t_base& operator =(T other){
				return __box_t_base<T>(other);
			}		
		};

		template <typename T, bool isEnum>
		class __box_t{		
		};

		template <typename T>
		class __box_t<T, true> : public __box_t_base<T>{	
		public:
			__box_t(T t) : __box_t_base<T>(t){};
			__box_t(T* t) : __box_t_base<T>(t){};

			String* ToString()
			{
				return new String("Enum");
			}
		};

		template <typename T>
		class __box_t<T, false>  : public __box_t_base<T>{
		public:
			 __box_t(T t) : __box_t_base<T>(t){};
			 __box_t(T* t) : __box_t_base<T>(t){};

			String* ToString()
			{
				String* s = new String(__box_t_base<T>::data);
				return s;
			}
		};
	}
	
	template <typename T>
	class Box_T : public __Internal__::__box_t<T, IsEnum(T)> {
	public:
		Box_T(T t) : _Internal_::__box_t<T, IsEnum(T)>(t){};
		Box_T(T* t) : _Internal_::__box_t<T, IsEnum(T)>(t){};
	};
}
