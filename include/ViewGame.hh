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


enum class GameViewEnum {
    actions,
    week,
    farm,
    ranking
};

class ViewGame {
private:
    sf::RenderWindow *window;
    Model *model;
    GameViewEnum gameView;

    void displayMenuBar();

    void displayWarehouse();

    void displayActions();

public:
    void display();

    explicit ViewGame(Model *_model, sf::RenderWindow *_window);

};


