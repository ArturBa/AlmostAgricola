//
// Created by artur on 19/02/2020.
//

#pragma once

#include <SFML/Graphics.hpp>
#include <algorithm>
#include <map>

#include "Sender.hh"
#include "Json.hh"

class Settings : public Sender {
private:
    std::string lang;
    int resHor;
    nlohmann::json *settingsJson;
    std::map<int, sf::Vector2u> mapOfResolutions = {
            {800,  {800,  600}},
            {1280, {1280, 720}},
            {1920, {1920, 1080}}
    };
public:
    void updateSettings();

    [[nodiscard]] const std::string &getLang() const;

    [[nodiscard]] int getResHor() const;

    void setLang(const std::string &_lang);

    void setResHor(int _resHor);

    sf::Vector2u getSize();

    Settings();
};


