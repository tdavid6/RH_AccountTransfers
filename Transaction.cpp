#include "Transaction.h"

#include <iostream>

enum class ORDER_TYPE { DEPOSIT, WITHDRAWAL, ORDER_TYPE_COUNT }; // * (-1)
enum class ORDER_STATUS { CANCELED, COMPLETED, ORDER_STATUS_COUNT };
const static std::string order_type[static_cast<unsigned int>(ORDER_TYPE::ORDER_TYPE_COUNT)] = { "Deposit", "Withdrawal" };
const static std::string order_status[static_cast<unsigned int>(ORDER_STATUS::ORDER_STATUS_COUNT)] = { "Canceled", "Completed" };

Transaction::Transaction()
{

}

Transaction::Transaction(const std::string &type, const std::string &amt, const std::string &date, const std::string &status)
	: m_date(date)
{
	if (type == order_type[static_cast<unsigned int>(ORDER_TYPE::DEPOSIT)])
	{
		m_type = static_cast<unsigned int>(ORDER_TYPE::DEPOSIT);
	}
	else if (type == order_type[static_cast<unsigned int>(ORDER_TYPE::WITHDRAWAL)])
	{
		m_type = static_cast<unsigned int>(ORDER_TYPE::WITHDRAWAL);
	}
	else
	{
		//flag error
	}

	std::string amount = amt;
	if (amt.substr(0, 1) == "$")
	{
		amount = amt.substr(1);
		m_Amount = std::stod(amount); //catch error case
	}

	m_status = (status == order_status[static_cast<unsigned int>(ORDER_STATUS::COMPLETED)]);
}

unsigned int Transaction::findIndex(const std::string &str, std::string *arr)
{
	for (unsigned int arrIndex = 0; arrIndex < arr->size(); ++arrIndex)
	{
		if (str == arr[arrIndex])
		{
			return arrIndex;
		}
	}
	return 0;
}


Transaction::~Transaction()
{

}