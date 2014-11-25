
#include "stdafx.h"

#include "transformers.h"

//Implementation of reexmonkey.xinterop.infrastructure.concretes.InteropExtensions

namespace xs = reexmonkey::xinterop::infrastructure::concrete;
namespace interop = System::Runtime::InteropServices;

const std::string xs::InteropExtensions::ToNativeString(String^ s)
{
	auto str = (const char*)(interop::Marshal::StringToHGlobalAnsi(s).ToPointer());
	//create std::string from str;
	std::string converted(str);
	//free resources
	interop::Marshal::FreeHGlobal(IntPtr((void*)str));
	return converted;
}


String^ xs::InteropExtensions::ToManagedString(const std::string& s)
{
	return gcnew String(s.c_str());
}