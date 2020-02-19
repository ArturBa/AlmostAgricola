//
// Created by bauer on 2/12/20.
//

#include "ViewGame.hh"

#define DEFAULT_WINDOW_FLAGS (ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBackground)

ViewGame::ViewGame(ViewController *_viewController) :
        ViewAbstract(_viewController) {
}

std::string ViewGame::getTextFromKey(const std::string &key, const std::string &default_value) {
    return viewController->getShared()->lang.getText(key, default_value);
}

void ViewGame::display() {
    ImGui::SFML::Update(*viewController->getShared()->window, viewController->getShared()->deltaClock.restart());
    viewController->getShared()->window->clear({206, 186, 162});
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
    for (const auto &i: *actions) {
        if (line % 6) {
            ImGui::SameLine();
        }
        line++;
        ImGui::PushItemFlag(ImGuiItemFlags_Disabled, !i.second);
        if (ImGui::ImageButton(ActionButtonFactory::getActionButton(i.first, viewController->getShared()->lang)->getTexture(),
                               {BUTTON_WIDTH, BUTTON_HEIGHT})) {
            viewController->getShared()->model.selectAction(i.first);
        }
        if (ImGui::IsItemHovered()) {
            ImGui::BeginTooltip();
            ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
            ImGui::TextUnformatted(ActionButtonFactory::getActionButton(i.first, viewController->getShared()->lang)->getText().c_str());
            ImGui::PopTextWrapPos();
            ImGui::EndTooltip();
        }
        ImGui::PushItemFlag(ImGuiItemFlags_Disabled, false);
    }
    ImGui::EndChild();
}

void ViewGame::displayRanking() {

}

void ViewGame::displayFarm() {

}

void ViewGame::displayWeek() {

}

void ViewGame::displayUpgrades() {

}

void ViewGame::displayWarehouse() {
    if (!ImGui::Begin("Warehouse", nullptr, DEFAULT_WINDOW_FLAGS)) {
        ImGui::End();
        return;
    }
    auto player = viewController->getShared()->model.getCurrentPlayer();
    ImGui::Text("%s", getTextFromKey("warehouse").c_str());
    ImGui::Separator();
    ImGui::Text("%s: ", getTextFromKey("player").c_str());
    ImGui::Text("Kris");
    ImGui::Separator();
    ImGui::Text("%s", getTextFromKey("food").c_str());
    ImGui::Text("%s", getTextFromKey("wheat").c_str());
    ImGui::Text("%s", getTextFromKey("vegetable").c_str());
    ImGui::Text("%s", getTextFromKey("wood").c_str());
    ImGui::Text("%s", getTextFromKey("stone").c_str());
    ImGui::Text("%s", getTextFromKey("clay").c_str());
    ImGui::Text("%s", getTextFromKey("reed").c_str());
    ImGui::Text("%s", getTextFromKey("family_memb").c_str());
    ImGui::End();
}

