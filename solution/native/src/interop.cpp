
#include "stdafx.h"
#include <vcclr.h>
#include "interop.h"


using namespace System::Runtime::InteropServices;
using namespace reexmonkey::xinterop::services;


const std::string InteropService::ToNativeAnsiString(String ^ s)
{
	auto strIntPtr = Marshal::StringToHGlobalAnsi(s);
	auto cstr = static_cast<const char*>(strIntPtr.ToPointer());
	//create std::string from str;
	std::string converted(cstr);

	//free resources
	Marshal::FreeHGlobal(strIntPtr);
	return converted;
}

const std::wstring InteropService::ToNativeUnicodeString(String ^ s)
{
	pin_ptr<const wchar_t> str = PtrToStringChars(s);
	std::wstring ws(str);
	return ws;
}

std::vector<char> InteropService::ToNativeAnsiChars(String ^ s)
{
	auto strIntPtr = Marshal::StringToHGlobalAnsi(s);
	auto cstr = static_cast<const char*>(strIntPtr.ToPointer());
	std::vector<char> writable(cstr, cstr + strlen(cstr));
	writable.push_back('\0');
	//free resources
	Marshal::FreeHGlobal(strIntPtr);
	return writable;

}

String ^ InteropService::FromNativeAnsiChars(std::vector<char> chars)
{
	std::string s (chars.begin(), chars.end());
	return gcnew String(s.c_str());
}

std::vector<wchar_t> InteropService::ToNativeUnicodeChars(String ^ s)
{
	pin_ptr<const wchar_t> str = PtrToStringChars(s);
	std::wstring ws(str);
	std::vector<wchar_t> writable(ws.begin(), ws.end());
	writable.push_back('\0');
	return writable;
}

String ^ InteropService::FromNativeUnicodeChars(std::vector<wchar_t> wchars)
{
	std::wstring w(wchars.begin(), wchars.end());
	return gcnew String(w.c_str());
}

String ^ InteropService::FromNativeAnsiString(const std::string & s)
{
	return gcnew String(s.c_str());
}

String ^ InteropService::FromNativeUnicodeString(const std::wstring & s)
{
	return gcnew String(s.c_str());
}

IntPtr InteropService::ToIntPtr(Object ^ object, GCHandle% handle)
{
	handle = GCHandle::Alloc(object);
	return GCHandle::ToIntPtr(handle);
}

Object ^ InteropService::FromIntPtr(IntPtr ptr)
{
	GCHandle handle = GCHandle::FromIntPtr(ptr);
	return ptr != IntPtr::Zero
		? handle.Target
		: nullptr;
}