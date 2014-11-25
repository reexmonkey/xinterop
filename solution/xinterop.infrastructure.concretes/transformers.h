
#pragma once

//unamanaged references
#include <string>

using namespace System;

namespace reexmonkey
{
	namespace xinterop {
		namespace infrastructure{
			namespace concrete{
				/// <summary>
				/// Helper class to provide interop conversion properties
				/// </summary>
				public ref class InteropExtensions abstract sealed
				{
				public:
					/// <summary>
					/// Converts a managed string to corresponding native (STL) string.
					/// </summary>
					/// <param name="s">The managed string to convert</param>
					/// <returns>The native string equivalent</returns>
					static const std::string ToNativeString(String^ s);

					/// <summary>
					/// Converts a native (STL) string to corresponding managed string.
					/// </summary>
					/// <param name="s">The native (STL) string to convert</param>
					/// <returns>The managed string equivalent</returns>
					static String^ ToManagedString(const std::string& s);
				};
			}
		}
	}
}