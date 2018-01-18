#include "getopt.h"
#include <string>
#include <iostream>
#include <QtWidgets/QApplication>
#include "imageFileFinder.h"

int main(int argc, char *argv[])
{
	QCoreApplication app(argc, argv);
	int c;
	std::string sourceRoot;
	while ((c = getopt(argc, argv, "s:")) != -1)
		switch (c)
		{
		case 's':
			sourceRoot = optarg;
		}

	ImageFileFinder finder(sourceRoot);
	std::vector<std::string> files = finder.foundImages();
	for (auto file = files.begin(); file != files.end(); ++file)
	{
		std::cout << *file << std::endl;
	}

	return app.exec();
}