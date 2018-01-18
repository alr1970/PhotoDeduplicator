#include "imageFileFinder.h"
#include <QtCore/QDir>
#include <iostream>

ImageFileFinder::ImageFileFinder(const std::string & startLocation)
{
	searchFolder(startLocation);
}

const std::vector<std::string>& ImageFileFinder::foundImages() const
{
	return _foundImages;
}

void ImageFileFinder::searchFolder(const std::string& folderPath)
{
	// List the files and folders in the specified folder
	QDir thisDir(folderPath.c_str());

	// Look for images and folders
	QFileInfoList items = thisDir.entryInfoList(QStringList("*.jpg"), QDir::AllDirs | QDir::Files);

	thisDir.cdUp();
	QFileInfoList::const_iterator constIterator;
	for (constIterator = items.constBegin(); constIterator != items.constEnd(); ++constIterator) {
		std::string fullItemPath = constIterator->absoluteFilePath().toLocal8Bit().constData();
		if (constIterator->isFile()) {
			_foundImages.push_back(fullItemPath);
		}
		else if((fullItemPath != folderPath)  // avoid following '.'
			&& (fullItemPath.c_str() != thisDir.absolutePath())) {
			searchFolder(fullItemPath);
		}
	}
}