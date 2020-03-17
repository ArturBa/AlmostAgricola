//
// Created by artur on 20/02/2020.
//

#include <gmock/gmock.h>
#include <Actions.hh>

using namespace ::testing;
using namespace std;

class AActions : public Test {

};

struct fileNameState {
    Actions action;
    string textValue;
};

struct FileNameTest : AActions, testing::WithParamInterface<fileNameState> {
    FileNameTest() {
    }

    virtual ~ FileNameTest() = default;
};

INSTANTIATE_TEST_SUITE_P (AActions, FileNameTest,
                          Values(
                                  fileNameState{Actions::TEST, "test"},
                                  fileNameState{Actions::GET_2_FOOD, "act_2_food"},
                                  fileNameState{Actions::GET_SHEEP, "act_sheep"}
                          ));

TEST_P(FileNameTest, GetActionFileName) {
    auto as = GetParam();
    EXPECT_EQ(as.textValue, getActionFileName(as.action));
}

TEST_F(AActions, CheckIterateOverEnum) {
    vector<Actions> vector;
    for (auto action : Actions()) {
        vector.push_back(action);
    }
    ASSERT_EQ(vector.front(), Actions::First);
    ASSERT_EQ(vector.back(), Actions::Last);
}