#pragma once
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "STL_includes.h"

//const unsigned int ST


class Transaction
{
public:
	Transaction();
	Transaction(const std::string &type, const std::string &amt, const std::string &date, const std::string &status);
	~Transaction();

private:

	double m_Amount = 0;
	std::string m_date;
	bool m_status; //bool completed or cancelled
	bool m_type; //bool Deposit or Withdrawal

private:
	unsigned int findIndex(const std::string &str, std::string *arr);

public:
	//bool setAmount(const std::string &amt)
};

#endif // !"TRANSACTION_H"