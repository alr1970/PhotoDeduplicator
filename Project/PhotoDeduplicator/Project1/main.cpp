#include "getopt.h"
#include <string>
#include <iostream>
#include <QtWidgets/QApplication>
#include "../DeduplicatorInternals/ImageMap.h"

int main(int argc, char *argv[])
{
	QCoreApplication app(argc, argv);
	int c;
	std::string sourceRoot;
	while ((c = getopt(argc, argv, "s:")) != -1) {
		switch (c)
		{
		case 's':
			sourceRoot = optarg;
		}
	}

	ImageMap themap(sourceRoot);
	std::vector<std::string> fileSet = themap.getSet();
	while (fileSet.size() > 0) {
		for (auto file = fileSet.begin(); file != fileSet.end(); ++file)
		{
			std::cout << *file << std::endl;
		}
		std::cout << std::endl;
		fileSet = themap.getSet();
	}

	return app.exec();
}