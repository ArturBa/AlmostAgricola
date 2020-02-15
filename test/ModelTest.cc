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
    ASSERT_EQ(model.loadImage("../test/res/img/test.png"), true);
}

TEST_F(AModel, IsImageLoadedWithBadPath) {
    ASSERT_EQ(model.loadImage("../test/res/img/no_img.jpg"), false);
}

TEST_F(AModel, AreImageDimmentionsCorrect) {
    model.loadImage("../test/res/img/test.png");
    ASSERT_EQ(model.getWidth(), 2);
    ASSERT_EQ(model.getHeight(), 2);
}

TEST_F(AModel, AreImageValuesCorrect) {
    model.loadImage("../test/res/img/test.png");
    auto modelImg = model.getImage();
    const unsigned char expImg[16] = {0, 0, 0, 255, 255, 0, 0, 255, 0, 255, 0, 255, 0, 0, 255, 255};
    for (int i = 0; i < 16; ++i) {
        ASSERT_EQ(modelImg[i], expImg[i]);
    }
}