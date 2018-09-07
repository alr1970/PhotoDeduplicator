#include "FileDetails.h"
#include <QtCore/QFile>

FileDetails::FileDetails() : _size(-1)
{
}

FileDetails::FileDetails(const std::string & fullFillePathAndName) : _size(-1)
{
	_filename = fullFillePathAndName.substr(fullFillePathAndName.find_last_of("/") + 1);
	_filepath = fullFillePathAndName.substr(0, fullFillePathAndName.find_last_of("/"));
}

FileDetails::~FileDetails()
{
}

long long FileDetails::size()
{
	if (_size == -1) {
		// Find out
		std::string fullFileName = _filepath + "/" + _filename;
		QFile qFile(fullFileName.c_str());
		if (qFile.exists()) {
			_size = qFile.size();
		}
		else {
			_size = 0;
		}
	}
	return _size;
}
