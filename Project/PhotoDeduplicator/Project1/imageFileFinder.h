#pragma once

#include <string>
#include <vector>

class ImageFileFinder
{
public:
	ImageFileFinder(const std::string& startLocation);
	virtual ~ImageFileFinder() {};

	const std::vector<std::string>& foundImages() const;

protected:
	std::vector<std::string> _foundImages;
};