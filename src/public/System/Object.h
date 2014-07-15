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
		virtual int GetHashCode();
		
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

		template <typename T, bool isEnum, bool isBasic, bool isStruct>
		class __box_t{
			__box_t(T t)
			{
				//static_assert(false, "Invalid box template arguments");
				throw exception("Invalid box template arguments");
			}

			__box_t(T* t)
			{
				//static_assert(false, "Invalid box template arguments");
				throw exception("Invalid box template arguments");
			}
		};

		//Enum inside a box
		template <typename T>
		class __box_t<T, true, false, false> : public __box_t_base<T>{	
		public:
			__box_t(T t) : __box_t_base<T>(t){};
			__box_t(T* t) : __box_t_base<T>(t){};

			String* ToString()
			{
				//TODO: Use boost to extract the label of the enum
				return new String("Enum");
			}
		};

		//Primitive type inside a box
		template <typename T>
		class __box_t<T, false, true, false>  : public __box_t_base<T>{
		public:
			 __box_t(T t) : __box_t_base<T>(t){};
			 __box_t(T* t) : __box_t_base<T>(t){};

			String* ToString()
			{
				String* s = new String(__box_t_base<T>::data);
				return s;
			}
		};

		//Struct type inside a box
		template <typename T>
		class __box_t<T, false, false, true>  : public __box_t_base<T>{
		public:
			 __box_t(T t) : __box_t_base<T>(t){};
			 __box_t(T* t) : __box_t_base<T>(t){};

			String* ToString()
			{
				String* s = __box_t_base<T>::data.ToString();
				return s;
			}
		};

		//Is an Object inside a Box (i.e DateTime)
		template <typename T>
		class __box_t<T, false, false, false>  : public __box_t_base<T>{
		public:
			 __box_t(T t) : __box_t_base<T>(t){};
			 __box_t(T* t) : __box_t_base<T>(t){};

			String* ToString()
			{
				String* s = __box_t_base<T>::data->ToString();
				return s;
			}
		};
	}
	
	template <typename T>
	class Box_T : public __Internal__::__box_t<T, IsEnum(T), IsBasic(T), IsStruct(T)> {
	public:
		Box_T(T t) : __Internal__::__box_t<T, IsEnum(T), IsBasic(T), IsStruct(T)>(t){};
		Box_T(T* t) : __Internal__::__box_t<T, IsEnum(T), IsBasic(T), IsStruct(T)>(t){};
	};
}
