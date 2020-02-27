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
    ASSERT_EQ(0, player.warehouse->sheep.getResource());
}

TEST_F(APlayer, AddSheep_Init_0) {
    player.warehouse->sheep.addResource();
    ASSERT_EQ(1, player.warehouse->sheep.getResource());
    player.warehouse->sheep.addResource(3);
    ASSERT_EQ(1 + 3, player.warehouse->sheep.getResource());
}

TEST_F(APlayer, GetFoodNo_Init_2) {
    ASSERT_EQ(2, player.warehouse->food.getResource());
}

TEST_F(APlayer, TransformSheepIntoFood_2) {
    auto playerFoodBefore = player.warehouse->food.getResource();
    player.transformSheepIntoFood();
    ASSERT_EQ(playerFoodBefore + 2, player.warehouse->food.getResource());
}

TEST_F(APlayer, TransformMultipleSheepIntoFood_2) {
    auto playerFoodBefore = player.warehouse->food.getResource();
    player.transformSheepIntoFood(2);
    ASSERT_EQ(playerFoodBefore + 2 * 2, player.warehouse->food.getResource());
}

TEST_F(APlayer, TransformSheepIntoFood_AfterUpgrade_2) {
    auto playerFoodBefore = player.warehouse->food.getResource();
    player.addUpgrade(UpgradeEnum::Kitchen_0);
    player.transformSheepIntoFood();
    ASSERT_EQ(playerFoodBefore + 3, player.warehouse->food.getResource());
    player.addUpgrade(UpgradeEnum::Kitchen_2);
    player.transformSheepIntoFood();
    ASSERT_EQ(playerFoodBefore + 3 + 4, player.warehouse->food.getResource());
}

TEST_F(APlayer, AddFamilyMember_WithPlace) {
    for (int i = 0; i < 5; ++i) {
        player.setFarm(i, 0, FarmEnum::WoodHouse);
    }
    player.addFamilyMember();
    ASSERT_EQ(3, player.getFamilyMembers());
    player.addFamilyMember();
    player.addFamilyMember();
    player.addFamilyMember();
    ASSERT_EQ(5, player.getFamilyMembers());
}

TEST_F(APlayer, AddFamilyMemberNoPlace_Success) {
    player.addFamilyMemberNoPlace();
    ASSERT_EQ(3, player.getFamilyMembers());
    player.addFamilyMemberNoPlace();
    player.addFamilyMemberNoPlace();
    player.addFamilyMemberNoPlace();
    ASSERT_EQ(5, player.getFamilyMembers());
}

TEST_F(APlayer, AddFamilyMember_NoPlace) {
    player.addFamilyMember();
    ASSERT_EQ(2, player.getFamilyMembers());
}