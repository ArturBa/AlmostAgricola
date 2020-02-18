//
// Created by artur on 18/02/2020.
//
#include "ActionButton.hh"

std::map<std::string, ActionButton *> ActionButtonFactory::mapOfActionButtons;

ActionButton *ActionButtonFactory::getActionButton(const std::string &actionName) {
    auto searchActionButton = mapOfActionButtons.find(actionName);
    if (searchActionButton != mapOfActionButtons.end()) {
        return searchActionButton->second;
    } else {
        mapOfActionButtons.insert(std::pair<std::string, ActionButton *>{actionName, new ActionButton(actionName)});
        return mapOfActionButtons.at(actionName);
    }
}

ActionButton::ActionButton(const std::string &actionName) :
        text(actionName) {
    char fileNameBuffer[64];
    sprintf(fileNameBuffer, "../res/img/action_button/%s.png", actionName.c_str());
    texture.loadFromFile(fileNameBuffer);
}

const sf::Texture &ActionButton::getTexture() const {
    return texture;
}

const std::string &ActionButton::getText() const {
    return text;
}

