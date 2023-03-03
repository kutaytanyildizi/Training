#ifndef _UNSUFFICIENTFUNDSEXCEPTION_H_
#define _UNSUFFICIENTFUNDSEXCEPTION_H_
#include <stdexcept>

class InsufficientFundsException : public std::exception
{
public:
	InsufficientFundsException() noexcept = default;
	~InsufficientFundsException() = default;
	virtual const char* what() const noexcept
	{
		return "Insufficent funds exception";
	}
};

#endif // !_UNSUFFICENTFUNDSEXCEPTION_H_

