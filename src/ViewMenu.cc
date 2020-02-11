//
// Created by artur on 30/01/2020.
//

#include "ViewMenu.hh"

#define ICON_SIZE 32
#define ICON_NUMBER 3


ViewMenu::ViewMenu(ViewController *_viewController) :
        ViewAbstract(_viewController), viewMenu(ViewMenuEnum::mainMenu) {
    viewController->getShared()->font.loadFromFile("../res/font/Lato-Black.ttf");
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    io.IniFilename = "../res/cnf/800_600.ini";
// TODO change button colors
//    ImGui::PushStyleColor(ImGuiCol_Button, {103, 103, 103, 0});
//    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, {0, 0, 0, 255});
//    ImGui::PushStyleColor(ImGuiCol_ButtonActive, {0, 0, 0, 255});
}

void ViewMenu::display() {
    ImGui::SFML::Update(*viewController->getShared()->window, viewController->getShared()->deltaClock.restart());
    viewController->getShared()->window->clear({206, 186, 162});
    switch (viewMenu) {
        case ViewMenuEnum::mainMenu:
            displayMainMenu();
            break;
        case ViewMenuEnum::newGame:
            displayNewGame();
            break;
        case ViewMenuEnum::loadGame:
            displayLoadGame();
            break;
        case ViewMenuEnum::settings:
            displaySettings();
            break;
        case ViewMenuEnum::credits:
            displayCredits();
            break;
        case ViewMenuEnum::hotSeatConfig:
            displayHotSeatConfig();
            break;
    }
    ImGui::SFML::Render(*viewController->getShared()->window);
    viewController->getShared()->window->display();
}

void ViewMenu::displayMainMenu() {
    displayText("Almost Agricola");
    ImVec2 buttonSpace(0, 25.f);
    ImVec2 buttonSize(235, 30);
    if (!ImGui::Begin("Main Menu", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove)) {
        ImGui::End();
        return;
    }
    ImGui::PushItemWidth(235);
    if (ImGui::Button("New Game", buttonSize)) {
        viewMenu = ViewMenuEnum::newGame;
    }
    ImGui::Dummy(buttonSpace);
    if (ImGui::Button("Load Game", buttonSize)) {
        viewMenu = ViewMenuEnum::loadGame;
    }
    ImGui::Dummy(buttonSpace);
    if (ImGui::Button("Settings", buttonSize)) {
        viewMenu = ViewMenuEnum::settings;
    }
    ImGui::Dummy(buttonSpace);
    if (ImGui::Button("Credits", buttonSize)) {
        viewMenu = ViewMenuEnum::credits;
    }
    ImGui::Dummy(buttonSpace);
    if (ImGui::Button("Exit", buttonSize)) {
        viewController->getShared()->window->close();
    }

    ImGui::End();
}

void ViewMenu::displayCredits() {
    displayText("Credits");
    if (!ImGui::Begin("Credits", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove)) {
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
        viewMenu = ViewMenuEnum::mainMenu;
    }

    ImGui::End();
}

void ViewMenu::displaySettings() {
    displayText("Settings");
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
    }
    ImGui::Dummy({0, 20});
    if (ImGui::Button("Back###settings", {235, 30})) {
        viewMenu = ViewMenuEnum::mainMenu;
    }

    ImGui::End();
}

void ViewMenu::displayLoadGame() {
    displayText("Load Game");
    if (!ImGui::Begin("LoadGame", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoDecoration)) {
        ImGui::End();
        return;
    }
    static int selectedSave = 0;
    // TODO replace this char arrays with model data
    const char *saveNames[] = {"save0", "save1", "save2"};
    const char *savePlayer[] = {"John", "Joanna", "Gerald"};

    ImGui::ListBox("Save", &selectedSave, saveNames, IM_ARRAYSIZE(saveNames));
    ImGui::Text("Player: %s", savePlayer[selectedSave]);

    ImGui::Dummy({0, 20});
    if (ImGui::Button("Load game", {235, 30})) {
    }
    if (ImGui::Button("Back###loadGame", {235, 30})) {
        viewMenu = ViewMenuEnum::mainMenu;
    }
    ImGui::End();
}

void ViewMenu::displayNewGame() {
    displayText("New Game");
    if (!ImGui::Begin("NewGame", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoDecoration)) {
        ImGui::End();
        return;
    }
    if (ImGui::Button("Hot seat", {235, 30})) {
        viewMenu = ViewMenuEnum::hotSeatConfig;
    }
    ImGui::Dummy({0, 20});
    ImGui::PushItemFlag(ImGuiItemFlags_Disabled, true);
    if (ImGui::Button("LAN", {235, 30})) { ;
    }
    ImGui::PushItemFlag(ImGuiItemFlags_Disabled, false);
    ImGui::Dummy({0, 20});
    if (ImGui::Button("Back###newGame", {235, 30})) {
        viewMenu = ViewMenuEnum::mainMenu;
    }
    ImGui::End();
}

void ViewMenu::displayText(const std::string &_text) {
    sf::Text text;

    float positionX = (800.f - _text.length() * 25.f) / 2.f;
    text.setPosition(positionX, 20.f);
    text.setFont(viewController->getShared()->font);
    text.setString(_text);

    text.setCharacterSize(50);

    text.setFillColor({132, 144, 137});
    text.setStyle(sf::Text::Bold);

    viewController->getShared()->window->draw(text);
}

