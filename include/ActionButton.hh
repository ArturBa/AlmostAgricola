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

#define BUTTON_WIDTH 64
#define BUTTON_HEIGHT 128

class ActionButtonFactory;

class ActionButtonJson {
public:
    static std::string getText(const std::string &key, const std::string &default_value);

    ~ActionButtonJson() = default;

private:
    ActionButtonJson();

    static nlohmann::json *textJson;
};

class ActionButton {
public:
    const sf::Texture &getTexture() const;

    const std::string &getText() const;

private:
    sf::Texture texture;
    std::string text;

    explicit ActionButton(const std::string &actionName);

    friend ActionButtonFactory;

};


class ActionButtonFactory {
public:
    static ActionButton *getActionButton(const std::string &actionName);

private:
    static std::map<std::string, ActionButton *> mapOfActionButtons;

};
