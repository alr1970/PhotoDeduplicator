#include "FileDetails.h"
#include <QtCore/QFile>

FileDetails::FileDetails() : _size(-1)
{
}

FileDetails::FileDetails(const std::string & fullFillePathAndName)
{
	_filename = fullFillePathAndName.substr(fullFillePathAndName.find_last_of("/") + 1);
	_filepath = fullFillePathAndName.substr(0, fullFillePathAndName.find_last_of("/"));
	
	// get the file size
	std::string fullFileName = _filepath + "/" + _filename;
	QFile qFile(fullFileName.c_str());
	if (qFile.exists()) {
		_size = qFile.size();
	}
	else {
		_size = 0;
	}
}

FileDetails::~FileDetails()
{
}

bool FileDetails::operator==(const FileDetails & b) const
{
	return _size == b._size;
}

bool FileDetails::operator!=(const FileDetails & b) const
{
	return size() != b.size();
}

long long FileDetails::size() const
{
	return _size;
}
