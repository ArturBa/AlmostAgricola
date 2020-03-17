//
// Created by artur on 29/01/2020.
//
#include <gmock/gmock.h>
#include <Model.hh>

using namespace ::testing;
using namespace std;

class AModel : public Test {
public:
    Model model;

    AModel() : model() {};
};

TEST_F(AModel, NewGame_CheckCurrentPlayer) {
    auto players = new std::vector<Player *>;
    players->reserve(2);
    players->emplace_back(new Player("Player0", PlayerTextureFactory::getPlayerTexture(0)));
    players->emplace_back(new Player("Player1", PlayerTextureFactory::getPlayerTexture(1)));

    model.newGame(players);

    string playerName = model.getCurrentPlayer()->getName();
    string player0Name = "Player0";
    ASSERT_EQ(player0Name, playerName);
}
