//
// Created by artur on 02/03/2020.
//
#include <gmock/gmock.h>
#include <Points.hh>

using namespace ::testing;
using namespace std;

class APoints : public Test {
public:
    APoints() {
        player = new Player("Player Name", PlayerTextureFactory::getPlayerTexture(0));
        points = new Points(player);
    }

    Player *player;
    Points *points;
};

TEST_F(APoints, CheckInitHousePoints) {
    ASSERT_EQ(0, points->getHouse());
}

TEST_F(APoints, CheckClayHouse) {
    player->warehouse->clay.addResource(4);
    player->warehouse->reed.addResource();
    player->upgradeHouseClay();
    ASSERT_EQ(2, points->getHouse());
}

TEST_F(APoints, CheckStoneHouse) {
    player->warehouse->clay.addResource(4);
    player->warehouse->stone.addResource(4);
    player->warehouse->reed.addResource(2);
    player->upgradeHouseClay();
    player->upgradeHouseStone();
    ASSERT_EQ(4, points->getHouse());
}

TEST_F(APoints, getSheep_0__1) {
    ASSERT_EQ(-1, points->getSheep());
}

TEST_F(APoints, getSheep_1_1) {
    player->warehouse->sheep.addResource(1);
    ASSERT_EQ(1, points->getSheep());
}

TEST_F(APoints, getSheep_4_2) {
    player->warehouse->sheep.addResource(4);
    ASSERT_EQ(2, points->getSheep());
}

TEST_F(APoints, getSheep_6_3) {
    player->warehouse->sheep.addResource(6);
    ASSERT_EQ(3, points->getSheep());
}

TEST_F(APoints, getSheep_8_4) {
    player->warehouse->sheep.addResource(8);
    ASSERT_EQ(4, points->getSheep());
}

TEST_F(APoints, getFamilyMembers_2_6) {
    ASSERT_EQ(6, points->getFamilyMembers());
}

TEST_F(APoints, getFamilyMembers_3_9) {
    player->addFamilyMemberNoPlace();
    ASSERT_EQ(9, points->getFamilyMembers());
}

TEST_F(APoints, getFamilyMembers_4_12) {
    player->addFamilyMemberNoPlace();
    player->addFamilyMemberNoPlace();
    ASSERT_EQ(12, points->getFamilyMembers());
}

TEST_F(APoints, getFamilyMembers_5_15) {
    player->addFamilyMemberNoPlace();
    player->addFamilyMemberNoPlace();
    player->addFamilyMemberNoPlace();
    ASSERT_EQ(15, points->getFamilyMembers());
}
