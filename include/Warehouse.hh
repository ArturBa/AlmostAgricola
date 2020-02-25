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
    unsigned int sheep;
    unsigned int food;
public:
    /**
     * @brief Default constructor
     */
    Warehouse();

    /**
     * @brief Get warehouse number of sheep
     * @return number of warehouse sheep
     */
    [[nodiscard]] unsigned int getSheep() const;

    /**
     * @brief Get warehouse number of food
     * @return number of warehouse food units
     */
    [[nodiscard]] unsigned int getFood() const;

    /**
     * @brief Add sheep to warehouse sheep
     * @param sheepNo number of sheep to add
     */
    void addSheep(unsigned int sheepNo = 1);
};


