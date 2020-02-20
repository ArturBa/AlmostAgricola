//
// Created by artur on 19/02/2020.
//
#include <gmock/gmock.h>
#include <Settings.hh>

using namespace ::testing;
using namespace std;

class ASettings : public Test {
public:
    static const string PL;
    static const string ENG;

    ASettings() : settings() {};
    Settings settings;
};

const string ASettings::PL("pl");
const string ASettings::ENG("eng");


TEST_F(ASettings, SetLang_Pl) {
    settings.setLang(PL);
    ASSERT_EQ(PL, settings.getLang());
}

TEST_F(ASettings, SetLang_Eng) {
    settings.setLang(ENG);
    ASSERT_EQ(ENG, settings.getLang());
}

TEST_F(ASettings, SetRes_1280) {
    settings.setResHor(1280);
    ASSERT_EQ(1280, settings.getResHor());
    ASSERT_EQ(sf::Vector2u(1280, 720).x, settings.getSize().x);
    ASSERT_EQ(sf::Vector2u(1280, 720).y, settings.getSize().y);
}

TEST_F(ASettings, SetRes_800) {
    settings.setResHor(800);
    ASSERT_EQ(800, settings.getResHor());
    ASSERT_EQ(sf::Vector2u(800, 600).x, settings.getSize().x);
    ASSERT_EQ(sf::Vector2u(800, 600).y, settings.getSize().y);
}

TEST_F(ASettings, SetRes_1920) {
    settings.setResHor(1920);
    ASSERT_EQ(1920, settings.getResHor());
    ASSERT_EQ(sf::Vector2u(1920, 1080).x, settings.getSize().x);
    ASSERT_EQ(sf::Vector2u(1920, 1080).y, settings.getSize().y);
}

TEST_F(ASettings, SetRes_530) {
    settings.setResHor(530);
    ASSERT_EQ(800, settings.getResHor());
    ASSERT_EQ(sf::Vector2u(800, 600).x, settings.getSize().x);
    ASSERT_EQ(sf::Vector2u(800, 600).y, settings.getSize().y);
}

