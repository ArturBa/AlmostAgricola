//
// Created by artur on 30/01/2020.
//

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <nlohmann/json.hpp>
#include "ViewController.hh"
#include "Json.hh"

/**
 * @struct Shared
 * @brief Contain all shared data between different controllers
 */
typedef struct Shared {
    Shared(sf::RenderWindow *_w, ViewController *_vc) : window(_w), viewController(_vc) {
        texturePlayers.loadFromFile("../res/img/players_icon.png");
        lang = LoadJsonFromFile("../res/lang/eng.json");
    }

    sf::RenderWindow *window;           /**< Main window data*/
    ViewController *viewController;     /**< ViewController data*/
    sf::Clock deltaClock;               /**< Clock data*/
    sf::Font font;
    sf::Sprite sprite;
    sf::Image image;
    sf::Texture texturePlayers;
    nlohmann::json *lang;
} Shared;
