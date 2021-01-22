#pragma once
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "STL_includes.h"

//const unsigned int ST
const std::string STATUS = { "Canceled", "Completed" };
const std::string TYPE = { "Deposit", "Withdrawal" };
enum status { CANCELED, COMPLETED };
enum type { DEPOSIT, WITHDRAWAL}; // * (-1)

class Transaction
{
public:
	Transaction();
	Transaction(const std::string &type, const std::string &amt, const std::string &date, const std::string &status);
	~Transaction();

private:
	double m_Amount;
	std::string m_date;
	bool m_status; //bool completed or cancelled
	bool m_type; //bool Deposit or Withdrawal

public:
	//bool setAmount(const std::string &amt)
};

#endif // !"TRANSACTION_H"