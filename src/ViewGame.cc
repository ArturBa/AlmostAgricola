//
// Created by bauer on 2/12/20.
//

#include "ViewGame.hh"

ViewGame::ViewGame(ViewController *_viewController) :
        ViewAbstract(_viewController),
        viewGame(ViewGameEnum::action) {
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    io.IniFilename = "../res/cnf/800_600_game.ini";
}

void ViewGame::display() {
    ImGui::SFML::Update(*viewController->getShared()->window, viewController->getShared()->deltaClock.restart());
    viewController->getShared()->window->clear({206, 186, 162});
    switch (viewGame) {
        case ViewGameEnum::action:
            displayAction();
            break;
        case ViewGameEnum::ranging:
            break;
        case ViewGameEnum::farm:
            break;
    }
    ImGui::SFML::Render(*viewController->getShared()->window);
    viewController->getShared()->window->display();

}

void ViewGame::displayAction() {
    if (!ImGui::Begin("Action", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoDecoration)) {
        ImGui::End();
        return;
    }
    if (ImGui::Button("some button seat", {235, 30})) {
    }
    ImGui::End();
}
