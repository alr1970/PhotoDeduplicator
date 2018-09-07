#pragma once
#include <string>
class FileDetails
{
public:
	FileDetails();
	FileDetails(const std::string& fullFillePathAndName);
	virtual ~FileDetails();

	std::string filepath() { return _filepath; };
	std::string filename() { return _filename; };

	long long size();

protected:
	// Keep path and name separately beacuse multiple copies of the same file my exist
	std::string _filepath;
	std::string _filename;
	long long _size;	// size on bytes on disk, might be really big!

	// Image properties
	unsigned _width;
	unsigned _height;

};

