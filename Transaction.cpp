#include "Transaction.h"

#include <iostream>

Transaction::Transaction()
{

}

Transaction::Transaction(const std::string &type, const std::string &amt, const std::string &date, const std::string &status)
{
	m_date = date;

	std::string amount = amt;
	if (amt.substr(0, 1) == "$")
	{
		amount = amt.substr(1, amt.size());
		m_Amount = std::stod(amount);
	}

	if (status == "Completed")
	{
		m_status = true;
	}
	else if (status == "Canceled")
	{
		m_status = false;
	}

	if (status == "Withdrawal")
	{
		m_status = true;
	}
	else if (status == "Deposit")
	{
		m_status = false;
	}

	//for (unsigned int statusIndex = 0; statusIndex < STATUS.size(); ++statusIndex)
	//{
	//	if (status.c_str == STATUS[statusIndex])
	//	{
	//
	//	}
	//}
}


Transaction::~Transaction()
{

}