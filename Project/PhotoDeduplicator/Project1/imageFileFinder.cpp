#include "imageFileFinder.h"

ImageFileFinder::ImageFileFinder(const std::string & startLocation)
{
}

const std::vector<std::string>& ImageFileFinder::foundImages() const
{
	return _foundImages;
}
