#pragma once
#include <map>
#include <vector>
#include "FileDetails.h"
class ImageMap
{
public:
	ImageMap(const std::string& rootFolder);
	~ImageMap();

	std::vector<std::string> getSet();

protected:
	std::multimap<FileDetails, std::string> theFiles;
	std::multimap<FileDetails, std::string>::const_iterator rangeFront;
	std::multimap<FileDetails, std::string>::const_iterator rangeBack;
};

