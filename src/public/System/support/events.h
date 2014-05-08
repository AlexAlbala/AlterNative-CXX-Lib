#pragma once

/*********************************************************************************************************/
/************************************************ EVENTS  ************************************************/
/*********************************************************************************************************/
#define EVENT(name, ...)					::System::__Internal__::_event<__VA_ARGS__> name;

#define EVENT_INIT(del, name)				del* __internal__del = null;											\
											name = ::System::Event::CreateEvent(__internal__del)

#define EVENT_FIRE(eventName,...)			eventName.fireEvent(__VA_ARGS__ )