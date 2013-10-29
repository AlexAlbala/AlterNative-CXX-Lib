#pragma once
#include <boost/signals2/signal.hpp>

using namespace boost::signals2;
namespace System{
	namespace __Internal__{
		template<typename RType, typename... Arguments>
		class _Delegate
		{
		public:
			signal<TypeDecl(RType) (Arguments ...)> _target;	
		

		public:
			_Delegate()
			{
				_target();
			}
		
			_Delegate(boost::function<TypeDecl(RType) (Arguments ...)> target)
			{
				_target.connect(target);
			}

		
			TypeDecl(RType) Invoke(Arguments... args)
			{	
				boost::optional<TypeDecl(RType)> opt = _target(args...);
				return opt.get_value_or(null);
			}
		};
	
		template<typename... Arguments>
		class _Delegate<void, Arguments...> : public Delegate
		{
		public:
			signal<void (Arguments ...)> _target;	
		

		public:
			_Delegate()
			{
				_target();
			}
		
			_Delegate(boost::function<void (Arguments ...)> target)
			{
				_target.connect(target);
			}

		
			void Invoke(Arguments... args)
			{	
				_target(args...);
			}	
		
		};
	}

	class Delegate
	{
	public:
		template<typename A, typename... B>
		static Delegate* Combine(__Internal__::_Delegate<A,B...>* one, __Internal__::_Delegate<A,B...>* other)
		{			
			one->_target.connect(other->_target);
			return one;		
		}
		
	};
}
