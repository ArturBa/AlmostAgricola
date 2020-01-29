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

enum class ViewEnum {
    mainMenu,
    newGame,
    loadGame,
    settings,
    credits,
    game
};

enum class GameViewEnum {
    actions,
    week,
    farm,
    ranking
};

class View {
private:
    sf::RenderWindow *window;
    sf::Clock deltaClock;
    sf::Sprite sprite;
    sf::Image image;
    sf::Texture texture;
    float color[3] = {0};
    ViewEnum actualView;
    GameViewEnum gameView;

    Model *model;

    void display();

    void displayMenuPhoto();

    void displayMenu();

    void displayCredits();

    void displayNewGame();

    void displayLoadGame();

    void displaySettings();

    void displayGame();

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


