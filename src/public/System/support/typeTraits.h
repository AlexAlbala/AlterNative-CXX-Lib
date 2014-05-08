#pragma once
#include <type_traits>

/*********************************************************************************************************/
/*********************************************** TYPE TRAITS  ********************************************/
/*********************************************************************************************************/
/*
Dereferences the types for template arguments (i.e: List<Object*> is -> List<Object>)
*/
#define TypeArg(T)							typename ::__Internal__::TypeTrait<T, true>::Type

/*
Changes the type of a variable declaration:
	-If the type is a basic type, the type is dereferenced
	-If the type is not a basic type, the type is referenced with an *
*/
#define TypeDecl(T)							typename ::__Internal__::TypeTrait<T,false>::Type

/*
Declares a type boxed using Box<T> format
*/
#define BoxDecl(T)							typename ::__Internal__::Boxing<T, ::__Internal__::IsFundamentalType<T>::result, false>::Type

/*
BOOLEAN: returns if it is a basic type or not
*/
#define IsBasic(T)							::__Internal__::IsFundamentalType<T>::result

/*
BOOLEAN: returns if it is an enum type or not
*/
#define IsEnum(T)							std::is_enum<T>::value

/*********************************************************************************************************/
/*********************************************** VARIADIC  ***********************************************/
/*********************************************************************************************************/
#define VARIADIC_ARGS(...) typedef ::__Internal__::variadic_typedef<__VA_ARGS__>
#define TUPLE_VARIADIC(var) typedef ::__Internal__::convert_in_tuple<var>::type

/*********************************************************************************************************/
/************************************** DLLEXPORT parameter list  ****************************************/
/*********************************************************************************************************/
#define DLL_Array(T)						T*

/*********************************************************************************************************/
/***************************************** INCLUDE TEMPLATES  ********************************************/
/*********************************************************************************************************/
#include "internal/TypeRefs.h"
#include "internal/TypeTraits.h"