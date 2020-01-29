//
// Created by artur on 29/01/2020.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "Model.hh"
#include "imgui-SFML.h"
#include "imgui.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>

class View {
private:
    sf::RenderWindow *window;
    sf::Clock deltaClock;
    sf::Color bgColor;
    char windowTitle[255] = {0};
    float color[3] = {0};

    Model *model;

    void display();

public:
    explicit View(Model *m);

    void processEvents();

};


