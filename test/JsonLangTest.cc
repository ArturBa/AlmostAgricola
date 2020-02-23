//
// Created by artur on 20/02/2020.
//
#include <gmock/gmock.h>
#include <JsonLang.hh>

using namespace ::testing;
using namespace std;

class AJsonLang : public Test {
public:
    AJsonLang() : settings(), jsonLang(&settings) {};
    Settings settings;
    JsonLang jsonLang;
};

TEST_F(AJsonLang, GetText_Test) {
    ASSERT_EQ(jsonLang.getText("test"), "test");
}

TEST_F(AJsonLang, GetTextAfterChangingLangToPl_Test) {
    settings.setLang("pl");
    ASSERT_EQ(jsonLang.getText("test"), "test");
}

TEST_F(AJsonLang, GetTextAfterChangingLangToEng_Test) {
    settings.setLang("eng");
    ASSERT_EQ(jsonLang.getText("test"), "test");
}

TEST_F(AJsonLang, GetTextFromUnknownKey_Null) {
    settings.setLang("eng");
    ASSERT_EQ(jsonLang.getText("NOTest"), "null");
}
