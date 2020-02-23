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
#include "PlayerTexture.hh"

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
    sf::Texture texture;
    sf::Sprite bgImage;

    void displayMainMenu();

    void displayNewGame();

    void displayHotSeatConfig();

    void displayLoadGame();

    static int getResFromIndex(int index);

    static std::string getLangFromIndex(int index);

    static int getIndexFromRes(int res);

    static int getIndexFromLang(const std::string &lang);

    void displaySettings();

    void displayCredits();

    void displayBgImage();

    void displayText(const std::string &_text);

    void displayPlayer(char *player_name, int &player_icon, int player_no, int active_players);

public:
    /**
     * @brief Constructor
     * @param _viewController ViewController pointer
     */
    explicit ViewMenu(ViewController *_viewController);

    /**
     * @brief Display GUI for main game menu
     */
    void display() override;

    /**
     * @brief Get json Text value for selected lang
     * @param key key for searching
     * @return text value in selected lang
     */
    std::string getJsonLangValue(const std::string &key);

};


