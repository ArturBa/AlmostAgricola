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

/**
 * @enum Game display mode
 */
enum class ViewGameEnum {
    action,         /**< Display action menu*/
    ranging,        /**< Display ranking menu*/
    farm,           /**< Display farm menu*/
};

class ViewGame : public ViewAbstract {
private:
    ViewGameEnum viewGame;

    void displayAction();

    void displayRanking();

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


