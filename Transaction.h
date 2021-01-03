#pragma once
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "STL_includes.h"

class Transaction
{
public:
	Transaction();
	~Transaction();

private:
	double m_Amount;
	std::string m_date;
	std::string m_status; //bool completed or cancelled
	std::string m_type; //bool Deposit or Withdrawal

public:

};

#endif // !"TRANSACTION_H"