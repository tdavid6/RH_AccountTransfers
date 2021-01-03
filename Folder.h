#pragma once
#ifndef FOLDER_H
#define FOLDER_H

#include "STL_includes.h"

class Folder
{
public:
	Folder();
	Folder(const std::string& p);
	~Folder();

private:
	std::string path;
	std::vector<std::string> filePaths;

public:
	void setPath(const std::string &str);
	//const std::string* getPath();
	const std::string& getPath() const;

	bool buildFiles();
};

#endif // !"FOLDER_H"
