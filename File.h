#pragma once
#ifndef FILE_H
#define FILE_H

#include "STL_includes.h"
#include "Transaction.h"



class File
{
public:
	File();
	File(const std::string& p);
	~File();

private:

	
	std::string m_path;
	std::vector<std::string> m_inputData;

	std::vector<Transaction> m_transactions;

	bool extrapTrans(const std::vector<std::string> &data);

public:
	void setPath(const std::string &str);
	//const std::string* getPath();
	const std::string& getPath() const;

	bool import();
	bool import(std::vector<std::string> &data);
	bool import(const std::string &fileName);
	bool import(std::vector<std::string> &data, const std::string &fileName);

	bool parseTransactions();

	bool comprehensiveData();

	bool printAll();

	unsigned int count(const std::string &str);
};

#endif // !"FILE_H"
