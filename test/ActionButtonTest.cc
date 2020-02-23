//
// Created by artur on 18/02/2020.
//
#include <gmock/gmock.h>
#include <ActionButton.hh>
#include <JsonLang.hh>
#include <Settings.hh>


using namespace ::testing;
using namespace std;

class AActionButton : public Test {
public:
    AActionButton() : settings(), langJson(&settings) {
        actionButton = ActionButtonFactory::getActionButton(Actions::TEST, langJson);
    };
    Settings settings;
    JsonLang langJson;
    ActionButton *actionButton;
};

TEST_F(AActionButton, IsImageLoadedCorrectly) {
    const auto &actTexture = actionButton->getTexture().copyToImage();
    auto expTexture = sf::Texture().copyToImage();
    expTexture.loadFromFile("../test/res/img/test.png");
    ASSERT_EQ(expTexture.getSize(), actTexture.getSize());
    for (unsigned int x = 0; x < actTexture.getSize().x; ++x) {
        for (unsigned int y = 0; y < actTexture.getSize().y; ++y) {
            ASSERT_EQ(actTexture.getPixel(x, y), expTexture.getPixel(x, y));
        }
    }
}

TEST_F(AActionButton, IsTextLoadedCorrectly) {
    const auto &text = actionButton->getText();
    ASSERT_EQ("test", text);
}

TEST_F(AActionButton, IsSameButtonAddedTwice_False) {
    auto actionButton0 = ActionButtonFactory::getActionButton(Actions::TEST, langJson);
    ASSERT_EQ(actionButton, actionButton0);
}
