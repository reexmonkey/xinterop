
#pragma once

//unamanaged references
#include <string>
#include <vector>

using namespace System;
using namespace System::Runtime::InteropServices;

#if _MSC_PLATFORM_TOOLSET == 140

namespace std
{
	typedef std::basic_string<unsigned short, std::char_traits<unsigned short>, std::allocator<unsigned short> > utf16string;
	typedef std::basic_string<unsigned int, std::char_traits<unsigned int>, std::allocator<unsigned int> > utf32string;

}
#endif


namespace reexmonkey
{
	namespace xinterop 
	{
		namespace services
		{
			/// <summary>
			/// Service class to provide conversion features between managed and native types.
			/// </summary>
			public ref class InteropService abstract sealed
			{
			public:
				/// <summary>
				/// Converts a managed UTF-16 string to a corresponding native ANSI string.
				/// Use this method when you wish to pass a managed string safely to a native function or string.
				/// This method indicates to the garbage collector not to move the referenced mangaed string during clean up operations.
				/// </summary>
				/// <param name="s">The managed string to be converted.</param>
				/// <returns>The equivalent native string from the conversion.</returns>
				static const std::string ToNativeAnsiString(String^ s);

				/// <summary>
				/// Converts a native ANSI string to corresponding managed string.
				/// Use this method when you want to pass a native string to a managed function or managed string. 
				/// </summary>
				/// <param name="s">The native string to be converted.</param>
				/// <returns>The equivalent managed UTF-16 string from the conversion.</returns>
				static String^ FromNativeAnsiString(const std::string& s);

				/// <summary>
				/// Converts a managed UTF-16 string to a corresponding native wide character string.
				/// Use this method when you wish to pass a managed string safely to a native function or string.
				/// This method also indicates to the garbage collector not to move the referenced managed string reference during clean up operations.
				/// </summary>
				/// <param name="s"></param>
				/// <returns>The equivalent native wide character string from the conversion.</returns>
				static const std::wstring ToNativeWideString(String^ s);

				/// <summary>
				/// Converts a native wide-character string to a managed UTF-16 string.
				/// Use this method when you want to pass a native wide-character string to a managed function or managed string. 
				/// </summary>
				/// <param name="s">The wide-character string to be converted.</param>
				/// <returns>The equivalent managed UTF-16 string from the conversion</returns>
				static String^ FromNativeWideString(const std::wstring& s);

				/// <summary>
				///  Converts a managed UTF-16 string to a native fixed array of ANSI characters.
				///  Use this method, when you want to pass a managed UTF-16 string to a native function that requires a native fixed array of ANSI characters.
				/// </summary>
				/// <param name="s">The managed UTF-16 string to be converted.</param>
				/// <returns>The equivalent fixed array of ANSI characters.</returns>
				static std::vector<char> ToNativeAnsiChars(String^ s);

				/// <summary>
				/// Converts a native fixed array of ANSI characters to a managed UTF-16 string.
				/// Use this method when you want to pass a native fixed array of ANSI characters to a managed function or managed string. 
				/// </summary>
				/// <param name="chars">The native fixed array of ANSI characters to be converted.</param>
				/// <returns>The equivalent managed UTF-16 string from the conversion.</returns>
				static String^ FromNativeAnsiChars(std::vector<char> chars);


				/// <summary>
				/// Converts a managed UTF-16 string to a native fixed array of wide characters.
				/// Use this method, when you want to pass a managed UTF-16 string to a native function that requires a native fixed array of native wide characters.
				/// </summary>
				/// <param name="s">The managed UTF-16 string to be converted.</param>
				/// <returns>The equivalent fixed array of wide characters.</returns>
				static std::vector<wchar_t> ToNativeWideChars(String^ s);

				/// <summary>
				/// Converts a native fixed array of wide characters to a managed UTF-16 string.
				/// Use this method when you want to pass a native fixed array of wide characters to a managed function or managed string. 
				/// </summary>
				/// <param name="wchars">The native fixed array of wide characters to be converted.</param>
				/// <returns>The equivalent managed UTF-16 string from the conversion.</returns>
				static String^ FromNativeWideChars(std::vector<wchar_t> wchars);

				#if _MSC_PLATFORM_TOOLSET == 140

				/// <summary>
				/// Converts a managed UTF-16 string to a native UTF-16 string.
				/// Use this method, when you want to pass a managed UTF-16 string to a native function or native UTF-16 string.
				/// </summary>
				/// <param name="s">The managed UTF-16 string to be converted.</param>
				/// <returns>The equivalent native native UTF-16 string.</returns>
				static std::utf16string ToNativeUtf16String(String^ s);

				/// <summary>
				/// Converts a native UTF-16 string to a managed UTF-16 string.
				/// Use this method when you want to pass a native UTF-16 string to a managed function or managed string. 
				/// </summary>
				/// <param name="utf16">The native UTF-16 string to be converted.</param>
				/// <returns>The equivalent managed UTF-16 string from the conversion.</returns>
				static String^ FromNativeUtf16String(std::utf16string utf16);


				/// <summary>
				/// Converts a managed UTF-32 string to a native UTF-32 string.
				/// Use this method, when you want to pass a managed UTF-32 string to a native function or native UTF-32 string.
				/// </summary>
				/// <param name="s">The managed UTF-32 string to be converted.</param>
				/// <returns>The equivalent native native UTF-32 string.</returns>
				static std::utf32string ToNativeUtf32String(String^ s);


				/// <summary>
				/// Converts a native UTF-32 string to a managed UTF-32 string.
				/// Use this method when you want to pass a native UTF-32 string to a managed function or managed string. 
				/// </summary>
				/// <param name="utf32">The native UTF-32 string to be converted.</param>
				/// <returns>The equivalent managed UTF-32 string from the conversion.</returns>
				static String^ FromNativeUtf32String(std::utf32string utf32);


				/// <summary>
				/// Converts a managed UTF-16 string to a native fixed array of native UTF-16 characters.
				/// Use this method, when you want to pass a managed UTF-16 string to a native function that requires a native fixed array of native UTF-16 characters.
				/// </summary>
				/// <param name="s">The managed UTF-16 string to be converted.</param>
				/// <returns>The equivalent fixed array of native UTF-16 characters.</returns>
				static std::vector<unsigned short> ToNativeUtf16Chars(String^ s);

				/// <summary>
				/// Converts a native fixed array of native UTF-32 characters to a managed UTF-16 string.
				/// Use this method when you want to pass a native array of UTF-16 characters to a managed function or managed string. 
				/// </summary>
				/// <param name="utf16">The native fixed array of native UTF-16 characters to be converted.</param>
				/// <returns>The equivalent managed UTF-16 string from the conversion.</returns>
				static String^ FromNativeUtf16Chars(std::vector<unsigned short> utf16);

				/// <summary>
				/// Converts a managed UTF-16 string to a native fixed array of native UTF-32 characters.
				/// Use this method, when you want to pass a managed UTF-16 string to a native function that requires a native fixed array of native UTF-32 characters.
				/// </summary>
				/// <param name="s">The managed UTF-16 string to be converted.</param>
				/// <returns>The equivalent fixed array of native UTF-32 characters.</returns>
				static std::vector<unsigned int> ToNativeUtf32Chars(String^ s);

				/// <summary>
				/// Converts a native fixed array of native UTF-32 characters to a managed UTF-16 string.
				/// Use this method when you want to pass a native array of UTF-32 characters to a managed function or managed string. 
				/// </summary>
				/// <param name="utf32">The native fixed array of native UTF-32 characters to be converted.</param>
				/// <returns>The equivalent managed UTF-32 string from the conversion.</returns>
				static String^ FromNativeUtf32Chars(std::vector<unsigned int> utf32);

				#else

				/// <summary>
				/// Converts a managed UTF-16 string to a native UTF-16 string.
				/// Use this method, when you want to pass a managed UTF-16 string to a native function or native UTF-16 string.
				/// </summary>
				/// <param name="s">The managed UTF-16 string to be converted.</param>
				/// <returns>The equivalent native native UTF-16 string.</returns>
				static std::u16string ToNativeUtf16String(String^ s);

				/// <summary>
				/// Converts a native UTF-16 string to a managed UTF-16 string.
				/// Use this method when you want to pass a native UTF-16 string to a managed function or managed string. 
				/// </summary>
				/// <param name="utf16">The native UTF-16 string to be converted.</param>
				/// <returns>The equivalent managed UTF-16 string from the conversion.</returns>
				static String^ FromNativeUtf16String(std::u16string utf16);


				/// <summary>
				/// Converts a managed UTF-32 string to a native UTF-32 string.
				/// Use this method, when you want to pass a managed UTF-32 string to a native function or native UTF-32 string.
				/// </summary>
				/// <param name="s">The managed UTF-32 string to be converted.</param>
				/// <returns>The equivalent native native UTF-32 string.</returns>
				static std::u32string ToNativeUtf32String(String^ s);


				/// <summary>
				/// Converts a native UTF-32 string to a managed UTF-32 string.
				/// Use this method when you want to pass a native UTF-32 string to a managed function or managed string. 
				/// </summary>
				/// <param name="utf32">The native UTF-32 string to be converted.</param>
				/// <returns>The equivalent managed UTF-32 string from the conversion.</returns>
				static String^ FromNativeUtf32String(std::u32string utf32);

				/// <summary>
				/// Converts a managed UTF-16 string to a native fixed array of native UTF-16 characters.
				/// Use this method, when you want to pass a managed UTF-16 string to a native function that requires a native fixed array of native UTF-16 characters.
				/// </summary>
				/// <param name="s">The managed UTF-16 string to be converted.</param>
				/// <returns>The equivalent fixed array of native UTF-16 characters.</returns>
				static std::vector<char16_t> ToNativeUtf16Chars(String^ s);


				/// <summary>
				/// Converts a native fixed array of native UTF-32 characters to a managed UTF-16 string.
				/// Use this method when you want to pass a native array of UTF-16 characters to a managed function or managed string. 
				/// </summary>
				/// <param name="utf16">The native fixed array of native UTF-16 characters to be converted.</param>
				/// <returns>The equivalent managed UTF-16 string from the conversion.</returns>
				static String^ FromNativeUtf16Chars(std::vector<char16_t> utf16);



				/// <summary>
				/// Converts a managed UTF-16 string to a native fixed array of native UTF-32 characters.
				/// Use this method, when you want to pass a managed UTF-16 string to a native function that requires a native fixed array of native UTF-32 characters.
				/// </summary>
				/// <param name="s">The managed UTF-16 string to be converted.</param>
				/// <returns>The equivalent fixed array of native UTF-32 characters.</returns>
				static std::vector<char32_t> ToNativeUtf32Chars(String^ s);


				/// <summary>
				/// Converts a native fixed array of native UTF-32 characters to a managed UTF-16 string.
				/// Use this method when you want to pass a native array of UTF-16 characters to a managed function or managed string. 
				/// </summary>
				/// <param name="utf32">The native fixed array of native UTF-16 characters to be converted.</param>
				/// <returns>The equivalent managed UTF-16 string from the conversion.</returns>
				static String^ FromNativeUtf32Chars(std::vector<char32_t> utf32);

				#endif 



				/// <summary>
				/// 
				/// </summary>
				/// <param name="object"></param>
				/// <param name="handle"></param>
				/// <returns></returns>
				static IntPtr ToIntPtr(Object^ object, [Out]GCHandle% handle);

				/// <summary>
				/// 
				/// </summary>
				/// <param name="ptr"></param>
				/// <returns></returns>
				static Object^ FromIntPtr(IntPtr ptr);
			};
		}
	}
}