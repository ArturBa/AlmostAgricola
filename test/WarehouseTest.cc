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

TEST_F(AWarehouse, GetFood_AddFood) {
    ASSERT_EQ(2, warehouse.getFood());
    warehouse.addFood(ADD_VALUE);
    ASSERT_EQ(2 + ADD_VALUE, warehouse.getFood());
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

TEST_F(AWarehouse, GetWood_AddWood) {
    ASSERT_EQ(0, warehouse.getWood());
    warehouse.addWood(ADD_VALUE);
    ASSERT_EQ(ADD_VALUE, warehouse.getWood());
}

TEST_F(AWarehouse, GetStone_AddStone) {
    ASSERT_EQ(0, warehouse.getStone());
    warehouse.addStone(ADD_VALUE);
    ASSERT_EQ(ADD_VALUE, warehouse.getStone());
}

TEST_F(AWarehouse, GetReed_AddReed) {
    ASSERT_EQ(0, warehouse.getReed());
    warehouse.addReed(ADD_VALUE);
    ASSERT_EQ(ADD_VALUE, warehouse.getReed());
}

TEST_F(AWarehouse, GetSheep_AddSheep) {
    ASSERT_EQ(0, warehouse.getSheep());
    warehouse.addSheep(ADD_VALUE);
    ASSERT_EQ(ADD_VALUE, warehouse.getSheep());
}

TEST_F(AWarehouse, GetSwine_AddSwine) {
    ASSERT_EQ(0, warehouse.getSwine());
    warehouse.addSwine(ADD_VALUE);
    ASSERT_EQ(ADD_VALUE, warehouse.getSwine());
}

TEST_F(AWarehouse, GetCow_AddCow) {
    ASSERT_EQ(0, warehouse.getCow());
    warehouse.addCow(ADD_VALUE);
    ASSERT_EQ(ADD_VALUE, warehouse.getCow());
}

