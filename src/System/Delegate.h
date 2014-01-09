#pragma once
#include <boost/signals2/signal.hpp>
#include "System.h"

namespace __Internal__{
	template<typename A, typename... B>
	class _Delegate;
}

namespace System{
    class Delegate : public Object
    {
	friend class _event;
    public:		    

            template<typename A, typename... B>
            static Delegate* Combine(__Internal__::_Delegate<A,B...>* one, __Internal__::_Delegate<A,B...>* other)
            {                        
				if(one == null)
					one = new __Internal__::_Delegate<A,B...>();

				one->CombineWith(other);
                return one;                
            }

			template<typename A, typename... B>
            static Delegate* Combine(__Internal__::_Delegate<A,B...>* one, const __Internal__::_Delegate<A,B...>* other)
            {
				if(one == null)
					one = new __Internal__::_Delegate<A,B...>();

                one->CombineWith(other);
                return one;                
            }

			template<typename A, typename... B>
            static Delegate* Remove(__Internal__::_Delegate<A,B...>* one, __Internal__::_Delegate<A,B...>* other)
            {                        
                one->Remove(other);
                return one;
            }

			template<typename A, typename... B>
            static Delegate* Remove(__Internal__::_Delegate<A,B...>* one, const __Internal__::_Delegate<A,B...>* other)
            {                        
                one->Remove(other);
                return one;
			}

			template<typename A, typename... B>
			bool Equals(__Internal__::_Delegate<A,B...>* one)
			{
				__Internal__::_Delegate<A,B...>* me = (__Internal__::_Delegate<A,B...>*)this;
				return &(one->_target) == &(me->_target);
			}
    };
}

    namespace __Internal__{
            template<typename RType, typename... Arguments>
            class _Delegate : public System::Delegate
            {			
            public:
                boost::signals2::signal<TypeDecl(RType) (Arguments ...)> _target;
            public:
                _Delegate()
                {                    
                }
                
                _Delegate(boost::function<TypeDecl(RType) (Arguments ...)> target)
                {
                    this->_target.connect(target);
                }

				void CombineWith(_Delegate* other)
				{
					_target.connect(&other->_target);
				}

				void Remove(_Delegate* other)
				{
					_target.disconnect(&other->_target);
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
                boost::signals2::signal<void (Arguments ...)> _target;
            public:
                _Delegate()
                {                        
                }
                
                _Delegate(boost::function<void (Arguments ...)> target)
                {
                    this->_target.connect(target);							
                }

				void CombineWith(_Delegate* other)
				{
					_target.connect(other->_target);
				}

				void Remove(_Delegate* other)
				{
					_target.disconnect(&other->_target);
				}
                
                void Invoke(Arguments... args)
                {        
                    this->_target(args...);
                }
            };			
    }