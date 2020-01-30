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
#include "ViewMenu.hh"

enum class ViewEnum {
    menu,
    game
};

class View {
private:
    sf::RenderWindow *window;
    sf::Clock deltaClock;
    sf::Color bgColor;
    ViewEnum actualView;
    ViewGame *viewGame;
    ViewMenu *viewMenu;
    Model *model;

    void display();
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


