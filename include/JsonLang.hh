//
// Created by artur on 19/02/2020.
//

#pragma once

#include "Json.hh"
#include "Observer.hh"
#include "Settings.hh"


class JsonLang : public Observer {
private:
    nlohmann::json *textJson;
    Settings *settings;

public:
    explicit JsonLang(Settings *_settings);

    std::string getText(const std::string &key, const std::string &default_value = "null");

    void update() override;

};


