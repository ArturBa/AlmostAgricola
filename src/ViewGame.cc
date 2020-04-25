//
// Created by bauer on 2/12/20.
//

#include <Points.hh>
#include <iostream>
#include "ViewGame.hh"

#define DEFAULT_WINDOW_FLAGS (ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBackground)
#define BG_COLOR {0x2f, 0x30, 0x32}

ViewGame::ViewGame(ViewController *_viewController) :
        ViewAbstract(_viewController) {
}

std::string ViewGame::getTextFromKey(const std::string &key, const std::string &default_value) {
    return viewController->getShared()->lang.getText(key, default_value);
}

void ViewGame::display() {
    ImGui::SFML::Update(*viewController->getShared()->window, viewController->getShared()->deltaClock.restart());
    viewController->getShared()->window->clear(BG_COLOR);
    if (!ImGui::Begin("Game", nullptr, DEFAULT_WINDOW_FLAGS)) {
        ImGui::End();
        return;
    }
    if (ImGui::BeginTabBar("##Tabs", ImGuiTabBarFlags_None)) {
        if (ImGui::BeginTabItem(getTextFromKey("actions").c_str())) {
            displayAction();
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem(getTextFromKey("farm").c_str())) {
            displayFarm();
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem(getTextFromKey("week").c_str())) {
            displayWeek();
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem(getTextFromKey("upgrades").c_str())) {
            displayUpgrades();
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem(getTextFromKey("ranking").c_str())) {
            displayRanking();
            ImGui::EndTabItem();
        }
        ImGui::EndTabBar();
    }
    ImGui::End();
    displayWarehouse();
    ImGui::SFML::Render(*viewController->getShared()->window);
    viewController->getShared()->window->display();

}

void ViewGame::displayAction() {
    ImGui::BeginChild("##Actions", {650, 550});
    auto actions = viewController->getShared()->model.getMapOfActions();
    int line = 0;
    for (const auto &i: actions) {
        if (line % 6) {
            ImGui::SameLine();
        }
        line++;
        ImGui::PushItemFlag(ImGuiItemFlags_Disabled, !i.second.first);
        if (ImGui::ImageButton(
                ActionButtonFactory::getActionButton(i.first, viewController->getShared()->lang)->getTexture(),
                {ACTION_BUTTON_WIDTH, ACTION_BUTTON_HEIGHT})) {
            try {
                viewController->getShared()->model.selectAction(i.first);
            } catch (GameException &gameException) {
                viewController->switchTo(ViewEnum::results);
            }
        }
        if (ImGui::IsItemHovered()) {
            ImGui::BeginTooltip();
            ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
            ImGui::TextUnformatted(ActionButtonFactory::getActionButton(i.first,
                                                                        viewController->getShared()->lang)->getText().c_str());
            ImGui::PopTextWrapPos();
            ImGui::EndTooltip();
        }
        ImGui::PushItemFlag(ImGuiItemFlags_Disabled, false);
    }
    ImGui::EndChild();
}

void ViewGame::displayRank() {
    auto players = *viewController->getShared()->model.getPlayers();
    ImGui::BeginChild("Plot");
    ImGui::Dummy({10, 0});
    ImGui::SameLine(300.f);
    ImGui::Text("Sheep");
    ImGui::DrawLine({140, 0}, {140, (float) players.size() * 20 + 5}, sf::Color::Black, 2.0f);
    ImGui::DrawLine({140, (float) players.size() * 20 + 5}, {540, (float) players.size() * 20 + 5},
                    sf::Color::Black, 2.0f);
    for (auto player: players) {
        ImGui::TextColored(player->getPlayerTexture()->getColor(), "%s", player->getName().c_str());
        Points point(player);
        ImGui::DrawRectFilled({240, -14, static_cast<float>(100 * point.getSheep()), 16},
                              player->getPlayerTexture()->getColor());
    }
    ImGui::Dummy({0, 20.f});
    ImGui::Dummy({0, 10.f});
    ImGui::SameLine(234.f);
    ImGui::Text("0");
    ImGui::Dummy({0, 30.f});
    ImGui::EndChild();
}

