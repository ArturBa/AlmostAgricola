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

    [[nodiscard]] unsigned int getClay() const;

    /**
     * @brief Add clay to warehouse clay
     * @param clayNo number of clay to add
     */
    void addClay(unsigned int clayNo = 1);

    [[nodiscard]] unsigned int getWood() const;

    [[nodiscard]] unsigned int getStone() const;

    [[nodiscard]] unsigned int getReed() const;

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

    [[nodiscard]] unsigned int getSwine() const;

    [[nodiscard]] unsigned int getCow() const;

};


