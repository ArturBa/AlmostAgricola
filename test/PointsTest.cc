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

