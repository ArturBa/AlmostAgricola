//
// Created by artur on 29/01/2020.
//

#include "View.hh"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

View::View(Model *m) :
        actualView(ViewEnum::main_menu) {
    model = m;

    window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Almost Agricola", sf::Style::Close);
    window->setVerticalSyncEnabled(true);
    ImGui::SFML::Init(*window);
    model->loadImage("../res/img/menu_sheep.jpg");
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

    window->clear(model->getBgColor());
    switch (actualView) {
        case ViewEnum::main_menu:
            displayMenu();
            break;
        case ViewEnum::credits:
            displayCredits();
            break;
    }
    ImGui::SFML::Render(*window);
    window->display();
}


void View::displayMenu() {
    displayMenuPhoto();
    ImVec2 buttonSpace(0, 25.f);
    ImVec2 buttonSize(235, 30);
    if (!ImGui::Begin("Main Menu", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove)) {
        ImGui::End();
        return;
    }
    ImGui::PushItemWidth(235);
    if (ImGui::Button("New Game", buttonSize)) {
        color[0] = 1, color[1] = 0, color[2] = 0;
        model->setBgColor(color);
    }
    ImGui::Dummy(buttonSpace);
    if (ImGui::Button("Load Game", buttonSize)) {
        color[0] = 0, color[1] = 1, color[2] = 0;
        model->setBgColor(color);
    }
    ImGui::Dummy(buttonSpace);
    if (ImGui::Button("Settings", buttonSize)) {
        color[0] = 0, color[1] = 0, color[2] = 1;
        model->setBgColor(color);
    }
    ImGui::Dummy(buttonSpace);
    if (ImGui::Button("Credits", buttonSize)) {
        actualView = ViewEnum::credits;
    }

    ImGui::End();
}


void View::displayGame() {

}


void View::displayGameActions() {

}


void View::displayCredits() {
    if (!ImGui::Begin("Main Menu", nullptr,
                      ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse |
                      ImGuiWindowFlags_NoMove)) {
        ImGui::End();
        return;
    }
    displayMenuPhoto();
    ImGui::PushItemWidth(235);
    ImGui::TextWrapped("All credits go here. Lorem ipsum. What if there is even more text?");
    ImGui::TextWrapped(
            "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur sapien sem, sagittis non dapibus id, tincidunt lacinia nulla. Morbi lobortis rhoncus dui, sit amet fringilla sapien pulvinar sit amet. Nullam neque eros, egestas quis pulvinar nec, vulputate non tellus. Praesent et elit ipsum. Aenean venenatis rhoncus quam sed iaculis. Cras pellentesque tristique nibh in hendrerit. Nullam ut efficitur diam. Donec imperdiet sapien id condimentum gravida. Praesent hendrerit pretium ipsum nec interdum. Sed tempus justo quam, vel blandit dolor porttitor non. Morbi rutrum, arcu in semper ullamcorper, diam urna feugiat turpis, vestibulum pharetra augue felis et mauris. ");
    ImGui::TextWrapped(
            "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur sapien sem, sagittis non dapibus id, tincidunt lacinia nulla. Morbi lobortis rhoncus dui, sit amet fringilla sapien pulvinar sit amet. Nullam neque eros, egestas quis pulvinar nec, vulputate non tellus. Praesent et elit ipsum. Aenean venenatis rhoncus quam sed iaculis. Cras pellentesque tristique nibh in hendrerit. Nullam ut efficitur diam. Donec imperdiet sapien id condimentum gravida. Praesent hendrerit pretium ipsum nec interdum. Sed tempus justo quam, vel blandit dolor porttitor non. Morbi rutrum, arcu in semper ullamcorper, diam urna feugiat turpis, vestibulum pharetra augue felis et mauris. ");

    ImGui::Dummy(ImVec2(0.0f, 20.0f));

    if (ImGui::Button("Back", {235, 20})) {
        actualView = ViewEnum::main_menu;
    }

    ImGui::End();
}


void View::displayMenuPhoto() {
    setSprite(model->getWidth(), model->getHeight(), model->getImage());
    window->draw(sprite);
}


void View::setSprite(unsigned int width, unsigned int height, unsigned char *pixelArray) {
    image.create(width, height, pixelArray);
    texture.loadFromImage(image);

    float scale = calculateScale(width, height);
    sprite.setTexture(texture);
    sprite.setScale({scale, scale});

    sprite.setPosition({((float) window->getSize().x - ((float) width * scale) - 250) / 2,
                        ((float) window->getSize().y - ((float) height * scale)) / 2});
}


float View::calculateScale(unsigned int width, unsigned int height) {
    if ((window->getSize().x - 250) / width > (window->getSize().y) / height) {
        return (float) window->getSize().y / (float) height;
    } else {
        return (float) (window->getSize().x - 250) / (float) width;
    }
}