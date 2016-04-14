// iterator example

#pragma once

#include <iostream>
#include <iterator>
#include "IEnumeratorCXX.h"

using namespace std;

namespace System{
	namespace Collections{
		namespace Generic{

			template<typename T> 
			class iteratorcxx : public iterator<input_iterator_tag, T>
			{
			private:
			//T* p;
			IEnumerator_T<T> *it;
			char is_end_iterator;
			char is_end;
			public:
				iteratorcxx(IEnumerator_T<T> *_it){
					this->it = _it;
					this->is_end_iterator = 0;
					this->is_end = 0;
				}
			
				iteratorcxx(int n){
					if(!n)
						this->is_end_iterator = 1;
				}
			
				T* operator()(){
					return it->getCurrent();
				}

				T& operator*(){
					return *(it->getCurrent());
				}
			
				iteratorcxx& operator++(){
					is_end = !it->MoveNext();
					return *this;
				}
			
				iteratorcxx operator++(int){
					is_end = !it->MoveNext();
					return *this;
				}
				
				iteratorcxx operator+(int value){
				for(int i=0; i < value;i++)
					is_end = !it->MoveNext();
			
				return *this;
				}
			
				iteratorcxx operator+=(int value){	
					return operator+(value);
				}
			
				bool operator==(const iteratorcxx& rhs){
                    if(!(rhs.is_end) && !(this->is_end)) {
                        throw "One iterator MUST be at end!";
                    } else {
						if(rhs.is_end_iterator)
							return this->is_end;
						else
							return rhs.is_end;
					}
				}
			
				bool operator!=(const iteratorcxx& rhs){
					return !(operator==(rhs));
				}
			};
		}
	}
}
