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

TEST_F(APlayer, SetFarm_Correctly) {
    ASSERT_TRUE(player.setFarm(2, 0, FarmEnum::WoodHouse));
}

TEST_F(APlayer, SetFarm_AwayFromHouse) {
    ASSERT_FALSE(player.setFarm(3, 0, FarmEnum::WoodHouse));
}

TEST_F(APlayer, SetFarm_OverrideHouse) {
    ASSERT_FALSE(player.setFarm(0, 0, FarmEnum::WoodHouse));
}

TEST_F(APlayer, SetFarm_OutsideField) {
    ASSERT_FALSE(player.setFarm(7, 7, FarmEnum::WoodHouse));
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

TEST_F(APlayer, UpgradeHouseToClay_NoMaterials) {
    ASSERT_FALSE(player.upgradeHouseClay());
}

TEST_F(APlayer, UpgradeHouseToClay_WithMaterials) {
    player.warehouse->clay.addResource(4);
    player.warehouse->reed.addResource();
    ASSERT_TRUE(player.upgradeHouseClay());
}

TEST_F(APlayer, UpgradeHouseToClay_DoubleUpgrade) {
    player.warehouse->clay.addResource(8);
    player.warehouse->reed.addResource(2);
    player.upgradeHouseClay();

    ASSERT_FALSE(player.upgradeHouseClay());
}

TEST_F(APlayer, UpgradeHouseToStone_NoMaterials) {
    ASSERT_FALSE(player.upgradeHouseStone());
}

TEST_F(APlayer, UpgradeHouseToStone_WithMaterials_NoClayUpgrade) {
    player.warehouse->stone.addResource(4);
    player.warehouse->reed.addResource();
    ASSERT_FALSE(player.upgradeHouseStone());
}

TEST_F(APlayer, UpgradeHouseToStone_WithMaterials_WithClayUpgrade) {
    player.warehouse->clay.addResource(4);
    player.warehouse->stone.addResource(4);
    player.warehouse->reed.addResource(2);
    player.upgradeHouseClay();
    ASSERT_TRUE(player.upgradeHouseStone());
}

TEST_F(APlayer, UpgradeHouseToStone_DoubleUpgrade) {
    player.warehouse->clay.addResource(4);
    player.warehouse->stone.addResource(8);
    player.warehouse->reed.addResource(3);
    player.upgradeHouseClay();
    player.upgradeHouseStone();

    ASSERT_FALSE(player.upgradeHouseStone());
}

TEST_F(APlayer, GetFarmInitial) {
    std::map<FarmEnum, int> expectedFarmCount = {
            {FarmEnum::WoodHouse, 2},
            {FarmEnum::Grass,     22}
    };
    auto farm = player.getFarm();
    std::map<FarmEnum, int> actualFarmCount;
    for (const auto &y: farm) {
        for (const auto &x: y) {
            try {
                actualFarmCount.at(x)++;
            } catch (...) {
                actualFarmCount.insert({x, 1});
            }
        }
    }
    ASSERT_EQ(expectedFarmCount, actualFarmCount);
}

TEST_F(APlayer, GetFarmClayUpgrade) {
    std::map<FarmEnum, int> expectedFarmCount = {
            {FarmEnum::ClayHouse, 2},
            {FarmEnum::Grass,     22}
    };
    player.warehouse->clay.addResource(4);
    player.warehouse->reed.addResource();
    player.upgradeHouseClay();
    auto farm = player.getFarm();
    std::map<FarmEnum, int> actualFarmCount;
    for (const auto &y: farm) {
        for (const auto &x: y) {
            try {
                actualFarmCount.at(x)++;
            } catch (...) {
                actualFarmCount.insert({x, 1});
            }
        }
    }
    ASSERT_EQ(expectedFarmCount, actualFarmCount);
}

TEST_F(APlayer, GetFarmStoneUpgrade) {
    std::map<FarmEnum, int> expectedFarmCount = {
            {FarmEnum::StoneHouse, 2},
            {FarmEnum::Grass,      22}
    };
    player.warehouse->stone.addResource(4);
    player.warehouse->clay.addResource(4);
    player.warehouse->reed.addResource(2);
    player.upgradeHouseClay();
    player.upgradeHouseStone();
    auto farm = player.getFarm();
    std::map<FarmEnum, int> actualFarmCount;
    for (const auto &y: farm) {
        for (const auto &x: y) {
            try {
                actualFarmCount.at(x)++;
            } catch (...) {
                actualFarmCount.insert({x, 1});
            }
        }
    }
    ASSERT_EQ(expectedFarmCount, actualFarmCount);
}

TEST_F(APlayer, GetRequiredFood_2FamilyMembers) {
    ASSERT_EQ(4, player.getFoodRequired());
}

TEST_F(APlayer, GetRequiredFood_3FamilyMembers) {
    player.addFamilyMemberNoPlace();
    ASSERT_EQ(6, player.getFoodRequired());
}

TEST_F(APlayer, FeedFamily_2FamilyMembers) {
    player.harvest();
    ASSERT_EQ(0, player.warehouse->food.getResource());
    ASSERT_EQ(1, player.warehouse->begCards.getResource());
}

TEST_F(APlayer, FeedFamily_3FamilyMembers) {
    player.addFamilyMemberNoPlace();
    player.harvest();
    ASSERT_EQ(0, player.warehouse->food.getResource());
    ASSERT_EQ(2, player.warehouse->begCards.getResource());
}

TEST_F(APlayer, FeedFamily_3FamilyMembers_EvenFoodNo) {
    player.warehouse->food.addResource();
    player.addFamilyMemberNoPlace();
    player.harvest();
    ASSERT_EQ(1, player.warehouse->food.getResource());
    ASSERT_EQ(2, player.warehouse->begCards.getResource());
}

