//
// Created by artur on 30/01/2020.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "imgui-SFML.h"
#include "imgui.h"
#include <imgui_internal.h>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include "Model.hh"

enum class ViewMenuEnum {
    mainMenu,
    newGame,
    loadGame,
    settings,
    credits,
    hotSeatConfig
};

class ViewMenu {
    sf::RenderWindow *window;
    sf::Font font;
    sf::Sprite sprite;
    sf::Image image;
    sf::Texture texture;
    Model *model;
    ViewMenuEnum viewMenu;


public:
    void display();

    ViewMenu(Model *_model, sf::RenderWindow *_window);

    void displayMainMenu();

    void displayNewGame();

    void displayHotSeatConfig();

    void displayLoadGame();

    void displaySettings();

    void displayCredits();

    void displayText(std::string _text);

    void displayMenuPhoto();

    void setSprite(unsigned int width, unsigned int height, unsigned char *pixelArray);

    float calculateScale(unsigned int width, unsigned int height);
};


