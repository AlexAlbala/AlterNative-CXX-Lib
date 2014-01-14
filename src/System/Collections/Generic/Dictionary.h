#pragma once
#include "IEnumerable.h"
#include <stdlib.h>
#include <map>
#include <utility>

#ifdef _MSC_VER
#define MAP_KV map
#else
#define MAP_KV map<TypeDecl(KeyT),TypeDecl(ValueT)>
#endif

using namespace std;
namespace System{
	namespace Collections{
		namespace Generic{
			template<typename KeyT, typename ValueT>
			class Dictionary_T : private map<TypeDecl(KeyT),TypeDecl(ValueT)>, public Object
			{
				public:
				int Count;

				Dictionary_T() : MAP_KV()
				{
					Count = 0;
				}
			
				Dictionary_T(Dictionary_T<KeyT, ValueT>* dictionary) : MAP_KV()
				{
					for(int i=0; i<dictionary->Count;i++)
					{
						TypeDecl(KeyT) key = dictionary->keys[i];
						TypeDecl(ValueT) val = dictionary->values[i];
						this->Add(key,val);
					}					
				}
			
				~Dictionary_T()
				{
					MAP_KV::clear();
				}				
			
				inline void Add(TypeDecl(KeyT) key, TypeDecl(ValueT) value)
				{
#ifdef _MSC_VER
					MAP_KV::emplace(key, value);
#else
					pair<TypeDecl(KeyT), TypeDecl(ValueT)> mpair(key, value);
					map<TypeDecl(KeyT),TypeDecl(ValueT)>::insert(mpair);
#endif
					Count++;
				}

				inline void SetData(TypeDecl(KeyT) key, TypeDecl(ValueT) value)
				{	
					MAP_KV::at(key) = value;
				}

				inline bool ContainsKey(TypeDecl(KeyT) key)
				{
					return MAP_KV::find(key) != MAP_KV::end();
				}

				inline void Remove(TypeDecl(KeyT) key)
				{
					MAP_KV::erase(key);
					Count--;
				}

				inline TypeDecl(ValueT)& operator[](TypeDecl(KeyT) key)
				{					
					return MAP_KV::at(key);
				}

				inline void Clear()
				{
					MAP_KV::clear();
					Count = 0;
				}

				bool TryGetValue(TypeDecl(KeyT) key, ValueT& value)
				{
					if(ContainsKey(key))
					{
						value = MAP_KV::at(key);
						return true;
					}
					else					
					{
						value = null;
						return false;
					}					
				}
			};
		}
	}
}