//
// Created by bauer on 2/11/20.
//
#include <gmock/gmock.h>
#include <Player.hh>

using namespace ::testing;
using namespace std;

class APlayer : public Test {
public:
    APlayer() : player("Player Name", PlayerTextureFactory::getPlayerTexture(0)) {}

    Player player;
};

TEST_F(APlayer, GetImageId_Initial_0) {
    ASSERT_EQ(player.getPlayerTexture()->getTexture().getSize(),
              PlayerTextureFactory::getPlayerTexture(0)->getTexture().getSize());
}

TEST_F(APlayer, GetPlayerName_Initial_PlayerName) {
    ASSERT_EQ(player.getName(), "Player Name");
}

TEST_F(APlayer, GetSheepNo_Init_0) {
    ASSERT_EQ(0, player.getSheep());
}

TEST_F(APlayer, AddSheep_Init_0) {
    player.addSheep();
    ASSERT_EQ(1, player.getSheep());
    player.addSheep(3);
    ASSERT_EQ(1 + 3, player.getSheep());
}

TEST_F(APlayer, GetFoodNo_Init_2) {
    ASSERT_EQ(2, player.getFood());
}

TEST_F(APlayer, TransformSheepIntoFood_2) {
    auto playerFoodBefore = player.getFood();
    player.transformSheepIntoFood();
    ASSERT_EQ(playerFoodBefore + 2, player.getFood());
}

TEST_F(APlayer, TransformMultipleSheepIntoFood_2) {
    auto playerFoodBefore = player.getFood();
    player.transformSheepIntoFood(2);
    ASSERT_EQ(playerFoodBefore + 2 * 2, player.getFood());
}

TEST_F(APlayer, TransformSheepIntoFood_AfterUpgrade_2) {
    auto playerFoodBefore = player.getFood();
    player.addUpgrade(UpgradeEnum::Kitchen_0);
    player.transformSheepIntoFood();
    ASSERT_EQ(playerFoodBefore + 3, player.getFood());
    player.addUpgrade(UpgradeEnum::Kitchen_2);
    player.transformSheepIntoFood();
    ASSERT_EQ(playerFoodBefore + 3 + 4, player.getFood());
}
