//
// Created by artur on 30/01/2020.
//

#include "Application.hh"

Application::Application()
        : shared(&window, &viewController), viewController(&shared),
          window(sf::RenderWindow(sf::VideoMode(800, 600),
                                  "Almost Agricola", sf::Style::Close)) {
    window.setVerticalSyncEnabled(true);
}

void Application::start() {
    ImGui::SFML::Init(*shared.window);
    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(ImColor(109, 116, 116)));
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(ImColor(0, 0, 0)));
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(ImColor(0, 0, 0)));
    ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(ImColor(226, 226, 226)));
    ImGui::PushStyleColor(ImGuiCol_ScrollbarBg, ImVec4(ImColor(109, 116, 116)));
    ImGui::PushStyleColor(ImGuiCol_SliderGrab, ImVec4(ImColor(109, 116, 116)));
    ImGui::PushStyleColor(ImGuiCol_TextSelectedBg, ImVec4(ImColor(109, 116, 116)));
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
