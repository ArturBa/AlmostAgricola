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
        auto players = new std::vector<Player *>;
        players->reserve(2);
        players->emplace_back(new Player("Player0", PlayerTextureFactory::getPlayerTexture(0)));
        players->emplace_back(new Player("Player1", PlayerTextureFactory::getPlayerTexture(1)));
        game = new Game(players);
    }

    Game *game;

};

TEST_F(AGame, getCurrentPlayer_player0) {
    string playerName = game->getCurrentPlayer()->getName();
    string player0Name = "Player0";
    ASSERT_EQ(player0Name, playerName);
}

TEST_F(AGame, getPlayers) {
    string player0Name = "Player0";
    ASSERT_EQ(game->getPlayers()->at(0)->getName(), player0Name);
}

TEST_F(AGame, selectAction) {
    game->selectAction(Actions::GET_SHEEP);

    string playerName = game->getCurrentPlayer()->getName();
    string player0Name = "Player1";
    ASSERT_EQ(player0Name, playerName);
}