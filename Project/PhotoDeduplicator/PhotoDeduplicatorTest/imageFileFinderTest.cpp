#include "gtest/gtest.h"
#include "../DeduplicatorInternals/imageFileFinder.h"

TEST(ImageFileFinder, findFrom)
{
	ImageFileFinder finder("..\\..\\testdata");

	EXPECT_EQ(finder.foundImages().size(), 4);

}