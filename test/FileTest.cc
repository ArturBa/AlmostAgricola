//
// Created by artur on 26/01/2020.
//

#include <File.hh>
#include <gmock/gmock.h>

TEST(FileTest, FileTest_AddInt_Test) {
    ASSERT_EQ(5, FileAdd(3, 2));
}
