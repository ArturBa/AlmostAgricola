/**
 * @file PlayerIteratorTest.cc
 * @author Artur Bauer
 * @date 09/03/2020
 * @brief Tests for PlayerIterator
 *
 */

#include <gmock/gmock.h>
#include <PlayerIterator.hh>
#include <PlayerList.hh>
#include <Player.hh>

using namespace ::testing;
using namespace std;

class APlayerIterator : public Test {
public:
    APlayerIterator() :
            players({new Player("a", PlayerTextureFactory::getPlayerTexture(0)),
                     new Player("b", PlayerTextureFactory::getPlayerTexture(0)),
                     new Player("c", PlayerTextureFactory::getPlayerTexture(0))
                    }) {
        playerList = new PlayerList<Player *>();
        playerList->add(players.at(0));
        playerList->add(players.at(1));
        playerList->add(players.at(2));
        playerIterator = playerList->createIterator();
    }

    ~APlayerIterator() {
        for (auto &player: players) {
            delete player;
        }
        delete playerList;
        delete playerIterator;
    }

    std::vector<Player *> players;
    PlayerList<Player *> *playerList;
    PlayerIterator<Player *> *playerIterator;
};

TEST_F(APlayerIterator, CheckInitValues) {
    ASSERT_EQ(players.at(0)->getName(), playerIterator->currentItem()->getName());
}

TEST_F(APlayerIterator, CheckInitSize) {
    ASSERT_EQ(players.size(), playerList->getCount());
}

TEST_F(APlayerIterator, Next_Player) {
    playerIterator->next();
    ASSERT_EQ(players.at(1)->getName(), playerIterator->currentItem()->getName());
}

TEST_F(APlayerIterator, Next_Throw) {
    for (const auto player: players) {
        playerIterator->next();
    }
    ASSERT_THROW(playerIterator->currentItem(), IteratorOutOfBounds);
}

TEST_F(APlayerIterator, First_Player) {
    playerIterator->next();
    playerIterator->first();
    ASSERT_EQ(players.at(0)->getName(), playerIterator->currentItem()->getName());
}

TEST_F(APlayerIterator, IsDone_False) {
    ASSERT_FALSE(playerIterator->isDone());
}

TEST_F(APlayerIterator, IsDone_True) {
    for (const auto player: players) {
        playerIterator->next();
    }
    ASSERT_TRUE(playerIterator->isDone());
}
