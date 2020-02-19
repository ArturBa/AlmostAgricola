//
// Created by artur on 19/02/2020.
//

#include "Window.hh"

Window::Window(Settings *_settings) : shared(&window, &viewController, _settings), viewController(&shared),
                                      settings(_settings), Observer(_settings),
                                      window(sf::RenderWindow(sf::VideoMode(800, 600),
                                                              "Almost Agricola", sf::Style::Close)) {
    window.setVerticalSyncEnabled(true);
}

void Window::start() {
    ImGui::SFML::Init(*shared.window);
    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(ImColor(109, 116, 116)));
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(ImColor(0, 0, 0)));
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(ImColor(0, 0, 0)));
    ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(ImColor(226, 226, 226)));
    ImGui::PushStyleColor(ImGuiCol_ScrollbarBg, ImVec4(ImColor(109, 116, 116)));
    ImGui::PushStyleColor(ImGuiCol_SliderGrab, ImVec4(ImColor(109, 116, 116)));
    ImGui::PushStyleColor(ImGuiCol_TextSelectedBg, ImVec4(ImColor(109, 116, 116)));

    viewController.getShared()->font.loadFromFile("../res/font/Lato-Black.ttf");
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    io.IniFilename = "../res/cnf/800.ini";
    io.Fonts->AddFontFromFileTTF("../res/font/Lato-Black.ttf", 10.f, nullptr, io.Fonts->GetGlyphRangesDefault());
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

void Window::update() {
    window.setSize(settings->getSize());
    char fileNameBuffer[64];
    sprintf(fileNameBuffer, "../res/cnf/%d.ini", settings->getResHor());
}


