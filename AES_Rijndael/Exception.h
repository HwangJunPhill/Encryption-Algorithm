#pragma once
#include <cstdint>
#include <string>
#include <map>
namespace AES
{
	class Exception
	{
	public:
		enum class ErrorCode : uint8_t
		{
			BadSize

		};
		static const std::map<ErrorCode, std::string> ErrorList;

		Exception(ErrorCode error, std::string msg = "")
			:error(error), message(msg)
		{

		}

		std::string What()
		{
			return (message.length() == 0) ? ErrorList.at(error) : message;
		}
	private:
		ErrorCode error;
		std::string message;
	};
	const std::map<Exception::ErrorCode, std::string> Exception::ErrorList =
		[]()->decltype(Exception::ErrorList) {
		std::map<Exception::ErrorCode, std::string> ErrorList;

		ErrorList[Exception::ErrorCode::BadSize] = "BadSize";

		return ErrorList;
	}();
}