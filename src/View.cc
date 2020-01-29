//
// Created by artur on 29/01/2020.
//

#include "View.hh"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

View::View(Model *m) {
    model = m;

    window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Almost Agricola", sf::Style::Close);
    window->setVerticalSyncEnabled(true);
    ImGui::SFML::Init(*window);
}

void View::processEvents() {
    sf::Event event{};
    while (window->isOpen()) {
        while (window->pollEvent(event)) {
            ImGui::SFML::ProcessEvent(event);

            if (event.type == sf::Event::Closed)
                window->close();
        }
        display();
    }

    ImGui::SFML::Shutdown();

}

void View::display() {
    ImGui::SFML::Update(*window, deltaClock.restart());

    if (!ImGui::Begin("Some window")) {
        ImGui::End();
        return;
    }

    // Background color edit
    if (ImGui::ColorEdit3("Background color", color)) {
        // this code gets called if color value changes, so
        // the background color is upgraded automatically!
        model->setBgColor(color);
    }

    // Window title text edit
    ImGui::InputText("Window title", windowTitle, 255);

    if (ImGui::Button("Update window title")) {
        window->setTitle(windowTitle);
    }
    window->clear(model->getBgColor());
    ImGui::End();

    ImGui::SFML::Render(*window);
    window->display();
}
