#pragma once
#ifndef FILE_H
#define FILE_H

#include "STL_includes.h"

class File
{
public:
	File();
	File(const std::string& p);
	~File();

private:
	std::string path;

public:
	void setPath(const std::string &str);
	//const std::string* getPath();
	const std::string& getPath() const;

	//bool buildFiles();
};

#endif // !"FILE_H"
