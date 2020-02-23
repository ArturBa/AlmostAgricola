//
// Created by artur on 23/02/2020.
//
#include <gmock/gmock.h>
#include <PlayerTexture.hh>

using namespace ::testing;
using namespace std;

class APlayerTexture : public Test {

};

TEST_F(APlayerTexture, getTexture_AsExpected) {
    sf::Texture expTexture;
    sf::Texture actTexture;
    for (int i = 0; i < PLAYER_TEXTURE_ICON_NUMBER; ++i) {
        expTexture.loadFromFile("../res/img/players_icon.png",
                                {i * PLAYER_TEXTURE_ICON_SIZE, 0, PLAYER_TEXTURE_ICON_SIZE, PLAYER_TEXTURE_ICON_SIZE});
        actTexture = PlayerTextureFactory::getPlayerTexture(i)->getTexture();
        ASSERT_EQ(actTexture.getSize(), expTexture.getSize());
        i++;
        for (unsigned int x = 0; x < actTexture.getSize().x; ++x) {
            for (unsigned int y = 0; y < actTexture.getSize().y; ++y) {
                ASSERT_EQ(actTexture.copyToImage().getPixel(x, y), expTexture.copyToImage().getPixel(x, y));
            }
        }
    }
}

TEST_F(APlayerTexture, getTexture_OverId) {
    sf::Texture expTexture;
    sf::Texture actTexture;
    expTexture.loadFromFile("../res/img/players_icon.png", {0, 0, PLAYER_TEXTURE_ICON_SIZE, PLAYER_TEXTURE_ICON_SIZE});
    actTexture = PlayerTextureFactory::getPlayerTexture(PLAYER_TEXTURE_ICON_NUMBER + 1)->getTexture();
    ASSERT_EQ(actTexture.getSize(), expTexture.getSize());
    for (unsigned int x = 0; x < actTexture.getSize().x; ++x) {
        for (unsigned int y = 0; y < actTexture.getSize().y; ++y) {
            ASSERT_EQ(actTexture.copyToImage().getPixel(x, y), expTexture.copyToImage().getPixel(x, y));
        }
    }
}

TEST_F(APlayerTexture, getPlayerTexture_DoubleSamePointer) {
    auto playerTexture0 = PlayerTextureFactory::getPlayerTexture(0);
    auto playerTexture1 = PlayerTextureFactory::getPlayerTexture(0);
    ASSERT_EQ(playerTexture0, playerTexture1);
}


TEST_F(APlayerTexture, getColorOfAllPlayerTextures) {
    ASSERT_EQ(PlayerTextureFactory::getPlayerTexture(0)->getColor(), sf::Color(0xd5, 0x00, 0xd5));
    ASSERT_EQ(PlayerTextureFactory::getPlayerTexture(1)->getColor(), sf::Color(0xe2, 0xc0, 0x95));
    ASSERT_EQ(PlayerTextureFactory::getPlayerTexture(2)->getColor(), sf::Color(0x00, 0xff, 0x00));
    ASSERT_EQ(PlayerTextureFactory::getPlayerTexture(3)->getColor(), sf::Color(0x00, 0x00, 0xff));
}

TEST_F(APlayerTexture, getColorUnknowPlayer) {
    ASSERT_EQ(PlayerTextureFactory::getPlayerTexture(PLAYER_TEXTURE_ICON_NUMBER + 1)->getColor(),
              sf::Color(100, 100, 100));
}
