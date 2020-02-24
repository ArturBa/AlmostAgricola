//
// Created by artur on 24/02/2020.
//
#include <gmock/gmock.h>
#include <Game.hh>

using namespace ::testing;
using namespace std;

class AGame : public Test {
public:

};

TEST_F(AGame, getCurrentPlayer_player0) {
    std::vector players = {
            Player("Player0", PlayerTextureFactory::getPlayerTexture(0)),
            Player("Player1", PlayerTextureFactory::getPlayerTexture(0))
    };
    auto game = Game(players);
    string playerName = game.getCurrentPlayer()->getName();
    string player0Name = "Player0";
    ASSERT_TRUE(player0Name == playerName);
}
