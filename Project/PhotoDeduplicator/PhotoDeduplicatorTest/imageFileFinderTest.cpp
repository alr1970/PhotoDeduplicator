#include "gtest/gtest.h"
#include "../Project1/imageFileFinder.h"

TEST(ImageFileFinder, findFrom)
{
	ImageFileFinder finder("C:/testData");

	EXPECT_EQ(finder.foundImages().size(), 2);

}