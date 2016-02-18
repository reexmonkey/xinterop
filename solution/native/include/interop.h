
#pragma once

//unamanaged references
#include <string>
#include <vector>

using namespace System;
using namespace System::Runtime::InteropServices;

namespace reexmonkey
{
	namespace xinterop 
	{
		namespace services
		{
			/// <summary>
			/// Helper class to provide interop conversion properties
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
				/// <returns>The resulting native string equivalent</returns>
				static const std::string ToNativeAnsiString(String^ s);

				/// <summary>
				/// Converts a native ANSI string to corresponding managed string.
				/// Use this method when you want to pass a native string to a managed function or string. 
				/// </summary>
				/// <param name="s">The native (STL) string to be converted</param>
				/// <returns>The resulting managed string equivalent</returns>
				static String^ FromNativeAnsiString(const std::string& s);

				/// <summary>
				/// Converts a managed UTF-16 string to a corresponding native Unicode string.
				/// Use this method when you wish to pass a managed string safely to a native function or string.
				/// This method indicates to the garbage collector not to move the referenced mangaed string during clean up operations.
				/// </summary>
				/// <param name="s"></param>
				/// <returns></returns>
				static const std::wstring ToNativeUnicodeString(String^ s);

				/// <summary>
				/// 
				/// </summary>
				/// <param name="s"></param>
				/// <returns></returns>
				static String^ FromNativeUnicodeString(const std::wstring& s);

				/// <summary>
				/// 
				/// </summary>
				/// <param name="s"></param>
				/// <returns></returns>
				static std::vector<char> ToNativeAnsiChars(String^ s);

				/// <summary>
				/// 
				/// </summary>
				/// <param name="chars"></param>
				/// <returns></returns>
				static String^ FromNativeAnsiChars(std::vector<char> chars);


				/// <summary>
				/// 
				/// </summary>
				/// <param name="s"></param>
				/// <returns></returns>
				static std::vector<wchar_t> ToNativeUnicodeChars(String^ s);

				/// <summary>
				/// 
				/// </summary>
				/// <param name="wchars"></param>
				/// <returns></returns>
				static String^ FromNativeUnicodeChars(std::vector<wchar_t> wchars);


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
				static Object^ ToObject(IntPtr ptr);
			};
		}
	}
}