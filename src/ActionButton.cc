//
// Created by artur on 18/02/2020.
//
#include <JsonLang.hh>
#include "ActionButton.hh"

std::string ActionButton::getJsonText(JsonLang &langJson, const Actions &action) {
    return langJson.getText(getActionFileName(action));
}

std::map<Actions, ActionButton *> ActionButtonFactory::mapOfActionButtons;

ActionButton *ActionButtonFactory::getActionButton(Actions action, JsonLang &langJson) {
    auto searchActionButton = mapOfActionButtons.find(action);
    if (searchActionButton != mapOfActionButtons.end()) {
        return searchActionButton->second;
    } else {
        mapOfActionButtons.insert(std::pair<Actions, ActionButton *>{action, new ActionButton(action, langJson)});
        return mapOfActionButtons.at(action);
    }
}

ActionButton::ActionButton(const Actions action, JsonLang &langJson) :
        text(ActionButton::getJsonText(langJson, action)) {
    char fileNameBuffer[64];
    sprintf(fileNameBuffer, "../res/img/action_button/%s.png", getActionFileName(action).c_str());
    texture.loadFromFile(fileNameBuffer);
}

const sf::Texture &ActionButton::getTexture() const {
    return texture;
}

const std::string &ActionButton::getText() const {
    return text;
}


