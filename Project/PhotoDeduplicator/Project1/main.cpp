#include "getopt.h"
#include <string>
int main(int argc, char *argv[])
{
	int c;
	std::string sourceRoot;
	while ((c = getopt(argc, argv, "s:")) != -1)
		switch (c)
		{
		case 's':
			sourceRoot = optarg;
		}

}