//
// Created by artur on 25/02/2020.
//

#include "Warehouse.hh"

Warehouse::Warehouse() {
    food = 2;
    wheat = vegetable = clay = wood = stone = reed = sheep = swine = cow = 0;
}

unsigned int Warehouse::getFood() const {
    return food;
}

void Warehouse::addFood(unsigned int foodNo) {
    food += foodNo;
}

unsigned int Warehouse::getSheep() const {
    return sheep;
}

void Warehouse::addSheep(unsigned int sheepNo) {
    sheep += sheepNo;
}

unsigned int Warehouse::getWheat() const {
    return wheat;
}

void Warehouse::addWheat(unsigned int wheatNo) {
    wheat += wheatNo;
}

unsigned int Warehouse::getVegetable() const {
    return vegetable;
}

void Warehouse::addVegetable(unsigned int vegetableNo) {
    vegetable += vegetableNo;
}

unsigned int Warehouse::getClay() const {
    return clay;
}

void Warehouse::addClay(unsigned int clayNo) {
    clay += clayNo;
}

unsigned int Warehouse::getWood() const {
    return wood;
}

void Warehouse::addWood(unsigned int WoodNo) {
    wood += WoodNo;
}

unsigned int Warehouse::getStone() const {
    return stone;
}

void Warehouse::addStone(unsigned int StoneNo) {
    stone += StoneNo;
}

unsigned int Warehouse::getReed() const {
    return reed;
}

void Warehouse::addReed(unsigned int ReedNo) {
    reed += ReedNo;
}

unsigned int Warehouse::getSwine() const {
    return swine;
}

void Warehouse::addSwine(unsigned int SwineNo) {
    swine += SwineNo;
}

unsigned int Warehouse::getCow() const {
    return cow;
}

void Warehouse::addCow(unsigned int CowNo) {
    cow += CowNo;
}
