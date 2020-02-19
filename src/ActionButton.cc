//
// Created by artur on 18/02/2020.
//
#include "ActionButton.hh"

nlohmann::json *ActionButtonJson::textJson;

ActionButtonJson::ActionButtonJson() {
    textJson = LoadJsonFromFile("../res/lang/eng/actions.json");
}

std::string ActionButtonJson::getText(const Actions &action, const std::string &default_value = "null") {
    if (textJson == nullptr) {
        ActionButtonJson();
    }
    return textJson->value(getActionFileName(action), default_value);
}

std::map<Actions, ActionButton *> ActionButtonFactory::mapOfActionButtons;

ActionButton *ActionButtonFactory::getActionButton(const Actions action) {
    auto searchActionButton = mapOfActionButtons.find(action);
    if (searchActionButton != mapOfActionButtons.end()) {
        return searchActionButton->second;
    } else {
        mapOfActionButtons.insert(std::pair<Actions, ActionButton *>{action, new ActionButton(action)});
        return mapOfActionButtons.at(action);
    }
}

ActionButton::ActionButton(const Actions action) :
        text(ActionButtonJson::getText(action)) {
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

