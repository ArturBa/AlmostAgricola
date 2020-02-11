//
// Created by bauer on 2/11/20.
//
#include <gmock/gmock.h>
#include <Player.hh>

using namespace ::testing;
using namespace std;

class APlayer : public Test {
public:
    APlayer() : player("Player Name", 0) {}

    Player player;
};

TEST_F(APlayer, GetImageId_Initial_0) {
    ASSERT_EQ(player.getImageId(), 0);
}

TEST_F(APlayer, GetPlayerName_Initial_PlayerName) {
    EXPECT_EQ(player.getName(), "Player Name");
}
