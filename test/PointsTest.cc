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

struct sheepPointsState {
    int sheepNo;
    int points;

    friend std::ostream &operator<<(std::ostream &os, const sheepPointsState &state) {
        os << "Number of sheep: " << state.sheepNo << " points: " << state.points;
        return os;
    }
};

struct SheepPointsTest : APoints, testing::WithParamInterface<sheepPointsState> {
    SheepPointsTest() {
        player->warehouse->sheep.addResource(GetParam().sheepNo);
    }

    virtual ~ SheepPointsTest() = default;
};

INSTANTIATE_TEST_SUITE_P (APoints, SheepPointsTest,
                          Values(
                                  sheepPointsState{0, -1},
                                  sheepPointsState{1, 1},
                                  sheepPointsState{4, 2},
                                  sheepPointsState{6, 3},
                                  sheepPointsState{8, 4}
                          ));

TEST_P(SheepPointsTest, getSheep) {
    auto as = GetParam();
    EXPECT_EQ(as.points, points->getSheep());
}


struct familyMembersPointsState {
    int familyMembers;
    int points;

    friend std::ostream &operator<<(std::ostream &os, const familyMembersPointsState &state) {
        os << "Number of family members: " << state.familyMembers << " points: " << state.points;
        return os;
    }
};

struct FamilyMembersPointsTest : APoints, testing::WithParamInterface<familyMembersPointsState> {
    FamilyMembersPointsTest() {
        for (unsigned int i = player->getFamilyMembers(); i < GetParam().familyMembers; ++i) {
            player->addFamilyMemberNoPlace();
        }
    }

    virtual ~ FamilyMembersPointsTest() = default;
};

INSTANTIATE_TEST_SUITE_P (APoints, FamilyMembersPointsTest,
                          Values(
                                  familyMembersPointsState{2, 6},
                                  familyMembersPointsState{3, 9},
                                  familyMembersPointsState{4, 12},
                                  familyMembersPointsState{5, 15}
                          ));

TEST_P(FamilyMembersPointsTest, getFamilyMembers) {
    auto as = GetParam();
    EXPECT_EQ(as.points, points->getFamilyMembers());
}

