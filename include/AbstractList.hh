/**
 * @brief File containing AbstractList class
 * @file AbstractList.hh
 * @author Artur Bauer
 * @date 03 Mar 2020
 * @version 0.10.7
 *
 *
 * File contain all required information for AbstractList class.
 * This class with class Iterator creates interface for Iterator design pattern
 */
#pragma once

#define DEFAULT_LIST_CAPACITY 8

template<class Item>
class Iterator;

/**
 * @class AbstractList
 * @brief Class creating interface for Iterator design pattern
 * @tparam Item class to iterate over
 */
template<class Item>
class AbstractList {
public:
    /**
     * Get number of Items
     * @return number of Items
     */
    [[nodiscard]] virtual long getCount() const = 0;

    /**
     * Get Item under selected index
     * @param index Index of Item
     * @return Item under selected index
     */
    virtual Item get(long index) const = 0;

    /**
     * Create iterator
     * @return Iterator pointer
     */
    virtual Iterator<Item> *createIterator() const = 0;

    /**
     * Add item to iterate over
     * @param _item Item to add
     */
    virtual void add(Item _item) = 0;
};

