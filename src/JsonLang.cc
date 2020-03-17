//
// Created by artur on 19/02/2020.
//

#include "JsonLang.hh"
#include <iostream>


JsonLang::JsonLang(Settings *_settings) : Observer(_settings) {
    settings = _settings;
    textJson = nullptr;
}

std::string JsonLang::getText(const std::string &key, const std::string &default_value) {
    if (textJson == nullptr) {
        char fileNameBuffer[64];
        sprintf(fileNameBuffer, "../res/lang/%s.json", settings->getLang().c_str());
        textJson = LoadJsonFromFile(fileNameBuffer);
    }
    std::string result = textJson->value(key, default_value);
    if (result == "null") {
        std::cerr << "Cannot find a text value for key: " << key << '\n';
    }
    return result;
}

void JsonLang::update() {
    delete textJson;
    textJson = nullptr;
}
