//
// Created by artur on 20/02/2020.
//

#include <gmock/gmock.h>
#include <Actions.hh>

using namespace ::testing;
using namespace std;

class AActions : public Test {

};

TEST_F(AActions, GetActionFileName_TEST_test) {
    ASSERT_EQ("test", getActionFileName(Actions::TEST));
}

TEST_F(AActions, GetActionFileName_GET_SHEEP_sheep) {
    ASSERT_EQ("sheep", getActionFileName(Actions::GET_SHEEP));
}

TEST_F(AActions, GetActionFileName_GET_2_FOOD_2_food) {
    ASSERT_EQ("2_food", getActionFileName(Actions::GET_2_FOOD));
}

TEST_F(AActions, CheckIterateOverEnum) {
    vector<Actions> vector;
    for (auto action : Actions()) {
        vector.push_back(action);
    }
    ASSERT_EQ(vector.front(), Actions::First);
    ASSERT_EQ(vector.back(), Actions::Last);
}