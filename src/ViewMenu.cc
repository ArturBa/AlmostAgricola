//
// Created by artur on 30/01/2020.
//

#include "ViewMenu.hh"

#define ICON_SIZE 32
#define ICON_NUMBER 3
#define DEFAULT_WINDOW_FLAGS (ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBackground)
#define BUTTON_SPACE    {  0,  25}
#define BUTTON_SIZE     {235,  30}
#define TEXT_COLOR      {255, 255, 255, 255}


ViewMenu::ViewMenu(ViewController *_viewController) :
        ViewAbstract(_viewController), viewMenu(ViewMenuEnum::mainMenu) {
    viewController->getShared()->font.loadFromFile("../res/font/Lato-Black.ttf");
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    io.IniFilename = "../res/cnf/800_600.ini";

    texture.loadFromFile("../res/img/menu_dark_sheep.jpg");
    bgImage.setTexture(texture);
    sf::Vector2u size = texture.getSize();
    bgImage.setOrigin({static_cast<float>(size.x / 2), static_cast<float>(size.y / 2)});
    bgImage.setPosition({800.f / 2, 600.f / 2});
    float scale = 800. / size.x < 600. / size.y ? 600.f / size.y : 800.f / size.x;
    bgImage.setScale(scale, scale);
}

void ViewMenu::display() {
    ImGui::SFML::Update(*viewController->getShared()->window, viewController->getShared()->deltaClock.restart());
    viewController->getShared()->window->clear({206, 186, 162});
    displayBgImage();
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
    if (!ImGui::Begin("Main Menu", nullptr, DEFAULT_WINDOW_FLAGS )) {
        ImGui::End();
        return;
    }
    if (ImGui::Button("New Game", BUTTON_SIZE)) {
        viewMenu = ViewMenuEnum::newGame;
    }
    ImGui::Dummy(BUTTON_SPACE);
    if (ImGui::Button("Load Game", BUTTON_SIZE)) {
        viewMenu = ViewMenuEnum::loadGame;
    }
    ImGui::Dummy(BUTTON_SPACE);
    if (ImGui::Button("Settings", BUTTON_SIZE)) {
        viewMenu = ViewMenuEnum::settings;
    }
    ImGui::Dummy(BUTTON_SPACE);
    if (ImGui::Button("Credits", BUTTON_SIZE)) {
        viewMenu = ViewMenuEnum::credits;
    }
    ImGui::Dummy(BUTTON_SPACE);
    if (ImGui::Button("Exit", BUTTON_SIZE)) {
        viewController->getShared()->window->close();
    }

    ImGui::End();
}

void ViewMenu::displayCredits() {
    displayText("Credits");
    if (!ImGui::Begin("Credits", nullptr, DEFAULT_WINDOW_FLAGS)) {
        ImGui::End();
        return;
    }

    ImGui::BeginChild("Credits##scroll", {235, 350});
    ImGui::TextWrapped("All credits go here. Lorem ipsum. What if there is even more text?");
    ImGui::TextWrapped(
            "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur sapien sem, sagittis non dapibus id, tincidunt lacinia nulla. Morbi lobortis rhoncus dui, sit amet fringilla sapien pulvinar sit amet. Nullam neque eros, egestas quis pulvinar nec, vulputate non tellus. Praesent et elit ipsum. Aenean venenatis rhoncus quam sed iaculis. Cras pellentesque tristique nibh in hendrerit. Nullam ut efficitur diam. Donec imperdiet sapien id condimentum gravida. Praesent hendrerit pretium ipsum nec interdum. Sed tempus justo quam, vel blandit dolor porttitor non. Morbi rutrum, arcu in semper ullamcorper, diam urna feugiat turpis, vestibulum pharetra augue felis et mauris. ");
    ImGui::TextWrapped(
            "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur sapien sem, sagittis non dapibus id, tincidunt lacinia nulla. Morbi lobortis rhoncus dui, sit amet fringilla sapien pulvinar sit amet. Nullam neque eros, egestas quis pulvinar nec, vulputate non tellus. Praesent et elit ipsum. Aenean venenatis rhoncus quam sed iaculis. Cras pellentesque tristique nibh in hendrerit. Nullam ut efficitur diam. Donec imperdiet sapien id condimentum gravida. Praesent hendrerit pretium ipsum nec interdum. Sed tempus justo quam, vel blandit dolor porttitor non. Morbi rutrum, arcu in semper ullamcorper, diam urna feugiat turpis, vestibulum pharetra augue felis et mauris. ");

    ImGui::EndChild();

    if (ImGui::Button("Back###credits", BUTTON_SIZE)) {
        viewMenu = ViewMenuEnum::mainMenu;
    }

    ImGui::End();
}

void ViewMenu::displaySettings() {
    displayText("Settings");
    if (!ImGui::Begin("Settings", nullptr, DEFAULT_WINDOW_FLAGS)) {
        ImGui::End();
        return;
    }
    ImGui::Text("Resolution:");
    const char *res[] = {"800x600", "1366x766", "1920x1080"};
    static int selRes = 0;
    ImGui::Combo("##res", &selRes, res, IM_ARRAYSIZE(res));

    ImGui::Text("Language:");
    const char *lang[] = {"English", "Polski"};
    static int selLang = 0;
    ImGui::Combo("##lang", &selLang, lang, IM_ARRAYSIZE(lang));

    ImGui::Dummy(BUTTON_SPACE);
    if (ImGui::Button("Apply", BUTTON_SIZE)) {
    }
    ImGui::Dummy(BUTTON_SPACE);
    if (ImGui::Button("Back###settings", BUTTON_SIZE)) {
        viewMenu = ViewMenuEnum::mainMenu;
    }

    ImGui::End();
}

