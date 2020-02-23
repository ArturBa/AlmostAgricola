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
#include <map>
#include <string>

#include "Model.hh"
#include "ViewAbstract.hh"
#include "ViewController.hh"
#include "ActionButton.hh"
#include "Farm.hh"
#include "Upgrade.hh"

/**
 * @class ViewGame
 * @brief Class displaying main game view
 */
class ViewGame : public ViewAbstract {
private:
    void displayAction();

    void displayRanking();

    void displayFarm();

    void displayWeek();

    void displayUpgrades();

    void displayWarehouse();

    std::string getTextFromKey(const std::string &key, const std::string &default_value = "null");

    void displayRank();

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


