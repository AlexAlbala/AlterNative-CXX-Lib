#pragma once
#include <boost/signals2/signal.hpp>

using namespace boost::signals2;
namespace System{
	template<typename RType, typename... Arguments>
	class Delegate
	{
	private:
		signal<TypeDecl(RType) (Arguments ...)> _target;	
		

	public:
		Delegate()
		{
			_target();
		}
		
		Delegate(boost::function<TypeDecl(RType) (Arguments ...)> target)
		{
			_target.connect(target);
		}

		
		TypeDecl(RType) Invoke(Arguments... args)
		{	
			boost::optional<TypeDecl(RType)> opt = _target(args...);
			return opt.get_value_or(null);
		}
	
		static Delegate* Combine(Delegate* one, Delegate* other)
		{
			one->_target.connect(other->_target);
			return one;
		}
	};
	
	template<typename... Arguments>
	class Delegate<void, Arguments...>
	{
	private:
		signal<void (Arguments ...)> _target;	
		

	public:
		Delegate()
		{
			_target();
		}
		
		Delegate(boost::function<void (Arguments ...)> target)
		{
			_target.connect(target);
		}

		
		void Invoke(Arguments... args)
		{	
			_target(args...);
		}
	
		static Delegate* Combine(Delegate* one, Delegate* other)
		{
			one->_target.connect(other->_target);
			return one;
		}
	};
}
