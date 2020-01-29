//
// Created by artur on 29/01/2020.
//
#include <gmock/gmock.h>
#include <Model.hh>

using namespace ::testing;
using namespace std;

class AModel : public Test {
public:
    Model model;
};

TEST_F(AModel, IsImageLoadedWithGoodPath) {
    ASSERT_EQ(model.loadImage("../test/res/img/test.jpg"), true);
}

TEST_F(AModel, IsImageLoadedWithBadPath) {
    ASSERT_EQ(model.loadImage("../test/res/img/no_img.jpg"), false);
}

TEST_F(AModel, IsImageLoadedCorrectly) {
    model.loadImage("../test/res/img/test.jpg");
    ASSERT_EQ(model.getWidth(), 2);
    ASSERT_EQ(model.getHeight(), 2);
}
