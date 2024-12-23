#include "Object.h"

std::ostream& operator << (std::ostream& str, const Object& obj) {
	str << obj.GetType() << std::endl;
	obj.Print(str);
	return str;
}