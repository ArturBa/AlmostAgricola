//
// Created by artur on 27/02/2020.
//

#pragma once


/**
 * @class Resource
 * @brief Class for handling resource
 */
class Resource {
private:
    unsigned int value;
public:
    /**
     * @brief Get warehouse number of resource
     * @return number of warehouse resource units
     */
    [[nodiscard]] unsigned int getResource() const;

    /**
     * @brief Add sheep to warehouse sheep
     * @param sheepNo number of sheep to add
     */
    void addResource(unsigned int resourceNo = 1);

    /**
     * Decrease resource value
     * @param resourceNo value to decrease. Default = 1
     * @return true if success
     */
    bool decreaseResource(unsigned int resourceNo = 1);

};


