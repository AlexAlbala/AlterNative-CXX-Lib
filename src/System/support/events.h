#pragma once

/*********************************************************************************************************/
/************************************************ EVENTS  ************************************************/
/*********************************************************************************************************/
#define EVENT(name, ...)					__Internal__::_event<__VA_ARGS__> name;

#define EVENT_INIT(del, name)				del* __internal__del = null;											\
											name = __Internal__::Event::CreateEvent(__internal__del)

#define EVENT_FIRE(eventName,...)			eventName.fireEvent(__VA_ARGS__ )