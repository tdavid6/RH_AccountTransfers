#include <iostream>

#include "STL_includes.h"

#include "File.h"
#include "Transaction.h"

bool import(const std::string &file, std::vector<std::string> &data)
{
	std::ifstream input;
	input.open(file);

	std::string temp = "";

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


int main(int argc, char ** argv)
{
	File accountFile;

	if (argc == 1)
	{
		std::cout << "Enter file name:" << std::endl;
		std::string fileNamed = argv[0];
		fileNamed = fileNamed.substr(0, fileNamed.rfind('\\'));
		fileNamed += "/AccountTransfers_Signed.txt";
		accountFile.setPath(fileNamed);
		//std::getline(std::cin, fileNamed);
	}
	else
	{
		accountFile.setPath(argv[1]);
	}



	accountFile.import();

	if (accountFile.comprehensiveData()) // accountFile.count(searchTerms[COMPLETED]) + accountFile.count(searchTerms[CANCELED]) != accountFile.count(searchTerms[INITIATED]))
	{
		std::cout << "Pause here!" << std::endl;
	}
	else
	{

		
		//accountFile.printAll();


		std::cin.get();
		return 0;
	}
}