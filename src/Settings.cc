//
// Created by artur on 19/02/2020.
//

#include "Settings.hh"

void Settings::updateSettings() {
    notify();
    SaveJsonToFile(*settingsJson, "../res/cnf/settings.json");
}

sf::Vector2u Settings::getSize() {
    return mapOfResolutions.at(resHor);
}

Settings::Settings() {
    settingsJson = LoadJsonFromFile("../res/cnf/settings.json");
    lang = settingsJson->value("lang", "eng");
    resHor = settingsJson->value("res", 800);
}

const std::string &Settings::getLang() const {
    return lang;
}

int Settings::getResHor() const {
    return resHor;
}

void Settings::setLang(const std::string &_lang) {
    lang = _lang;
    settingsJson->at("lang") = _lang;
    updateSettings();
}

void Settings::setResHor(int _resHor) {
    if (mapOfResolutions.find(_resHor) != mapOfResolutions.end())
        resHor = _resHor;
    else
        resHor = 800;
    settingsJson->at("res") = _resHor;
    updateSettings();
}
