//
// Created by artur on 30/01/2020.
//

#include "ViewGame.hh"

ViewGame::ViewGame(Model *m, sf::RenderWindow *w) :
        gameView(GameViewEnum::actions) {
    model = m;
    window = w;
}

void ViewGame::display() {
    displayMenuBar();
    if (gameView != GameViewEnum::ranking) {
        displayWarehouse();
    }
    switch (gameView) {
        case GameViewEnum::actions:
            displayActions();
            break;
        case GameViewEnum::week:
            break;
        case GameViewEnum::farm:
            break;
        case GameViewEnum::ranking:
            break;
    }
}

void ViewGame::displayActions() {

}

void ViewGame::displayWarehouse() {
    if (!ImGui::Begin("Warehouse", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove)) {
        ImGui::End();
        return;
    }
    model->getWarehouse();
    //TODO get real model data
    int data[8] = {1, 2, 3, 3, 5, 6, 2, 4};
    ImGui::Text("Food:\t%d", data[0]);
    ImGui::Text("Wheal:\t%d", data[1]);
    ImGui::Text("Vegetable:\t%d", data[2]);
    ImGui::Text("Stone:\t%d", data[3]);
    ImGui::Text("Wood:\t%d", data[4]);
    ImGui::Text("Clay:\t%d", data[5]);
    ImGui::Text("Reed:\t%d", data[6]);
    ImGui::Text("Family members:\t%d", data[7]);

    ImGui::End();
}

void ViewGame::displayMenuBar() {
    if (ImGui::BeginMainMenuBar()) {
        if (ImGui::BeginMenu("Game")) {
            if (ImGui::MenuItem("Load", "Ctrl+O")) { ; }
            if (ImGui::MenuItem("Save", "Ctrl+S")) { ; }
            if (ImGui::MenuItem("Close", "Ctrl+W")) { window->close(); }
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }
}

