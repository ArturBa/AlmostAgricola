//
// Created by bauer on 2/12/20.
//

#include "ViewGame.hh"

#define DEFAULT_WINDOW_FLAGS (ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBackground)

ViewGame::ViewGame(ViewController *_viewController) :
        ViewAbstract(_viewController) {
}

void ViewGame::display() {
    ImGui::SFML::Update(*viewController->getShared()->window, viewController->getShared()->deltaClock.restart());
    viewController->getShared()->window->clear({206, 186, 162});
    if (!ImGui::Begin("Game", nullptr, DEFAULT_WINDOW_FLAGS)) {
        ImGui::End();
        return;
    }
    if (ImGui::BeginTabBar("##Tabs", ImGuiTabBarFlags_None)) {
        if (ImGui::BeginTabItem("Actions")) {
            displayAction();
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("Farm")) {
            displayFarm();
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("Week")) {
            displayWeek();
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("Upgrades")) {
            displayUpgrades();
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("Ranking")) {
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
    //TODO get this from model
    std::map<std::string, bool> actions = {{"0_1", true}};
    for (const auto &i: actions) {
        if (i.second) {
            if (ImGui::ImageButton(ActionButtonFactory::getActionButton(i.first)->getTexture(),
                                   {BUTTON_WIDTH, BUTTON_HEIGHT})) {

            }
            if (ImGui::IsItemHovered()) {
                ImGui::BeginTooltip();
                ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
                ImGui::TextUnformatted(ActionButtonFactory::getActionButton(i.first)->getText().c_str());
                ImGui::PopTextWrapPos();
                ImGui::EndTooltip();
            }

        }
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
    ImGui::Text("Warehouse");
    ImGui::Separator();
    ImGui::Text("Food");
    ImGui::Text("Wheat");
    ImGui::Text("Vegetable");
    ImGui::Text("Wood");
    ImGui::Text("Stone");
    ImGui::Text("Clay");
    ImGui::Text("Reed");
    ImGui::Text("Family memb.");
    ImGui::End();
}

