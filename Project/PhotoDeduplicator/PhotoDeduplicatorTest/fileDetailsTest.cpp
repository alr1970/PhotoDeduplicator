#include "gtest/gtest.h"
#include "../DeduplicatorInternals/fileDetails.h"

TEST(FileDetails, constructor)
{
	FileDetails fileDets("C:/testData/path/file.txt");

	EXPECT_EQ(fileDets.filename(), "file.txt");
	EXPECT_EQ(fileDets.filepath(), "C:/testData/path");
}

TEST(FileDetails, size)
{
	FileDetails fileDets("C:/testData/path/file.txt");
	EXPECT_EQ(fileDets.size(), 0); // doesn't exist

	FileDetails file1Dets("C:/testData/file1.jpg");
	EXPECT_EQ(file1Dets.size(), 1697397);
}