//
// Created by artur on 29/01/2020.
//

#include "View.hh"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

View::View(Model *m) :
        actualView(ViewEnum::mainMenu),
        bgColor({206, 186, 162}) {
    model = m;

    window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Almost Agricola", sf::Style::Close);
    viewGame = new ViewGame(model, window);
    window->setVerticalSyncEnabled(true);
    ImGui::SFML::Init(*window);
    ImGui::PushStyleColor(ImGuiCol_Button, {103, 103, 103, 0});
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, {0, 0, 0, 255});
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, {0, 0, 0, 255});
    font.loadFromFile("../res/font/Lato-Black.ttf");
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

    window->clear(bgColor);
    if (actualView != ViewEnum::game) {
        displayMenuPhoto();
        displayMenuLogo();
    }

    switch (actualView) {
        case ViewEnum::mainMenu:
            displayMainMenu();
            break;
        case ViewEnum::credits:
            displayCredits();
            break;
        case ViewEnum::newGame:
            displayNewGame();
            break;
        case ViewEnum::loadGame:
            displayLoadGame();
            break;
        case ViewEnum::settings:
            displaySettings();
            break;
        case ViewEnum::game:
            viewGame->display();
            break;
    }
    ImGui::SFML::Render(*window);
    window->display();
}


void View::displayMainMenu() {
    ImVec2 buttonSpace(0, 25.f);
    ImVec2 buttonSize(235, 30);
    if (!ImGui::Begin("Main Menu", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove)) {
        ImGui::End();
        return;
    }
    ImGui::PushItemWidth(235);
    if (ImGui::Button("New Game", buttonSize)) {
        actualView = ViewEnum::newGame;
    }
    ImGui::Dummy(buttonSpace);
    if (ImGui::Button("Load Game", buttonSize)) {
        actualView = ViewEnum::loadGame;
    }
    ImGui::Dummy(buttonSpace);
    if (ImGui::Button("Settings", buttonSize)) {
        actualView = ViewEnum::settings;
    }
    ImGui::Dummy(buttonSpace);
    if (ImGui::Button("Credits", buttonSize)) {
        actualView = ViewEnum::credits;
    }
    ImGui::Dummy(buttonSpace);
    if (ImGui::Button("Exit", buttonSize)) {
        window->close();
    }

    ImGui::End();
}

void View::displayCredits() {
    if (!ImGui::Begin("Main Menu", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove)) {
        ImGui::End();
        return;
    }
    ImGui::PushItemWidth(235);

    ImGui::BeginChild("Credits##scroll", {235, 300});
    ImGui::TextWrapped("All credits go here. Lorem ipsum. What if there is even more text?");
    ImGui::TextWrapped(
            "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur sapien sem, sagittis non dapibus id, tincidunt lacinia nulla. Morbi lobortis rhoncus dui, sit amet fringilla sapien pulvinar sit amet. Nullam neque eros, egestas quis pulvinar nec, vulputate non tellus. Praesent et elit ipsum. Aenean venenatis rhoncus quam sed iaculis. Cras pellentesque tristique nibh in hendrerit. Nullam ut efficitur diam. Donec imperdiet sapien id condimentum gravida. Praesent hendrerit pretium ipsum nec interdum. Sed tempus justo quam, vel blandit dolor porttitor non. Morbi rutrum, arcu in semper ullamcorper, diam urna feugiat turpis, vestibulum pharetra augue felis et mauris. ");
    ImGui::TextWrapped(
            "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur sapien sem, sagittis non dapibus id, tincidunt lacinia nulla. Morbi lobortis rhoncus dui, sit amet fringilla sapien pulvinar sit amet. Nullam neque eros, egestas quis pulvinar nec, vulputate non tellus. Praesent et elit ipsum. Aenean venenatis rhoncus quam sed iaculis. Cras pellentesque tristique nibh in hendrerit. Nullam ut efficitur diam. Donec imperdiet sapien id condimentum gravida. Praesent hendrerit pretium ipsum nec interdum. Sed tempus justo quam, vel blandit dolor porttitor non. Morbi rutrum, arcu in semper ullamcorper, diam urna feugiat turpis, vestibulum pharetra augue felis et mauris. ");

    ImGui::EndChild();
    ImGui::Dummy(ImVec2(0.0f, 20.0f));


    if (ImGui::Button("Back###credits", {235, 30})) {
        actualView = ViewEnum::mainMenu;
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

void View::displaySettings() {
    if (!ImGui::Begin("Settings", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove)) {
        ImGui::End();
        return;
    }
    ImGui::PushItemWidth(235);
    ImGui::Text("Resolution");
    const char *res[] = {"800x600", "1366x766", "1920x1080"};
    static int selRes = 0;
    ImGui::Combo("Resolution", &selRes, res, IM_ARRAYSIZE(res));

    ImGui::Dummy({0, 20});
    if (ImGui::Button("Apply", {235, 30})) {
        model->setSettings();
    }
    ImGui::Dummy({0, 20});
    if (ImGui::Button("Back###settings", {235, 30})) {
        actualView = ViewEnum::mainMenu;
    }

    ImGui::End();
}

void View::displayLoadGame() {
    if (!ImGui::Begin("LoadGame", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoDecoration)) {
        ImGui::End();
        return;
    }
    model->preLoadSaves();
    model->getSaves();
    static int selectedSave = 0;
    // TODO replace this char arrays with model data
    const char *saveNames[] = {"save0", "save1", "save2"};
    const char *savePlayer[] = {"John", "Joanna", "Gerald"};

    ImGui::ListBox("Save", &selectedSave, saveNames, IM_ARRAYSIZE(saveNames));
    ImGui::Text("Player: %s", savePlayer[selectedSave]);

    ImGui::Dummy({0, 20});
    if (ImGui::Button("Load game", {235, 30})) {
        model->loadSave();
    }
    if (ImGui::Button("Back###loadGame", {235, 30})) {
        actualView = ViewEnum::mainMenu;
    }
    ImGui::End();
}

void View::displayNewGame() {
    if (!ImGui::Begin("LoadGame", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoDecoration)) {
        ImGui::End();
        return;
    }
    if (ImGui::Button("Hot seat", {235, 30})) {
        model->newGame();
        actualView = ViewEnum::game;
    }
    ImGui::Dummy({0, 20});
    ImGui::PushItemFlag(ImGuiItemFlags_Disabled, true);
    if (ImGui::Button("LAN", {235, 30})) { ;
    }
    ImGui::PushItemFlag(ImGuiItemFlags_Disabled, false);
    ImGui::Dummy({0, 20});
    if (ImGui::Button("Back###newGame", {235, 30})) {
        actualView = ViewEnum::mainMenu;
    }
    ImGui::End();
}

void View::displayMenuLogo() {
    sf::Text text;

    text.setPosition(220.f, 20.f);
    text.setFont(font);
    text.setString("Almost Agricola");

    text.setCharacterSize(50);

    text.setFillColor({132, 144, 137});
    text.setStyle(sf::Text::Bold);

    window->draw(text);
}
