#define FULLFILLMAP(numArgs, ...)\
char* _arr_ =  #__VA_ARGS__;\
std::string str = std::string(_arr_);\
std::vector<std::string> tokens;\
boost::algorithm::split(tokens, str, boost::algorithm::is_any_of(","));\
for(int __i=0; __i < numArgs ; __i++){ \
	std::string tmp = tokens[__i];\
	tmp.erase( remove_if(tmp.begin(), tmp.end(), isspace));\
	map->SetData(__i, new String(tmp.data()));\
}

#define STRING_SWITCH(variable, numArgs, ...)\
struct variable##_struct {\
	enum labels { \
		__VA_ARGS__##,\
	};\
	\
	Array<String>* map;\
	\
	variable##_struct(){\
		map = new Array<String>(numArgs);\
		FULLFILLMAP(numArgs, __VA_ARGS__);\
	}\
	\
	int parseString(String* s){\
		for(int i=0; i < map->Length; i++)\
		{\
			String* tmp = map->GetData(i);\
			if(tmp->compare(s->data()) == 0)\
				return i;\
		}\
		return -1;\
	}\
}variable;\
typedef variable##_struct::labels variable##_labels;