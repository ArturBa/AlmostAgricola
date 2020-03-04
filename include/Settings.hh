//
// Created by artur on 19/02/2020.
//

#pragma once

#include <SFML/Graphics.hpp>
#include <algorithm>
#include <map>

#include "Sender.hh"
#include "Json.hh"

/**
 * @class Settings
 * @brief Class containing all main settings
 * @interface Sender
 */
class Settings : public Sender {
private:
    std::string lang;
    unsigned int resHor;
    nlohmann::json *settingsJson;
    std::map<int, sf::Vector2u> mapOfResolutions = {
            {800,  {800,  600}},
            {1280, {1280, 720}},
            {1920, {1920, 1080}}
    };

    void updateSettings();

public:
    /**
     * @brief Get set lang
     * @return lang
     */
    [[nodiscard]] const std::string &getLang() const;

    /**
     * @brief Get Horizontal Resolution
     * @return Horizontal resolution
     */
    [[nodiscard]] int getResHor() const;

    /**
     * @brief Set lang
     * @param _lang lang to set
     */
    void setLang(const std::string &_lang);

    /**
     * @brief Set Horizontal resolution
     * @param _resHor horizontal resolution
     */
    void setResHor(unsigned int _resHor);

    /**
     * @brief Get 2d size based on horizontal resolution
     * @return Vector of window size
     */
    sf::Vector2u getSize();

    /**
     * @brief Default constructor
     */
    Settings();
};


class SettingsException : public std::exception {
	virtual const char* what() const throw() {
		return "My exception happened";
	}
};
