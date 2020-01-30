//
// Created by artur on 30/01/2020.
//

#include "Application.hh"

Application::Application()
        : shared(&window, &viewController), viewController(&shared),
          window(sf::RenderWindow(sf::VideoMode(800, 600),
                                  "Almost Agricola", sf::Style::Close)) {

}

void Application::start() {
    ImGui::SFML::Init(*shared.window);
    sf::Event event{};
    while (shared.window->isOpen()) {
        while (shared.window->pollEvent(event)) {
            ImGui::SFML::ProcessEvent(event);

            if (event.type == sf::Event::Closed)
                shared.window->close();
        }
        viewController.display();
    }
    ImGui::SFML::Shutdown();
}
