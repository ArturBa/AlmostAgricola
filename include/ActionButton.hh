//
// Created by artur on 18/02/2020.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "imgui-SFML.h"
#include "imgui.h"
#include <imgui_internal.h>
#include <string>
#include <map>

#include "Json.hh"
#include "Actions.hh"

#define BUTTON_WIDTH 64
#define BUTTON_HEIGHT 128

class ActionButtonFactory;

/**
 * @class ActionButtonJson
 * @brief Class containing action descriptions
 */
class ActionButtonJson {
public:
    /**
     * @brief Get text of selected action
     * @param action Selected action
     * @param default_value Default value in case not founded by action key
     * @return Description of action
     */
    static std::string getText(const Actions &action, const std::string &default_value);

    /**
     *@brief Default deconstructor
     */
    ~ActionButtonJson() = default;

private:
    ActionButtonJson();

    static nlohmann::json *textJson;
};

class ActionButton {
public:
    /**
     * Get texture of a button
     * @return button texture
     */
    const sf::Texture &getTexture() const;

    /**
     * Get action text description
     * @return Text description
     */
    const std::string &getText() const;

private:
    sf::Texture texture;
    std::string text;

    explicit ActionButton(Actions action);

    friend ActionButtonFactory;

};


class ActionButtonFactory {
public:
    /**
     * Get action button
     * @param action Action which does action button
     * @return action button pointer
     */
    static ActionButton *getActionButton(const Actions action);

private:
    static std::map<Actions, ActionButton *> mapOfActionButtons;

};
