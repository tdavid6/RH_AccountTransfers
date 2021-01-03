#include <iostream>

#include "STL_includes.h"
#include "File.h"

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


	if (argc == 1)
	{
		//Enter file name
		std::cout << "Enter file name:" << std::endl;
		std::cin.get();
		return 0;
	}
	
	if (argc == 2)
	{
		std::vector<std::string> searchTerms = { "Amount", "$", "Bank Account", "Checking", "Initiated", "Completed", "Status", "Canceled", "Deposit", "Withdrawal"};

		File accountFile(argv[1]);
		accountFile.import();

		for (auto & term : searchTerms)
		{
			std::cout << term << ": " << accountFile.count(term) << std::endl;
		}
		
		//accountFile.printAll();
	}
	
	std::cin.get();
	return 0;
}