void ViewMenu::displayLoadGame() {
    displayText("Load Game");
    if (!ImGui::Begin("LoadGame", nullptr, DEFAULT_WINDOW_FLAGS)) {
        ImGui::End();
        return;
    }
    static int selectedSave = 0;
    // TODO replace this char arrays with model data
    const char *saveNames[] = {"save0", "save1", "save2"};
    const char *savePlayer[] = {"John", "Joanna", "Gerald"};

    ImGui::ListBox("Save", &selectedSave, saveNames, IM_ARRAYSIZE(saveNames));
    ImGui::Text("Player: %s", savePlayer[selectedSave]);

    ImGui::Dummy(BUTTON_SPACE);
    if (ImGui::Button("Load game", BUTTON_SIZE)) {
    }
    if (ImGui::Button("Back###loadGame", BUTTON_SIZE)) {
        viewMenu = ViewMenuEnum::mainMenu;
    }
    ImGui::End();
}

void ViewMenu::displayNewGame() {
    displayText("New Game");
    if (!ImGui::Begin("NewGame", nullptr, DEFAULT_WINDOW_FLAGS)) {
        ImGui::End();
        return;
    }
    if (ImGui::Button("Hot seat", BUTTON_SIZE)) {
        viewMenu = ViewMenuEnum::hotSeatConfig;
    }
    ImGui::Dummy(BUTTON_SPACE);
    ImGui::PushItemFlag(ImGuiItemFlags_Disabled, true);
    if (ImGui::Button("LAN", BUTTON_SIZE)) { ;
    }
    ImGui::PushItemFlag(ImGuiItemFlags_Disabled, false);
    ImGui::Dummy(BUTTON_SPACE);
    if (ImGui::Button("Back###newGame", BUTTON_SIZE)) {
        viewMenu = ViewMenuEnum::mainMenu;
    }
    ImGui::End();
}

void ViewMenu::displayBgImage() {
    viewController->getShared()->window->draw(bgImage);
}

void ViewMenu::displayText(const std::string &_text) {
    sf::Text text;

    float positionX = (800.f - _text.length() * 25.f) / 2.f;
    text.setPosition(positionX, 20.f);
    text.setFont(viewController->getShared()->font);
    text.setString(_text);

    text.setCharacterSize(50);

    text.setFillColor(TEXT_COLOR);
    text.setStyle(sf::Text::Bold);

    viewController->getShared()->window->draw(text);
}

void ViewMenu::displayHotSeatConfig() {
    displayText("Hot seat");
    static int numberOfPlayers = 2;

    if (!ImGui::Begin("HotSeat##noplayers", nullptr, DEFAULT_WINDOW_FLAGS)) {
        ImGui::End();
        return;
    }
    ImGui::SliderInt("Number of players##hotseat", &numberOfPlayers, 2, 6);
    ImGui::End();
    static char playerNames[6][64] = {
            "Player name",
            "Player name",
            "Player name",
            "Player name",
            "Player name",
            "Player name"
    };
    static int playerIcon[6] = {0};

    displayPlayer(playerNames[0], playerIcon[0], 0, numberOfPlayers);
    displayPlayer(playerNames[1], playerIcon[1], 1, numberOfPlayers);
    displayPlayer(playerNames[2], playerIcon[2], 2, numberOfPlayers);
    displayPlayer(playerNames[3], playerIcon[3], 3, numberOfPlayers);
    displayPlayer(playerNames[4], playerIcon[4], 4, numberOfPlayers);
    displayPlayer(playerNames[5], playerIcon[5], 5, numberOfPlayers);

    if (!ImGui::Begin("HotSeat", nullptr, DEFAULT_WINDOW_FLAGS)) {
        ImGui::End();
        return;
    }
    if (ImGui::Button("Start Game", BUTTON_SIZE)) {
        viewController->switchTo(ViewEnum::game);
    }
    if (ImGui::Button("Back###hotSeat", BUTTON_SIZE)) {
        viewMenu = ViewMenuEnum::newGame;
    }
    ImGui::End();
}

void ViewMenu::displayPlayer(char *player_name, int &player_icon, int player_no, int active_players) {
    char nameBuffer[64];
    sf::Sprite sprite(viewController->getShared()->texturePlayers);
    sprite.setTextureRect(sf::Rect(player_icon * ICON_SIZE, 0, ICON_SIZE, ICON_SIZE));
    sprintf(nameBuffer, "HotSeat###player%d", player_no);
    if (!ImGui::Begin(nameBuffer, nullptr, DEFAULT_WINDOW_FLAGS)) {
        ImGui::End();
        return;
    }
    if (player_no >= active_players) {
        ImGui::PushItemFlag(ImGuiItemFlags_Disabled, true);
    }
    ImGui::Text("Player %i:", player_no + 1);
    ImGui::InputText("", player_name, 64);
    sprintf(nameBuffer, "Icon Selector##player%i", player_no);
    if (ImGui::ImageButton(sprite, {64, 64})) {
        ImGui::OpenPopup(nameBuffer);
    }
    if (ImGui::BeginPopupModal(nameBuffer, nullptr)) {
        for (int i = 0; i < ICON_NUMBER; i++) {
            if (i % 4)
                ImGui::SameLine();

            sprite.setTextureRect({i * ICON_SIZE, 0, ICON_SIZE, ICON_SIZE});
            ImGui::PushID(100 + i);
            if (ImGui::ImageButton(sprite, {64, 64})) {
                player_icon = i;
            }
            ImGui::PopID();
        }
        if (ImGui::Button("Select"))
            ImGui::CloseCurrentPopup();
        ImGui::EndPopup();
    }
    ImGui::End();
}
