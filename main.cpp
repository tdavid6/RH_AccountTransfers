#include <iostream>

#include "STL_includes.h"

#include "File.h"
#include "Transaction.h"

bool import(const std::string &file, std::vector<std::string> &data)
{
	std::ifstream input;
	input.open(file);

	std::string temp = "";
	//std::vector<std::string> data;
	if (input.is_open())
	{
		while (std::getline(input, temp))
		{
			data.push_back(temp);
			temp = "";
		}
		input.close();
		return true;
	}
	else
	{
		std::cerr << file << " failed to open" << std::endl;
	}
	return false;
}

bool exportAll(const std::vector<std::string> &output)
{
	std::string fileName = "OutputFileTif.csv";
	std::ofstream outputFile;
	outputFile.open(fileName);

	std::string temp = "";
	//std::vector<std::string> data;
	if (outputFile.is_open())
	{
		for (const auto& dataPoint : output)
		{
			outputFile << dataPoint << std::endl;
		}

		outputFile.close();
		return true;
	}
	else
	{
		std::cerr << fileName << " failed to open" << std::endl;
	}
	return false;
}

bool compareNextChar()
{
	return false;
}

bool containsString(const std::string &searchKey, const std::string &searchString)
{
	if (searchString.find(searchKey) == 0)
		return true;
	else
		return false;

	if (searchKey.size() <= searchString.size())
	{
		for (unsigned int let = 0; let < searchKey.size(); ++let)
		{
			auto found_It = std::find(searchString.begin(), searchString.end(), searchKey[let]);
			if (found_It != searchString.end())
				return true;
		}
		//auto found_It = std::find(searchString.begin(), searchString.end(), 'b');
		//chartest = searchKey.c_str();
		//auto it = std::find(searchString.begin(), searchString.end(), searchKey.c_str());
		//if (found_It != searchString.end())
			//return true;
	}
	return false;
}

unsigned int count(const std::string &str, const std::string &toCount, const unsigned int &startingNumber = 0)
{
	unsigned int count = startingNumber;

	if (toCount.size() <= str.size())
	{
		//for (auto )
	}
	

	return count;
}

int main(int argc, char** argv)
{
	//std::string str1 = "ahello";
	//std::string str2 = "hell";
	//if (containsString(str2, str1))
	//	std::cout << "worked\n";
	//else
	//	std::cout << "didn't work\n";

	File accountFile;
	if (argc == 1)
	{
		//Enter file name
		std::string fileNamed = "";
		std::cout << "Enter file name:" << std::endl;
		//accountFile.setPath("F:/Code/Projects/c++/RH_AccountTransfers/Debug/AccountTransfers_Signed.txt");
		//std::cin.get();
		
	}
	
	if (argc == 2)
	{
		accountFile.setPath(argv[1]);
	}
		std::vector<std::string> searchTerms = { "Amount", "$", "Bank Account", "Checking", "Initiated", "Completed", "Status", "Canceled", "Deposit", "Withdrawal"};

		accountFile.import();

		//std::vector<Transaction> transactions;

		if (accountFile.count("Completed") + accountFile.count("Canceled") != accountFile.count("Initiated"))
		{
			std::cout << "There are missing data\n";
		}
		else
			std::cout << "Looks okay mathwiseeeeGamegie\n";

		//accountFile.parseTransactions();

		for (unsigned int sacDex = 0; sacDex < accountFile.count("Amount"); ++sacDex)
		{
			//transactions.emplace_back(Transaction());
		}

		for (auto & term : searchTerms)
		{
			std::cout << term << ": " << accountFile.count(term) << std::endl;
		}
		
		//accountFile.printAll();
	
	
	std::cin.get();
	return 0;
}