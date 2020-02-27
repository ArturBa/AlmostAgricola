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

    static unsigned int ADD_VALUE;
    Warehouse warehouse;
};

unsigned int AWarehouse::ADD_VALUE = 2;

TEST_F(AWarehouse, GetFood_init_2) {
    ASSERT_EQ(2, warehouse.getFood());
}

TEST_F(AWarehouse, GetWheat_AddWheat) {
    ASSERT_EQ(0, warehouse.getWheat());
    warehouse.addWheat(ADD_VALUE);
    ASSERT_EQ(ADD_VALUE, warehouse.getWheat());
}

TEST_F(AWarehouse, GetVegetable_AddVegetable) {
    ASSERT_EQ(0, warehouse.getVegetable());
    warehouse.addVegetable(ADD_VALUE);
    ASSERT_EQ(ADD_VALUE, warehouse.getVegetable());
}

TEST_F(AWarehouse, GetClay_AddClay) {
    ASSERT_EQ(0, warehouse.getClay());
    warehouse.addClay(ADD_VALUE);
    ASSERT_EQ(ADD_VALUE, warehouse.getClay());
}

TEST_F(AWarehouse, GetSheep_AddSheep) {
    ASSERT_EQ(0, warehouse.getSheep());
    warehouse.addSheep(ADD_VALUE);
    ASSERT_EQ(ADD_VALUE, warehouse.getSheep());
}

