#pragma once
#include "internal/Boxing.h"

/*********************************************************************************************************/
/********************************************** BOXING UNBOXING ******************************************/
/*********************************************************************************************************/
/*
Box and UnBox macros for supportin implcit boxing and unboxing from C#
*/
template<typename T>
System::Box_T<T>* BOX(T t){
	return new System::Box_T<T>(t);	
}

template<typename T>
T& UNBOX(System::Object* t){
	System::Box_T<T>* tmp = (System::Box_T<T>*)t;
	return *tmp;
}


/*********************************************************************************************************/
/********************************************** RETURN TEMPLATE ******************************************/
/*********************************************************************************************************/
namespace __Internal__{
	template<typename T, bool isBasic>
	struct objbox
	{
	public:
		static BoxDecl(T) DO(TypeDecl(T) element)
		{
		}
	};

	template<typename T>
	struct objbox<T,true>
	{
		static BoxDecl(T) DO(T element)
		{		
			return BOX<T>((T)(element));
		}
	};

	template<typename T>
	struct objbox<T,false>
	{
		static T* DO(T* element)
		{
			return (element);
		}
	};
}


template<typename T>
BoxDecl(T) OBJBOX(TypeDecl(T) element)
{
	return ::__Internal__::objbox<T, IsBasic(T)>::DO(element);
};
