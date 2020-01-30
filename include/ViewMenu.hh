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
#include "ViewAbstract.hh"
#include "ViewController.hh"

/**
 * @enum Menu display mode
 */
enum class ViewMenuEnum {
    mainMenu,          /**< Display main menu*/
    newGame,           /**< Display new game menu*/
    loadGame,          /**< Display load game menu*/
    settings,          /**< Display settings menu*/
    credits,           /**< Display credits*/
    hotSeatConfig      /**< Display new game hot seat config menu*/
};

/**
 * @class ViewMenu
 * @brief Class containing main menu views
 */
class ViewMenu : public ViewAbstract {
    ViewMenuEnum viewMenu;

    void displayMainMenu();

    void displayNewGame();

    void displayHotSeatConfig();

    void displayLoadGame();

    void displaySettings();

    void displayCredits();

public:
    /**
     * @brief Constructor
     * @param _viewController ViewController pointer
     */
    explicit ViewMenu(ViewController *_viewController);

    void display() override;
};


