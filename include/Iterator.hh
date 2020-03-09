/**
 * @brief File containing Iterator class
 * @file Iterator.hh
 * @author Artur Bauer
 * @date 03 Mar 2020
 * @version 0.10.7
 *
 * File contain all required information for Iterator class.
 * This class with class AbstractList creates interface for Iterator design pattern
 */
#pragma once

#include <string>

template<class Item>
class AbstractList;

/**
 * @class Iterator
 * @brief Class creating interface for Iterator design pattern
 * @tparam Item class to iterate over
 */
template<class Item>
class Iterator {
public:
    /**
     * @brief Set iterator to position 0
     */
    virtual void First() = 0;

    /**
     * @brief Move iterator to the next position
     */
    virtual void Next() = 0;

    /**
     * @brief Check if this is out of range
     * @return True if index out of range
     */
    [[nodiscard]] virtual bool isDone() const = 0;

    /**
     * @brief Return Item under current position
     * @throws IteratorOutOfBonds if trying to get Item out of range
     * @return Item under current position
     */
    virtual Item currentItem() const = 0;

protected:
//    virtual explicit Iterator(const AbstractList<Item> *_abstractList) = 0;

    friend class AbstractList<Item>;

};


/**
 * @class IteratorOutOfBounds
 * @brief Class to call if trying to get Item out of range
 */
class IteratorOutOfBounds : public std::exception {
    std::string errorMsg = "Iterator out of range";
public:
    IteratorOutOfBounds() = default;

    /**
     * Get the message
     * @return error message
     */
    std::string what() {
        return errorMsg;
    }
};