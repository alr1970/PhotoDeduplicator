#include "ImageMap.h"
#include "imageFileFinder.h"

ImageMap::ImageMap(const std::string& rootFolder)
{
	ImageFileFinder finder(rootFolder);
	for (auto image : finder.foundImages()) {
		theFiles.insert(std::make_pair(FileDetails(image), image));
	}
	rangeFront = theFiles.end();
	rangeBack = theFiles.end();
}

ImageMap::~ImageMap()
{
}

std::vector<std::string> ImageMap::getSet()
{
	std::vector<std::string> retVal;
	if (rangeFront == theFiles.end()) {
		auto range = theFiles.equal_range(theFiles.begin()->first);
		rangeFront = range.first;
		rangeBack = range.second;
	}
	else if(rangeBack != theFiles.end()) {
		auto range = theFiles.equal_range(rangeBack->first);
		rangeFront = range.first;
		rangeBack = range.second;
	}
	else {
		rangeFront = theFiles.end();
		rangeBack = theFiles.end();
	}
	if (rangeFront != theFiles.end()) {
		for (auto fil = rangeFront; fil != rangeBack; ++fil) {
			retVal.push_back(fil->second);
		}
	}
	return retVal;		 
}