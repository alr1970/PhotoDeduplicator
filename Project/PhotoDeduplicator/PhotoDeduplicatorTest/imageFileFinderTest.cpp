#include "gtest/gtest.h"
#include "../Project1/imageFileFinder.h"

TEST(ImageFileFinder, findFrom)
{
	ImageFileFinder finder("..\\..\\testdata");

	EXPECT_EQ(finder.foundImages().size(), 2);

}