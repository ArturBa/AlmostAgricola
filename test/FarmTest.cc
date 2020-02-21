//
// Created by artur on 21/02/2020.
//
#include <gmock/gmock.h>
#include <Farm.hh>

using namespace ::testing;
using namespace std;

class AFarm : public Test {

};

//TEST(Test, Texture){
//    sf::Texture texture;
//    texture.loadFromFile("../test/res/img/test.png");
//    ASSERT_EQ(sf::Vector2u(2, 2), texture.getSize());
//}

TEST_F(AFarm, DISABLED_CheckTexture) {
    sf::Texture expTexture;
    sf::Texture actTexture;
    int i = 0;
    for (auto farm: FarmEnum()) {
        expTexture.loadFromFile("../res/img/farm.png", {i * FARM_SIZE, 0, FARM_SIZE, FARM_SIZE});
        actTexture = FarmFactory::getFarm(farm)->getImage();
        ASSERT_EQ(actTexture.getSize(), expTexture.getSize());
        for (unsigned int x = 0; x < actTexture.getSize().x; ++x) {
            for (unsigned int y = 0; y < actTexture.getSize().y; ++y) {
                ASSERT_EQ(actTexture.copyToImage().getPixel(x, y), expTexture.copyToImage().getPixel(x, y));
            }
        }
    }
}
