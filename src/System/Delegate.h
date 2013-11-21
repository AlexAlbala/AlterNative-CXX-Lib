#pragma once
#include <boost/signals2/signal.hpp>
#include "System.h"

namespace __Internal__{
	template<typename A, typename... B>
	class _Delegate;
}

namespace System{
    class Delegate
    {
	friend class _event;
    public:		    

            template<typename A, typename... B>
            static Delegate* Combine(__Internal__::_Delegate<A,B...>* one, __Internal__::_Delegate<A,B...>* other)
            {                        
                    one->_target.connect(other->_target);
                    return one;                
            }

			template<typename A, typename... B>
            static Delegate* Combine(__Internal__::_Delegate<A,B...>* one, const __Internal__::_Delegate<A,B...>* other)
            {                        
                    one->_target.connect(other->_target);
                    return one;                
            }
                
    };
}

using namespace boost::signals2;
    namespace __Internal__{
            template<typename RType, typename... Arguments>
            class _Delegate : public System::Delegate
            {
            public:
                    signal<TypeDecl(RType) (Arguments ...)> _target;        
                

            public:
                    _Delegate()
                    {
                            this->_target();
                    }
                
                    _Delegate(boost::function<TypeDecl(RType) (Arguments ...)> target)
                    {
                            this->_target.connect(target);
                    }

                
                    TypeDecl(RType) Invoke(Arguments... args)
                    {        
                            boost::optional<TypeDecl(RType)> opt = this->_target(args...);
                            return opt.get_value_or(null);
                    }
            };
        
            template<typename... Arguments>
            class _Delegate<void, Arguments...> : public System::Delegate
            {
            public:
                    signal<void (Arguments ...)> _target;        
                

            public:
                    _Delegate()
                    {
                            this->_target();
                    }
                
                    _Delegate(boost::function<void (Arguments ...)> target)
                    {
                            this->_target.connect(target);							
                    }
                
                    void Invoke(Arguments... args)
                    {        
                            this->_target(args...);
                    }
            };
    }