void ViewGame::displayRanking() {
    displayRank();
    displayRank();
}

void ViewGame::displayFarm() {
    auto farm = viewController->getShared()->model.getCurrentPlayer()->getFarm();
    for (const auto &y: farm) {
        for (const auto &x: y) {
            ImGui::Image(FarmFactory::getFarm(x)->getTexture(), {80, 80});
            ImGui::SameLine();
        }
        ImGui::NewLine();
    }
}

void ViewGame::displayWeek() {
    for (auto action = Actions::WEEK_1_0; action <= Actions::Last; ++action) {
        ImGui::Image(ActionButtonFactory::getActionButton(action, viewController->getShared()->lang)->getTexture());
    }
}

void ViewGame::displayUpgrades() {
    for(auto upgrade : UpgradeEnum()){
        if (ImGui::ImageButton(
                UpgradeFactory::getUpgrade(upgrade, viewController->getShared()->lang)->getTexture(),
                {ACTION_BUTTON_WIDTH, ACTION_BUTTON_HEIGHT})) {
            ;
        }
        if (ImGui::IsItemHovered()) {
            ImGui::BeginTooltip();
            ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
            ImGui::TextUnformatted(UpgradeFactory::getUpgrade(upgrade, viewController->getShared()->lang)->getText().c_str());
            ImGui::PopTextWrapPos();
            ImGui::EndTooltip();
        }
    }
}

void ViewGame::displayWarehouse() {
    if (!ImGui::Begin("Warehouse", nullptr, DEFAULT_WINDOW_FLAGS)) {
        ImGui::End();
        return;
    }
    auto player = viewController->getShared()->model.getCurrentPlayer();
    ImGui::Text("%s: ", getTextFromKey("player").c_str());
    ImGui::Text("%s", player->getName().c_str());
    ImGui::Separator();
    ImGui::Text("%s: %d", getTextFromKey("food_required").c_str(), player->getFoodRequired());
    ImGui::Separator();
    ImGui::Text("%s: %d", getTextFromKey("till_harvest").c_str(), viewController->getShared()->model.weeksToHarvest());
    ImGui::Separator();
    ImGui::Text("%s", getTextFromKey("warehouse").c_str());
    ImGui::Separator();
    ImGui::Text("%s: %d", getTextFromKey("food").c_str(), player->warehouse->food.getResource());
    ImGui::Text("%s: %d", getTextFromKey("wheat").c_str(), player->warehouse->wheat.getResource());
    ImGui::Text("%s: %d", getTextFromKey("vegetable").c_str(), player->warehouse->vegetable.getResource());
    ImGui::Text("%s: %d", getTextFromKey("wood").c_str(), player->warehouse->wood.getResource());
    ImGui::Text("%s: %d", getTextFromKey("stone").c_str(), player->warehouse->stone.getResource());
    ImGui::Text("%s: %d", getTextFromKey("clay").c_str(), player->warehouse->clay.getResource());
    ImGui::Text("%s: %d", getTextFromKey("reed").c_str(), player->warehouse->reed.getResource());
    ImGui::Separator();
    ImGui::Text("%s: %d", getTextFromKey("sheep").c_str(), player->warehouse->sheep.getResource());
    ImGui::Text("%s: %d", getTextFromKey("swine").c_str(), player->warehouse->swine.getResource());
    ImGui::Text("%s: %d", getTextFromKey("cow").c_str(), player->warehouse->cow.getResource());
    ImGui::Separator();
    ImGui::Text("%s: %d", getTextFromKey("beg_card").c_str(), player->warehouse->begCards.getResource());
    ImGui::Text("%s: %d", getTextFromKey("family_memb").c_str(), player->getFamilyMembers());
    ImGui::End();
}

