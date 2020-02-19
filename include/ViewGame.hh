//
// Created by bauer on 2/12/20.
//

#pragma once

#include <SFML/Graphics.hpp>
#include "imgui-SFML.h"
#include "imgui.h"
#include <imgui_internal.h>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>

#include "Model.hh"
#include "ViewAbstract.hh"
#include "ViewController.hh"
#include "ActionButton.hh"
#include <map>
#include <string>

class ViewGame : public ViewAbstract {
private:
    void displayAction();

    void displayRanking();

    void displayFarm();

    void displayWeek();

    void displayUpgrades();

    void displayWarehouse();

    std::string getTextFromKey(const std::string &key, const std::string &default_value = "null");

public:
    /**
     * @brief Constructor
     * @param _viewController ViewController pointer
     */
    explicit ViewGame(ViewController *_viewController);

    /**
     * @brief Display GUI for main game menu
     */
    void display() override;
};


