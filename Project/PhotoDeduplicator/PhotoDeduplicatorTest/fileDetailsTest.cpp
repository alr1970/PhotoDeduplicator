#include "gtest/gtest.h"
#include "../DeduplicatorInternals/fileDetails.h"

TEST(FileDetails, constructor)
{
	FileDetails fileDets("D:/testData/path/file.txt");

	EXPECT_EQ(fileDets.filename(), "file.txt");
	EXPECT_EQ(fileDets.filepath(), "D:/testData/path");
}

TEST(FileDetails, size)
{
	FileDetails fileDets("..\\..\\testdata\\path\\file.txt");
	EXPECT_EQ(fileDets.size(), 0); // doesn't exist

	FileDetails file1Dets("..\\..\\testdata\\file1.jpg");
	EXPECT_EQ(file1Dets.size(), 135859);
}