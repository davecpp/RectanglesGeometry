#pragma once
#include "Defines.h"


BEGIN_GEOMETRY
template<typename _Ret, typename _Ty>
_Ret geometry_cast(_Ty t) {
	static_assert("please specialize this template for your geometry objects");
}
END_GEOMETRY
