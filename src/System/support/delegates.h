#pragma once

/*********************************************************************************************************/
/********************************************** DELEGATES  ***********************************************/
/*********************************************************************************************************/
#define DELEGATE(type,...)					typedef __Internal__::_Delegate<type, ##__VA_ARGS__>
#define DELEGATE_FUNC(func, ...)			boost::bind(&func, this,##__VA_ARGS__)
#define DELEGATE_METHOD(method, ...)		&method, __VA_ARGS__
#define DELEGATE_INVOKE(del, ...)			del->Invoke( __VA_ARGS__ )