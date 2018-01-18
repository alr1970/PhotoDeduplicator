#include "getopt.h"
#include <string>
#include <QtWidgets/QApplication>
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

	return app.exec();
}