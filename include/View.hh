//
// Created by artur on 29/01/2020.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "Model.hh"
#include "imgui-SFML.h"
#include "imgui.h"
#include <imgui_internal.h>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>

#include "ViewGame.hh"

enum class ViewEnum {
    mainMenu,
    newGame,
    loadGame,
    settings,
    credits,
    game
};

class View {
private:
    sf::RenderWindow *window;
    sf::Clock deltaClock;
    sf::Sprite sprite;
    sf::Image image;
    sf::Texture texture;
    sf::Color bgColor;
    sf::Font font;
    ViewEnum actualView;
    ViewGame *viewGame;

    Model *model;

    void display();

    void displayMenuPhoto();

    void displayMenuLogo();

    void displayMainMenu();

    void displayCredits();

    void displayNewGame();

    void displayLoadGame();

    void displaySettings();

    void displayGame();

    void displayGameWarehouse();

    void displayGameMenuBar();

    void displayGameActions();

    void setSprite(unsigned int width, unsigned int height, unsigned char *pixelArray);

    float calculateScale(unsigned int width, unsigned int height);

public:
    /**
     * View constructor
     * @param m [Model]
     */
    explicit View(Model *m);

    /**
     * Method for processing events in the game
     */
    void processEvents();
};


