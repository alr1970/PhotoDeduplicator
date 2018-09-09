#pragma once
#include <string>
class FileDetails
{
public:
	FileDetails();
	FileDetails(const std::string& fullFillePathAndName);
	virtual ~FileDetails();

	bool operator ==(const FileDetails &b) const;
	bool operator !=(const FileDetails &b) const;
	bool operator <(const FileDetails &b) const;

	std::string filepath() const { return _filepath; };
	std::string filename() const { return _filename; };

	long long size() const;

protected:
	// Keep path and name separately beacuse multiple copies of the same file my exist
	std::string _filepath;
	std::string _filename;
	long long _size;	// size on bytes on disk, might be really big!

	// Image properties
	unsigned _width;
	unsigned _height;

};

