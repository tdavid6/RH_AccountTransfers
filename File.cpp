#include "File.h"

#include <iostream>

enum class SEARCH_TERMS { AMOUNT, DOLLAR, BANK_ACCOUNT, CHECKING, INITIATED, COMPLETED, STATUS, CANCELED, DEPOSIT, WITHDRAWAL, SEARCH_TERMS_COUNT };
const static std::string searchTerms[static_cast<unsigned int>(SEARCH_TERMS::SEARCH_TERMS_COUNT)] = { "Amount", "$", "Bank Account", "Checking", "Initiated", "Completed", "Status", "Canceled", "Deposit", "Withdrawal" };

File::File()
{

}

File::File(const std::string& p)
	: m_path(p)
{

}

File::~File()
{

}

bool File::import()
{
	return import(m_inputData, m_path);
}

bool File::import(std::vector<std::string> &data)
{
	return import(data, m_path);
}

bool File::import(const std::string &fileName)
{
	return import(m_inputData, fileName);
}

bool File::import(std::vector<std::string> &data, const std::string &fileName)
{
	std::ifstream input;
	input.open(fileName);

	if (input.is_open())
	{
		std::string temp = "";
		while (std::getline(input, temp))
		{
			data.emplace_back(temp); //TODO: change to wide strings to read special characters
			temp = "";
		}
		input.close();
		return true;
	}
	else
	{
		std::cerr << fileName << " failed to open" << std::endl;
	}
	return false;
}

unsigned int File::count(const std::string &str)
{
	unsigned int count = 0;
	std::string dataLine = "";
	unsigned int strSize = str.size();
	for (unsigned int dataIndex = 0; dataIndex < m_inputData.size(); ++dataIndex)
	{
		dataLine = m_inputData[dataIndex];

		if (strSize <= dataLine.size())
		{
			if (str == dataLine.substr(0, strSize))
				++count;
		}
	}
	//for (auto & line : m_inputData)
	//{
	//	if (line.find(str) >= 0)
	//		++count;
	//}
	return count;
}

bool File::extrapTrans(const std::vector<std::string> &data)
{
	unsigned int dataSize = data.size();

	std::string t_Amount = "";
	std::string t_Date = "";
	std::string t_Status = "";
	std::string t_Type = "";

	for (unsigned int dataIndex = 0; dataIndex < dataSize; ++dataIndex)
	{
		if (data[dataIndex] == searchTerms[static_cast<unsigned int>(SEARCH_TERMS::AMOUNT)]
			&& (dataIndex - 1 >= 0 && dataIndex + 1 < dataSize))
		{
				t_Amount = data[dataIndex + 1];
				t_Type = data[dataIndex - 1];
		}

		if (data[dataIndex] == searchTerms[static_cast<unsigned int>(SEARCH_TERMS::INITIATED)])
		{
			if (dataIndex - 1 > 0 && dataIndex + 1 < dataSize)
			{
				t_Date = data[dataIndex + 1];
			}
		}

		if (data[dataIndex] == searchTerms[static_cast<unsigned int>(SEARCH_TERMS::STATUS)])
		{
			if (dataIndex - 1 > 0 && dataIndex + 1 < dataSize)
			{
				t_Status = data[dataIndex + 1];
			}
			
		}

		if (t_Amount != "" && t_Date != "" && t_Status != "" && t_Type != "")
		{
			m_transactions.push_back(Transaction(t_Type, t_Amount, t_Date, t_Status));
			t_Amount = "";
			t_Date = "";
			t_Status = "";
			t_Type = "";
		}
	}
	return true;
}


bool File::parseTransactions()
{
	//for (unsigned int dataIndex = 0; dataIndex < count("Amount"); ++dataIndex)
	unsigned int totalTransactions = count("Initiated");
	if (count("Completed") + count("Canceled") != totalTransactions || count("$") != totalTransactions)
	{
		std::cout << "There are missing data\n";
		return false;
	}
	unsigned int amtCount = 0;
	//unsigned int dollarCount
	//unsigned int 

	bool continueSearch = false;
	//Transaction newTransaction();

	std::string t_Amount = "";
	std::string t_Date = "";
	std::string t_Status = "";
	std::string t_Type = "";

	for (unsigned int dataIndex = 0; dataIndex < m_inputData.size(); ++dataIndex)
	{
		if (m_inputData[dataIndex] == "Amount")
		{
			t_Type = m_inputData[dataIndex - 1];
			std::string amtStr = m_inputData[dataIndex + 1];
			if (amtStr.substr(0, 1) == "$")
			{
				t_Amount = amtStr;
			}
		}

		if (m_inputData[dataIndex] == "Initiated")
		{
			t_Date = m_inputData[dataIndex + 1];
		}

		if (m_inputData[dataIndex] == "Status")
		{
			t_Status = m_inputData[dataIndex + 1];

			m_transactions.push_back(Transaction(t_Type, t_Amount, t_Date, t_Status));

			t_Amount = "";
			t_Date = "";
			t_Status = "";
			t_Type = "";
		}
	}

	return true;
}

bool File::comprehensiveData()
{
	unsigned int xfers = count(searchTerms[static_cast<unsigned int>(SEARCH_TERMS::INITIATED)]);
	unsigned int comp = count(searchTerms[static_cast<unsigned int>(SEARCH_TERMS::COMPLETED)]);
	unsigned int canc = count(searchTerms[static_cast<unsigned int>(SEARCH_TERMS::CANCELED)]);

	if (comp + canc != xfers)
	{
		std::cout << "There are missing data\n";
		std::cout << searchTerms[static_cast<unsigned int>(SEARCH_TERMS::INITIATED)] << " " << xfers << "\n";
		std::cout << searchTerms[static_cast<unsigned int>(SEARCH_TERMS::COMPLETED)] << " " << comp << "\n";
		std::cout << searchTerms[static_cast<unsigned int>(SEARCH_TERMS::CANCELED)] << " " << canc << "\n";

	}
	else
	{
		if (extrapTrans(m_inputData))
		{
			if (xfers == m_transactions.size())
				return true;
		}
	}

	return false;
}

bool File::printAll()
{
	for (auto & data : m_inputData)
	{
		std::cout << data << "\n";
	}
	std::cout << std::endl;
	return true;
}

void File::setPath(const std::string& str)
{
	m_path = str;
}

const std::string& File::getPath() const
{
	return m_path;
}