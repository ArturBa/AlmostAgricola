/**
 * @brief File containing PlayerIterator class
 * @file PlayerIterator.hh
 * @author Artur Bauer
 * @date 03 Mar 2020
 * @version 0.10.7
 *
 *
 * File contain all required information for PlayerIterator class.
 * This class is derived Iterator
 */
#pragma once

#include "Iterator.hh"

template<class Item>
class PlayerList;

/**
 * @class PlayerIterator
 * @brief Class derived from Iterator
 * @tparam Item class to iterate over
 */
template<class Item>
class PlayerIterator : public Iterator<Item> {
private:
    friend class PlayerList<Item>;

    const PlayerList<Item> *playerList;
    long current;

    explicit PlayerIterator(const PlayerList<Item> *_playerList);

public:

    void First() override;

    void Next() override;

    [[nodiscard]] bool isDone() const override;

    Item currentItem() const override;

};

template<class Item>
PlayerIterator<Item>::PlayerIterator(const PlayerList<Item> *_playerList) : playerList(_playerList), current(0) {

}

template<class Item>
void PlayerIterator<Item>::First() {
    current = 0;
}

template<class Item>
void PlayerIterator<Item>::Next() {
    current++;
}

template<class Item>
bool PlayerIterator<Item>::isDone() const {
    return current >= playerList->getCount();
}

template<class Item>
Item PlayerIterator<Item>::currentItem() const {
    if (isDone()) {
        throw IteratorOutOfBounds();
    }
    return playerList->get(current);
}

