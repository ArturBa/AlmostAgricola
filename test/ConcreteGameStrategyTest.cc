/**
 * @brief tests for concrete game strategy
 * @file ConcreteGameStrategyTest.cc
 * @author artur
 * @date 29/04/2020
 * @version 
 *
 * Test for concrete game strategy
 */


#include <gmock/gmock.h>
#include <ConcreteGameStrategy.hh>
#include <Actions.hh>
#include <Player.hh>

using namespace ::testing;
using namespace std;

class AConcreteGameStrategy : public Test {
public:
    AConcreteGameStrategy() {
        gameStrategy = new ConcreteGameStrategy();
    }

    ConcreteGameStrategy *gameStrategy;
};

TEST_F(AConcreteGameStrategy, initActive) {
    ASSERT_TRUE(gameStrategy->getMapOfActions().at(Actions::GET_2_FOOD).first);
    ASSERT_TRUE(gameStrategy->getMapOfActions().at(Actions::GET_SHEEP).first);
    ASSERT_FALSE(gameStrategy->getMapOfActions().at(Actions::WEEK_1_0).first);
}

TEST_F(AConcreteGameStrategy, nextTourActive) {
    gameStrategy->generateNextTourAction();
    ASSERT_TRUE(gameStrategy->getMapOfActions().at(Actions::GET_2_FOOD).first);
    ASSERT_TRUE(gameStrategy->getMapOfActions().at(Actions::GET_SHEEP).first);
    ASSERT_TRUE(gameStrategy->getMapOfActions().at(Actions::WEEK_1_0).first);
}

TEST_F(AConcreteGameStrategy, playerAction) {
    auto player = new Player("user", PlayerTextureFactory::getPlayerTexture(0));
    gameStrategy->selectAction(Actions::GET_2_FOOD, player);
    ASSERT_EQ(gameStrategy->getMapOfActions().at(Actions::GET_2_FOOD).second, player);
}
