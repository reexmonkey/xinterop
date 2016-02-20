
#include "stdafx.h"
#include <vcclr.h>
#include <codecvt>
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

const std::wstring InteropService::ToNativeWideString(String ^ s)
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

std::vector<wchar_t> InteropService::ToNativeWideChars(String^ s)
{
	pin_ptr<const wchar_t> str = PtrToStringChars(s);
	std::wstring ws(str);
	std::vector<wchar_t> writable(ws.begin(), ws.end());
	writable.push_back('\0');
	return writable;
}

String ^ InteropService::FromNativeWideChars(std::vector<wchar_t> wchars)
{
	std::wstring w(wchars.begin(), wchars.end());
	return gcnew String(w.c_str());
}



#if _MSC_PLATFORM_TOOLSET == 140

std::utf16string InteropService::ToNativeUtf16String(String ^ s)
{
	auto strIntPtr = Marshal::StringToHGlobalAnsi(s);
	auto cstr = static_cast<const char*>(strIntPtr.ToPointer());

	std::string utf8(cstr);
	std::wstring_convert<std::codecvt_utf8_utf16<uint16_t>, uint16_t> convert;
	std::utf16string u16string = convert.from_bytes(utf8);

	//free resources
	Marshal::FreeHGlobal(strIntPtr);
	return u16string;

}

String ^ InteropService::FromNativeUtf16String(std::utf16string utf16)
{
	std::wstring_convert<std::codecvt_utf8_utf16<uint16_t>, uint16_t> convert;
	std::string utf8 = convert.to_bytes(utf16);
	return gcnew String(utf8.c_str());
}

std::utf32string InteropService::ToNativeUtf32String(String ^ s)
{
	auto strIntPtr = Marshal::StringToHGlobalAnsi(s);
	auto cstr = static_cast<const char*>(strIntPtr.ToPointer());

	std::string utf8(cstr);
	std::wstring_convert<std::codecvt_utf8<uint32_t>, uint32_t> convert;
	std::utf32string utf32 = convert.from_bytes(utf8);

	//free resources
	Marshal::FreeHGlobal(strIntPtr);
	return utf32;
}

String ^ InteropService::FromNativeUtf32String(std::utf32string utf32)
{
	std::wstring_convert<std::codecvt_utf8_utf16<uint32_t>, uint32_t> convert;
	std::string utf8 = convert.to_bytes(utf32);
	return gcnew String(utf8.c_str());
}

std::vector<uint16_t> InteropService::ToNativeUtf16Chars(String ^ s)
{
	auto strIntPtr = Marshal::StringToHGlobalAnsi(s);
	auto cstr = static_cast<const char*>(strIntPtr.ToPointer());

	std::string utf8(cstr);
	std::wstring_convert<std::codecvt_utf8_utf16<uint16_t>, uint16_t> convert;
	std::utf16string u16string = convert.from_bytes(utf8);
	std::vector<uint16_t> writable(u16string.begin(), u16string.end());

	//free resources
	Marshal::FreeHGlobal(strIntPtr);
	return writable;
}

String ^ InteropService::FromNativeUtf16Chars(std::vector<uint16_t> utf16)
{
	std::wstring w(utf16.begin(), utf16.end());
	return gcnew String(w.c_str());
}

std::vector<uint32_t> InteropService::ToNativeUtf32Chars(String ^ s)
{
	auto strIntPtr = Marshal::StringToHGlobalAnsi(s);
	auto cstr = static_cast<const char*>(strIntPtr.ToPointer());

	std::string utf8(cstr);
	std::wstring_convert<std::codecvt_utf8_utf16<uint32_t>, uint32_t> convert;
	std::utf32string utf32 = convert.from_bytes(utf8);
	std::vector<uint32_t> writable(utf32.begin(), utf32.end());

	//free resources
	Marshal::FreeHGlobal(strIntPtr);
	return writable;
}

String ^ InteropService::FromNativeUtf32Chars(std::vector<uint32_t> utf32)
{
	std::wstring w(utf32.begin(), utf32.end());
	return gcnew String(w.c_str());
}

#else

std::u16string InteropService::ToNativeUtf16String(String ^ s)
{
	auto strIntPtr = Marshal::StringToHGlobalAnsi(s);
	auto cstr = static_cast<const char*>(strIntPtr.ToPointer());

	std::string utf8(cstr);
	std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> convert;
	std::u16string u16string = convert.from_bytes(utf8);

	//free resources
	Marshal::FreeHGlobal(strIntPtr);
	return u16string;

}

String ^ InteropService::FromNativeUtf16String(std::u16string utf16)
{
	std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> convert;
	std::string utf8 = convert.to_bytes(utf16);
	return gcnew String(utf8.c_str());
}

std::u32string InteropService::ToNativeUtf32String(String ^ s)
{
	auto strIntPtr = Marshal::StringToHGlobalAnsi(s);
	auto cstr = static_cast<const char*>(strIntPtr.ToPointer());

	std::string utf8(cstr);
	std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> convert;
	std::u32string utf32 = convert.from_bytes(utf8);

	//free resources
	Marshal::FreeHGlobal(strIntPtr);
	return utf32;
}

String ^ InteropService::FromNativeUtf32String(std::u32string utf32)
{
	std::wstring_convert<std::codecvt_utf8_utf16<char32_t>, char32_t> convert;
	std::string utf8 = convert.to_bytes(utf32);
	return gcnew String(utf8.c_str());
}

std::vector<char16_t> InteropService::ToNativeUtf16Chars(String ^ s)
{
	auto strIntPtr = Marshal::StringToHGlobalAnsi(s);
	auto cstr = static_cast<const char*>(strIntPtr.ToPointer());

	std::string utf8(cstr);
	std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> convert;
	std::u16string u16string = convert.from_bytes(utf8);

	std::vector<char16_t> writable(u16string.begin(), u16string.end());

	//free resources
	Marshal::FreeHGlobal(strIntPtr);
	return writable;
}

String ^ InteropService::FromNativeUtf16Chars(std::vector<char16_t> utf16)
{
	std::wstring w(utf16.begin(), utf16.end());
	return gcnew String(w.c_str());
}

std::vector<char32_t> InteropService::ToNativeUtf32Chars(String ^ s)
{
	auto strIntPtr = Marshal::StringToHGlobalAnsi(s);
	auto cstr = static_cast<const char*>(strIntPtr.ToPointer());

	std::string utf8(cstr);
	std::wstring_convert<std::codecvt_utf8_utf16<char32_t>, char32_t> convert;
	std::u32string utf32 = convert.from_bytes(utf8);

	std::vector<char32_t> writable(utf32.begin(), utf32.end());

	//free resources
	Marshal::FreeHGlobal(strIntPtr);
	return writable;
}

String ^ InteropService::FromNativeUtf32Chars(std::vector<char32_t> utf32)
{
	std::wstring w(utf32.begin(), utf32.end());
	return gcnew String(w.c_str());
}


#endif // _MSC_VER == 1900


String ^ InteropService::FromNativeAnsiString(const std::string & s)
{
	return gcnew String(s.c_str());
}

String ^ InteropService::FromNativeWideString(const std::wstring & s)
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