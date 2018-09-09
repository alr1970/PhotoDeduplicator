#pragma once

#include <string>
#include <vector>

class ImageFileFinder
{
public:
	ImageFileFinder(const std::string& startLocation);
	virtual ~ImageFileFinder() {};

	const std::vector<std::string>& foundImages() const;

	void searchFolder(const std::string & folderPath);

protected:
	std::vector<std::string> _foundImages;
};