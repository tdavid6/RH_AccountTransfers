#include "Folder.h"

#include <iostream>

Folder::Folder()
{

}

Folder::Folder(const std::string& p)
	: path(p)
{

}

Folder::~Folder()
{

}


void Folder::setPath(const std::string& str)
{
	path = str;
}

const std::string& Folder::getPath() const
{
	return path;
}

bool Folder::buildFiles()
{
	return true;
}