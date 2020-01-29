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
