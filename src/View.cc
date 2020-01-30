//
// Created by artur on 29/01/2020.
//

#include "View.hh"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

View::View(Model *m) :
        actualView(ViewEnum::menu),
        bgColor({206, 186, 162}) {
    model = m;

    window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Almost Agricola", sf::Style::Close);
    viewGame = new ViewGame(model, window);
    viewMenu = new ViewMenu(model, window);
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
    window->clear(bgColor);

    switch (actualView) {
        case ViewEnum::menu:
            viewMenu->display();
            break;
        case ViewEnum::game:
            viewGame->display();
            break;
    }
    ImGui::SFML::Render(*window);
    window->display();
}
