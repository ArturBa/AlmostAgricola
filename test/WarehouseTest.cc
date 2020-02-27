//
// Created by artur on 26/02/2020.
//
#include <gmock/gmock.h>
#include <Warehouse.hh>

using namespace ::testing;
using namespace std;

class AWarehouse : public Test {
public:
    AWarehouse() : warehouse() {}

    Warehouse warehouse;
};

TEST_F(AWarehouse, CheckInitValue) {
    ASSERT_EQ(2, warehouse.food.getResource());
    ASSERT_EQ(0, warehouse.wheat.getResource());
    ASSERT_EQ(0, warehouse.vegetable.getResource());
    ASSERT_EQ(0, warehouse.clay.getResource());
    ASSERT_EQ(0, warehouse.wood.getResource());
    ASSERT_EQ(0, warehouse.stone.getResource());
    ASSERT_EQ(0, warehouse.reed.getResource());
    ASSERT_EQ(0, warehouse.sheep.getResource());
    ASSERT_EQ(0, warehouse.swine.getResource());
    ASSERT_EQ(0, warehouse.cow.getResource());
}
