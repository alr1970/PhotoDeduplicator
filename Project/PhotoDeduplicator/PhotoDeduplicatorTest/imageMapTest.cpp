#include "gtest/gtest.h"
#include "../DeduplicatorInternals/ImageMap.h"

TEST(ImageMap, constructor)
{
	ImageMap themap("..\\..\\testdata");

	std::vector<std::string> firstSet = themap.getSet();
	EXPECT_EQ(firstSet.size(), 1);
	std::vector<std::string> secondSet = themap.getSet();
	EXPECT_EQ(secondSet.size(), 3);
	std::vector<std::string> thirdSet = themap.getSet();
	EXPECT_EQ(thirdSet.size(), 0);
}