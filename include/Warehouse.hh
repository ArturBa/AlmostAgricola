//
// Created by artur on 25/02/2020.
//

#pragma once


/**
 * @class Warehouse
 * @brief Class for warehouse status
 */
class Warehouse {
protected:
    unsigned int food;
    unsigned int wheat;
    unsigned int vegetable;
    unsigned int clay;
    unsigned int wood;
    unsigned int stone;
    unsigned int reed;
    unsigned int sheep;
    unsigned int swine;
    unsigned int cow;

public:
    /**
     * @brief Default constructor
     */
    Warehouse();


    /**
     * @brief Get warehouse number of food
     * @return number of warehouse food units
     */
    [[nodiscard]] unsigned int getFood() const;

    /**
     * @brief Add sheep to warehouse sheep
     * @param sheepNo number of sheep to add
     */
    void addFood(unsigned int foodNo = 1);

    /**
     * @brief Get warehouse number of wheat
     * @return number of warehouse wheat units
     */
    [[nodiscard]] unsigned int getWheat() const;

    /**
     * @brief Add wheat to warehouse wheat
     * @param wheatNo number of wheat to add
     */
    void addWheat(unsigned int wheatNo = 1);

    /**
     * @brief Get warehouse number of Vegetable
     * @return number of warehouse Vegetable units
     */
    [[nodiscard]] unsigned int getVegetable() const;

    /**
     * @brief Add vegetable to warehouse vegetable
     * @param vegetableNo number of vegetable to add
     */
    void addVegetable(unsigned int vegetableNo = 1);

    /**
     * @brief Get warehouse number of clay
     * @return number of warehouse clay
     */
    [[nodiscard]] unsigned int getClay() const;

    /**
     * @brief Add clay to warehouse clay
     * @param clayNo number of clay to add
     */
    void addClay(unsigned int clayNo = 1);

    /**
     * @brief Get warehouse number of wood
     * @return number of warehouse wood
     */
    [[nodiscard]] unsigned int getWood() const;

    /**
     * @brief Add wood to warehouse wood
     * @param woodNo number of wood to add
     */
    void addWood(unsigned int woodNo = 1);


    /**
     * @brief Get warehouse number of stone
     * @return number of warehouse stone
     */
    [[nodiscard]] unsigned int getStone() const;

    /**
     * @brief Add stone to warehouse stone
     * @param stoneNo number of stone to add
     */
    void addStone(unsigned int stoneNo = 1);

    /**
     * @brief Get warehouse number of reed
     * @return number of warehouse reed
     */
    [[nodiscard]] unsigned int getReed() const;

    /**
     * @brief Add Reed to warehouse Reed
     * @param ReedNo number of Reed to add
     */
    void addReed(unsigned int ReedNo = 1);

    /**
     * @brief Get warehouse number of sheep
     * @return number of warehouse sheep
     */
    [[nodiscard]] unsigned int getSheep() const;

    /**
     * @brief Add sheep to warehouse sheep
     * @param sheepNo number of sheep to add
     */
    void addSheep(unsigned int sheepNo = 1);

    /**
     * @brief Get warehouse number of swine
     * @return number of warehouse swine
     */
    [[nodiscard]] unsigned int getSwine() const;

    /**
     * @brief Add swine to warehouse swine
     * @param swineNo number of swine to add
     */
    void addSwine(unsigned int swineNo = 1);

    /**
     * @brief Get warehouse number of cow
     * @return number of warehouse cow
     */
    [[nodiscard]] unsigned int getCow() const;

    /**
     * @brief Add Cow to warehouse Cow
     * @param CowNo number of Cow to add
     */
    void addCow(unsigned int CowNo = 1);

};


