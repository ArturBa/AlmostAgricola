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

#include "JsonLang.hh"
#include "Actions.hh"

#define BUTTON_WIDTH 64
#define BUTTON_HEIGHT 128

class ActionButtonFactory;

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

    explicit ActionButton(Actions action, JsonLang &langJson);

    friend ActionButtonFactory;

    std::string getJsonText(JsonLang &langJson, const Actions &action);
};


class ActionButtonFactory {
public:
    /**
     * Get action button
     * @param action Action which does action button
     * @return action button pointer
     */
    static ActionButton *getActionButton(Actions action, JsonLang &langJson);

private:
    static std::map<Actions, ActionButton *> mapOfActionButtons;

};
