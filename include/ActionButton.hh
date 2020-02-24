//
// Created by artur on 18/02/2020.
//

#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <map>

#include "JsonLang.hh"
#include "Actions.hh"

#define ACTION_BUTTON_WIDTH 64
#define ACTION_BUTTON_HEIGHT 128

class ActionButtonFactory;

/**
 * @class ActionButton
 * @brief Class containing Textures and texts for action buttons
 */
class ActionButton {
public:
    /**
     * @brief Get texture of a button
     * @return button texture
     */
    const sf::Texture &getTexture() const;

    /**
     * @brief Get action text description
     * @return Text description
     */
    const std::string &getText() const;

private:
    sf::Texture texture;
    std::string text;

    explicit ActionButton(Actions action, JsonLang &langJson);

    friend ActionButtonFactory;

    std::string getJsonText(JsonLang &langJson, const Actions &action);
};


/**
 * @class ActionButtonFactory
 * @brief Class for creating and managing ActionButton
 */
class ActionButtonFactory {
public:
    /**
     * @brief Get action button
     * @param action Action which does action button
     * @return action button pointer
     */
    static ActionButton *getActionButton(Actions action, JsonLang &langJson);

private:
    static std::map<Actions, ActionButton *> mapOfActionButtons;

};
