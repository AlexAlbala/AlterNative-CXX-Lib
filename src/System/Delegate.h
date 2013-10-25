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
			return _target(args...);
		}

		/*operator + (Delegate* other)
		{
			_target.connect(other->_target);
		}

		operator - (Delegate* other)
		{
			_target.disconnect(other->_target);
		}*/
		/*
		Delegate<RType,Arguments...>* operator ()()
		{
			Invoke();
			return this;
		}
		
		Delegate<RType,Arguments...>* operator ()(Arguments... args)
		{
			this->Invoke(args...);
			return this;
		}*/
		
		static Delegate<RType,Arguments...>* Combine(Delegate* one, Delegate* other)
		{
			throw new NotImplementedException();
		}
	};
}
