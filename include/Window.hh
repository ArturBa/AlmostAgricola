//
// Created by artur on 19/02/2020.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "imgui-SFML.h"
#include "imgui.h"
#include <imgui_internal.h>

#include "ViewController.hh"
#include "Observer.hh"
#include "Settings.hh"
#include "Shared.hh"


class Window : public Observer {
private:
    Shared shared;
    ViewController viewController;
    sf::RenderWindow window;
    Settings *settings;

public:
    /**
     * @brief Default window constructor
     */
    explicit Window(Settings *_settings);

    /**
     * @brief update window size
     */
    void update() override;

    /**
     * @brief Window displaying start
     */
    void start();
};
