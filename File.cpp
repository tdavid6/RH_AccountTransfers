#include "File.h"

#include <iostream>

File::File()
{

}

File::File(const std::string& p)
	: path(p)
{

}

File::~File()
{

}


void File::setPath(const std::string& str)
{
	path = str;
}

const std::string& File::getPath() const
{
	return path;
}