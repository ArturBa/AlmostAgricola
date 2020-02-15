//
// Created by artur on 14/02/2020.
//

#include <gmock/gmock.h>
#include <Json.hh>

using namespace ::testing;
using namespace std;

class AJSON : public Test {

};

TEST_F(AJSON, LoadJsonFromFile_Correct) {
    nlohmann::json json = R"( {"1": "one"} )"_json;
    ASSERT_EQ(json, *LoadJsonFromFile("../test/res/json/test.json"));
}

TEST_F(AJSON, LoadJsonFromFile_WrongPath) {
    nlohmann::json json = R"( {"1": "one"} )"_json;
    ASSERT_EQ(nullptr, LoadJsonFromFile("../test/res/json/no_test.json"));
}

TEST_F(AJSON, LoadJsonFromFile_Value1_One) {
    nlohmann::json json_expected = R"( {"1": "one"} )"_json;
    nlohmann::json *json_actual = LoadJsonFromFile("../test/res/json/test.json");
    ASSERT_EQ(json_expected.at("1"), json_actual->at("1"));
}
