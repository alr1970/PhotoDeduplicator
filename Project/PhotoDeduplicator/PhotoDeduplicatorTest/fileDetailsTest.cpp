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

TEST(FileDetails, Equality)
{
	FileDetails file1("..\\..\\testdata\\file1.jpg");
	FileDetails file2("..\\..\\testdata\\file2.jpg");
	// file3 and file1 - Copy are copies of file1
	FileDetails file3("..\\..\\testdata\\file3.jpg");
	FileDetails file4("..\\..\\testdata\\file1 - Copy.jpg");
	EXPECT_NE(file1, file2);
	EXPECT_EQ(file1, file3);
	EXPECT_EQ(file1, file4);
}