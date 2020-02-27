//
// Created by artur on 24/02/2020.
//
#include <gmock/gmock.h>
#include <Game.hh>

using namespace ::testing;
using namespace std;

class AGame : public Test {
public:
    AGame() {
        auto players = new std::vector<Player>;
        players->reserve(2);
        players->emplace_back("Player0", PlayerTextureFactory::getPlayerTexture(0));
        players->emplace_back("Player1", PlayerTextureFactory::getPlayerTexture(1));
        game = new Game(players);
    }

    Game *game;

};

TEST_F(AGame, getCurrentPlayer_player0) {
    string playerName = game->getCurrentPlayer()->getName();
    string player0Name = "Player0";
    ASSERT_EQ(player0Name, playerName);
}
