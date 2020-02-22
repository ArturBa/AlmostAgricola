//
// Created by artur on 22/02/2020.
//
#include <gmock/gmock.h>
#include <Upgrade.hh>
#include <JsonLang.hh>
#include <Settings.hh>


using namespace ::testing;
using namespace std;

class AUpgrades : public Test {
public:
    AUpgrades() : settings(), langJson(&settings) {
        upgrade = UpgradeFactory::getUpgrade(UpgradeEnum::TEST, langJson);
    };
    Settings settings;
    JsonLang langJson;
    Upgrade *upgrade;
};

TEST_F(AUpgrades, IsImageLoadedCorrectly) {
    const auto &actTexture = upgrade->getTexture().copyToImage();
    auto expTexture = sf::Texture().copyToImage();
    expTexture.loadFromFile("../test/res/img/test.png");
    ASSERT_EQ(expTexture.getSize(), actTexture.getSize());
    for (unsigned int x = 0; x < actTexture.getSize().x; ++x) {
        for (unsigned int y = 0; y < actTexture.getSize().y; ++y) {
            ASSERT_EQ(actTexture.getPixel(x, y), expTexture.getPixel(x, y));
        }
    }
}

TEST_F(AUpgrades, IsTextLoadedCorrectly) {
    const auto &text = upgrade->getText();
    ASSERT_EQ("test", text);
}

TEST_F(AUpgrades, IsSameUpgradeTwice) {
    auto upgrade0 = UpgradeFactory::getUpgrade(UpgradeEnum::TEST, langJson);
    ASSERT_EQ(upgrade, upgrade0);
}

