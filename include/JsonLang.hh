//
// Created by artur on 19/02/2020.
//

#pragma once

#include "Json.hh"
#include "Observer.hh"
#include "Settings.hh"


/**
 * @class JsonLang
 * @brief Class containing all text for game
 * @interface Observer
 */
class JsonLang : public Observer {
private:
    nlohmann::json *textJson;
    Settings *settings;

public:
    /**
     * @brief default constructor
     * @param _settings settings pointer (observer)
     */
    explicit JsonLang(Settings *_settings);

    /**
     * @brief Get Text from JsonLang
     * @param key key to find a text value in json file
     * @param default_value value if not found key
     * @return text
     */
    std::string getText(const std::string &key, const std::string &default_value = "null");

    /**
     * @brief Update if changed language version
     */
    void update() override;

};


