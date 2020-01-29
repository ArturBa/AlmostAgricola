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


TEST_F(AModel, IsBgBlackWhenCreated) {
    ASSERT_EQ(model.getBgColor(), sf::Color::Black);
}

TEST_F(AModel, IsBgGreenAfterSet) {
    float color[3] = {0, 1, 0};
    model.setBgColor(color);
    ASSERT_EQ(model.getBgColor(), sf::Color::Green);
}

TEST_F(AModel, IsBgBlueAfterSet) {
    float color[3] = {0, 0, 1};
    model.setBgColor(color);
    ASSERT_EQ(model.getBgColor(), sf::Color::Blue);
}

TEST_F(AModel, IsBgRedAfterSet) {
    float color[3] = {1, 0, 0};
    model.setBgColor(color);
    ASSERT_EQ(model.getBgColor(), sf::Color::Red);
}

TEST_F(AModel, IsBgWhiteAfterSet) {
    float color[3] = {1, 1, 1};
    model.setBgColor(color);
    ASSERT_EQ(model.getBgColor(), sf::Color::White);
}

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
