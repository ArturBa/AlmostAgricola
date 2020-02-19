//
// Created by artur on 19/02/2020.
//

#include "JsonLang.hh"


JsonLang::JsonLang(Sender *sender) : Observer(sender) {
    textJson = LoadJsonFromFile("../res/lang/eng.json");
}

std::string JsonLang::getText(const std::string &key, const std::string &default_value = "null") {
    if (textJson == nullptr) {
        JsonLang(nullptr);
    }
    return textJson->value(key, default_value);
}

void JsonLang::update() {
    ;
}