void ViewMenu::displayHotSeatConfig() {
    displayText("Hot seat");
    static int numberOfPlayers = 2;

    if (!ImGui::Begin("HotSeat##noplayers", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove)) {
        ImGui::End();
        return;
    }
    ImGui::SliderInt("Number of players##hotseat", &numberOfPlayers, 2, 6);
    ImGui::End();
    static char player_names[6][64] = {
            "Player name",
            "Player name",
            "Player name",
            "Player name",
            "Player name",
            "Player name"
    };
    static int player_icon[6] = {2};
    ImGui::ShowMetricsWindow();

    if (!ImGui::Begin("HotSeat###player1", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove)) {
        ImGui::End();
        return;
    }
    ImGui::Text("Player 1:");
    ImGui::InputText("", player_names[0], 64);
    sf::Sprite sprite(viewController->getShared()->texturePlayers);
    sprite.setTextureRect(sf::Rect(player_icon[0] * ICON_SIZE, 0, ICON_SIZE, ICON_SIZE));
    if (ImGui::ImageButton(sprite, {64, 64})) { ;
        ImGui::OpenPopup("Icon Selector##player1");
    }
    if (ImGui::BeginPopupModal("Icon Selector##player1", nullptr)) {
        for (int i = 0; i < ICON_NUMBER; i++) {
            if (i % 4)
                ImGui::SameLine();

            sprite.setTextureRect({i * ICON_SIZE, 0, ICON_SIZE, ICON_SIZE});
            ImGui::PushID(100 + i);
            if (ImGui::ImageButton(sprite, {64, 64})) {
                player_icon[0] = i;
            }
            ImGui::PopID();
        }
        if (ImGui::Button("Select"))
            ImGui::CloseCurrentPopup();
        ImGui::EndPopup();
    }
    ImGui::End();

    if (!ImGui::Begin("HotSeat###player2", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove)) {
        ImGui::End();
        return;
    }
    ImGui::Text("Player 2:");
    ImGui::InputText("", player_names[1], 64);
    sprite.setTextureRect(sf::Rect(player_icon[1] * ICON_SIZE, 0, ICON_SIZE, ICON_SIZE));
    if (ImGui::ImageButton(sprite, {64, 64})) { ;
        ImGui::OpenPopup("Icon Selector##player2");
    }
    if (ImGui::BeginPopupModal("Icon Selector##player2", nullptr)) {
        for (int i = 0; i < ICON_NUMBER; i++) {
            if (i % 4)
                ImGui::SameLine();
            sprite.setTextureRect({i * ICON_SIZE, 0, ICON_SIZE, ICON_SIZE});
            if (ImGui::ImageButton(sprite, {64, 64})) {
                std::cout << "selected icon: " << i << '\n';
                player_icon[1] = i;
            }
        }
        if (ImGui::Button("Select"))
            ImGui::CloseCurrentPopup();
        ImGui::EndPopup();
    }
    ImGui::End();

    if (!ImGui::Begin("HotSeat###player3", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove)) {
        ImGui::End();
        return;
    }
    if (numberOfPlayers < 3)
        ImGui::PushItemFlag(ImGuiItemFlags_Disabled, true);
    ImGui::Text("Player 3:");
    ImGui::InputText("", player_names[2], 64);
    sprite.setTextureRect(sf::Rect(32, 0, 32, 32));
    if (ImGui::ImageButton(sprite, {64, 64})) { ;
    }
    ImGui::End();

    if (!ImGui::Begin("HotSeat###player4", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove)) {
        ImGui::End();
        return;
    }
    if (numberOfPlayers < 4)
        ImGui::PushItemFlag(ImGuiItemFlags_Disabled, true);
    ImGui::Text("Player 4:");
    ImGui::InputText("", player_names[3], 64);
    sprite.setTextureRect(sf::Rect(32, 0, 32, 32));
    if (ImGui::ImageButton(sprite, {64, 64})) { ;
    }
    ImGui::End();

    if (!ImGui::Begin("HotSeat###player5", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove)) {
        ImGui::End();
        return;
    }
    if (numberOfPlayers < 5)
        ImGui::PushItemFlag(ImGuiItemFlags_Disabled, true);
    ImGui::Text("Player 5:");
    ImGui::InputText("", player_names[4], 64);
    sprite.setTextureRect(sf::Rect(32, 0, 32, 32));
    if (ImGui::ImageButton(sprite, {64, 64})) { ;
    }
    ImGui::End();

    if (!ImGui::Begin("HotSeat###player6", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove)) {
        ImGui::End();
        return;
    }
    if (numberOfPlayers < 6)
        ImGui::PushItemFlag(ImGuiItemFlags_Disabled, true);
    ImGui::Text("Player 6:");
    ImGui::InputText("", player_names[5], 64);
    sprite.setTextureRect(sf::Rect(32, 0, 32, 32));
    if (ImGui::ImageButton(sprite, {64, 64})) { ;
    }
    ImGui::End();

    if (!ImGui::Begin("HotSeat", nullptr, ImGuiWindowFlags_NoDecoration)) {
        ImGui::End();
        return;
    }
    if (ImGui::Button("Start Game", {235, 30})) {
        viewController->switchTo(ViewEnum::game);
    }
    if (ImGui::Button("Back###hotSeat", {235, 30})) {
        viewMenu = ViewMenuEnum::newGame;
    }
    ImGui::End();

}
