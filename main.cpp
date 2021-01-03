#include <iostream>

#include "STL_includes.h"
#include "Folder.h"

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
	std::string str1 = "ahello";
	std::string str2 = "hell";
	if (containsString(str2, str1))
		std::cout << "worked\n";
	else
		std::cout << "didn't work\n";


	if (argc == 1)
	{
		//Enter file name
		std::cout << "Enter file name:" << std::endl;
		std::cin.get();
		return 0;
	}
	Folder folder;
	if (argc == 2)
	{
		folder.setPath(argv[1]);
		std::vector<std::string> inputData;
		import(folder.getPath(), inputData); //TODO: change to wide strings to read special characters
		for (auto & data : inputData)
		{
			std::cout << data << "\n";
		}
		std::cout << std::endl;
		//add(allData, inputData);
		//inputData.clear(); //was needed when looped through multiple input files and aggregated all data
	}
	//std::vector<std::string> allData;
	
	/*if (exportAll(allData))
	{
		std::cout << "The data was successfully merged" << std::endl;
	}*/
	std::cin.get();
	return 0;
}