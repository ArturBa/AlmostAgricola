/**
 * @brief File containing PlayerList class
 * @file PlayerList.hh
 * @author Artur Bauer
 * @date 03 Mar 2020
 * @version 0.10.7
 *
 *
 * File contain all required information for PlayerList class.
 * This class is derived AbstractList
 */
#pragma once

#include "AbstractList.hh"
#include "PlayerIterator.hh"
#include <vector>

/**
 * @class PlayerList
 * @brief Class derived from AbstractList
 * @tparam Item class to iterate over
 */
template<class Item>
class PlayerList : public AbstractList<Item> {
private:
    std::vector<Item> playerList;
public:
    /**
     * Default constructor
     * @param size initial size reserved for Item
     */
    explicit PlayerList(long size = DEFAULT_LIST_CAPACITY);

    [[nodiscard]] long getCount() const override;

    Item get(long index) const override;

    PlayerIterator<Item> *createIterator() const override;

    void add(Item _item) override;
};

template<class Item>
PlayerList<Item>::PlayerList(long size) {
    playerList.reserve(size);
}

template<class Item>
[[nodiscard]] long PlayerList<Item>::getCount() const {
    return playerList.size();
}

template<class Item>
Item PlayerList<Item>::get(long index) const {
    return playerList.at(index);
}

template<class Item>
[[nodiscard]] PlayerIterator<Item> *PlayerList<Item>::createIterator() const {
    return new PlayerIterator(this);
}

template<class Item>
void PlayerList<Item>::add(Item _item) {
    playerList.push_back(_item);
}

