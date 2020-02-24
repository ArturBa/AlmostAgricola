//
// Created by artur on 30/01/2020.
//

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include "ViewController.hh"
#include "Settings.hh"
#include "JsonLang.hh"
#include "Model.hh"

/**
 * @struct Shared
 * @brief Contain all shared data between different controllers
 */
typedef struct Shared {
    Shared(sf::RenderWindow *_w, ViewController *_vc, Settings *_st) : window(_w), viewController(_vc), settings(_st),
                                                                       lang(_st) {
    }

    sf::RenderWindow *window;           /**< Main window data*/
    ViewController *viewController;     /**< ViewController data*/
    sf::Clock deltaClock;               /**< Clock data*/
    sf::Font font;                      /**< Font data*/
    Settings *settings;                 /**< Settings sender pointer*/
    JsonLang lang;                      /**< JsonLang observer*/
    Model model;                        /**< Model data*/
} Shared;
