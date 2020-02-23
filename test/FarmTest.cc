//
// Created by artur on 21/02/2020.
//
#include <gmock/gmock.h>
#include <Farm.hh>

using namespace ::testing;
using namespace std;

class AFarm : public Test {

};

TEST_F(AFarm, CheckTexture) {
    sf::Texture expTexture;
    sf::Texture actTexture;
    int i = 0;
    for (auto farm: FarmEnum()) {
        expTexture.loadFromFile("../res/img/farm.png", {i * FARM_SIZE, 0, FARM_SIZE, FARM_SIZE});
        actTexture = FarmFactory::getFarm(farm)->getImage();
        ASSERT_EQ(actTexture.getSize(), expTexture.getSize());
        i++;
        for (unsigned int x = 0; x < actTexture.getSize().x; ++x) {
            for (unsigned int y = 0; y < actTexture.getSize().y; ++y) {
                ASSERT_EQ(actTexture.copyToImage().getPixel(x, y), expTexture.copyToImage().getPixel(x, y));
            }
        }
    }
}

TEST_F(AFarm, TwiceSameFarm) {
    auto farm_0 = FarmFactory::getFarm(FarmEnum::Grass);
    auto farm_1 = FarmFactory::getFarm(FarmEnum::Grass);
    ASSERT_EQ(farm_0, farm_1);
}
