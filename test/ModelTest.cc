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

TEST_F(AModel, ActionsMap_AllTrue) {
    auto actions = model.getMapOfActions();
    for (auto action: *actions) {
        ASSERT_TRUE(action.second);
    }
}