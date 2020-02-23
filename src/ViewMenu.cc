//
// Created by artur on 30/01/2020.
//

#include "ViewMenu.hh"

#define ICON_SIZE 32
#define ICON_NUMBER 3
#define DEFAULT_WINDOW_FLAGS (ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBackground)
#define BUTTON_SPACE            {  0,  25}
#define BUTTON_SIZE             {235,  30}
#define TITLE_TEXT_COLOR        {226, 226, 226, 255}


ViewMenu::ViewMenu(ViewController *_viewController) :
        ViewAbstract(_viewController), viewMenu(ViewMenuEnum::mainMenu) {

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

std::string ViewMenu::getJsonLangValue(const std::string &key) {
    return viewController->getShared()->lang.getText(key);
}

void ViewMenu::displayMainMenu() {
    displayText("Almost Agricola");
    if (!ImGui::Begin("Main Menu", nullptr, DEFAULT_WINDOW_FLAGS)) {
        ImGui::End();
        return;
    }
    if (ImGui::Button(getJsonLangValue("new_game").c_str(), BUTTON_SIZE)) {
        viewMenu = ViewMenuEnum::newGame;
    }
    ImGui::Dummy(BUTTON_SPACE);
    if (ImGui::Button(getJsonLangValue("load_game").c_str(), BUTTON_SIZE)) {
        viewMenu = ViewMenuEnum::loadGame;
    }
    ImGui::Dummy(BUTTON_SPACE);
    if (ImGui::Button(getJsonLangValue("settings").c_str(), BUTTON_SIZE)) {
        viewMenu = ViewMenuEnum::settings;
    }
    ImGui::Dummy(BUTTON_SPACE);
    if (ImGui::Button(getJsonLangValue("credits").c_str(), BUTTON_SIZE)) {
        viewMenu = ViewMenuEnum::credits;
    }
    ImGui::Dummy(BUTTON_SPACE);
    if (ImGui::Button(getJsonLangValue("exit").c_str(), BUTTON_SIZE)) {
        viewController->getShared()->window->close();
    }

    ImGui::End();
}

void ViewMenu::displayCredits() {
    displayText(getJsonLangValue("credits"));
    if (!ImGui::Begin("Credits", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove)) {
        ImGui::End();
        return;
    }

    ImGui::BeginChild("Credits##scroll", {235, 350});
    ImGui::TextWrapped("%s", getJsonLangValue("credits_text").c_str());

    ImGui::EndChild();

    if (ImGui::Button(getJsonLangValue("back").c_str(), BUTTON_SIZE)) {
        viewMenu = ViewMenuEnum::mainMenu;
    }

    ImGui::End();
}

int ViewMenu::getResFromIndex(int index) {
    switch (index) {
        case 0:
            return 800;
        case 1:
            return 1280;
        case 2:
            return 1920;
    }
}

int ViewMenu::getIndexFromRes(int res) {
    switch (res) {
        case 800:
            return 0;
        case 1280:
            return 1;
        case 1920:
            return 2;
    }
}

std::string ViewMenu::getLangFromIndex(int index) {
    switch (index) {
        case 0:
            return "eng";
        case 1:
            return "pl";
    }
}

int ViewMenu::getIndexFromLang(std::string lang) {
    if (lang == "eng")
        return 0;
    if (lang == "pl")
        return 1;
}

void ViewMenu::displaySettings() {
    displayText(getJsonLangValue("settings"));
    if (!ImGui::Begin("Settings", nullptr, DEFAULT_WINDOW_FLAGS)) {
        ImGui::End();
        return;
    }
    ImGui::PushItemWidth(235.f);
    ImGui::Text("%s:", getJsonLangValue("resolution").c_str());
    const char *res[] = {"800x600", "1280x720", "1920x1080"};
    static int selRes = getIndexFromRes(viewController->getShared()->settings->getResHor());
    ImGui::Combo("##res", &selRes, res, IM_ARRAYSIZE(res));

    ImGui::Text("%s:", getJsonLangValue("language").c_str());
    const char *lang[] = {"English", "Polski"};
    static int selLang = getIndexFromLang(viewController->getShared()->settings->getLang());
    ImGui::Combo("##lang", &selLang, lang, IM_ARRAYSIZE(lang));

    ImGui::Dummy(BUTTON_SPACE);
    if (ImGui::Button(getJsonLangValue("apply").c_str(), BUTTON_SIZE)) {
        viewController->getShared()->settings->setResHor(getResFromIndex(selRes));
        viewController->getShared()->settings->setLang(getLangFromIndex(selLang));
    }
    if (ImGui::Button(getJsonLangValue("back").c_str(), BUTTON_SIZE)) {
        viewMenu = ViewMenuEnum::mainMenu;
    }

    ImGui::End();
}

void ViewMenu::displayLoadGame() {
    displayText(getJsonLangValue("load_game"));
    if (!ImGui::Begin("LoadGame", nullptr, DEFAULT_WINDOW_FLAGS)) {
        ImGui::End();
        return;
    }
    static int selectedSave = 0;
    // TODO replace this char arrays with model data
    const char *saveNames[] = {"save0", "save1", "save2"};
    const char *savePlayer[] = {"John", "Joanna", "Gerald"};

    ImGui::PushItemWidth(245.f);
    ImGui::ListBox("", &selectedSave, saveNames, IM_ARRAYSIZE(saveNames));
    ImGui::Text("%s: %s", getJsonLangValue("player").c_str(), savePlayer[selectedSave]);

    ImGui::Dummy(BUTTON_SPACE);
    if (ImGui::Button(getJsonLangValue("load_game").c_str(), BUTTON_SIZE)) {
    }
    if (ImGui::Button(getJsonLangValue("back").c_str(), BUTTON_SIZE)) {
        viewMenu = ViewMenuEnum::mainMenu;
    }
    ImGui::End();
}

void ViewMenu::displayNewGame() {
    displayText(getJsonLangValue("new_game"));
    if (!ImGui::Begin("NewGame", nullptr, DEFAULT_WINDOW_FLAGS)) {
        ImGui::End();
        return;
    }
    if (ImGui::Button(getJsonLangValue("hot_seat").c_str(), BUTTON_SIZE)) {
        viewMenu = ViewMenuEnum::hotSeatConfig;
    }
    ImGui::Dummy(BUTTON_SPACE);
    ImGui::PushItemFlag(ImGuiItemFlags_Disabled, true);
    if (ImGui::Button(getJsonLangValue("LAN").c_str(), BUTTON_SIZE)) { ;
    }
    ImGui::PushItemFlag(ImGuiItemFlags_Disabled, false);
    ImGui::Dummy(BUTTON_SPACE);
    if (ImGui::Button(getJsonLangValue("back").c_str(), BUTTON_SIZE)) {
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

    text.setFillColor(TITLE_TEXT_COLOR);
    text.setStyle(sf::Text::Bold);

    viewController->getShared()->window->draw(text);
}

void ViewMenu::displayHotSeatConfig() {
    displayText(getJsonLangValue("hot_seat"));
    static int numberOfPlayers = 2;

    if (!ImGui::Begin("HotSeat##noplayers", nullptr, DEFAULT_WINDOW_FLAGS)) {
        ImGui::End();
        return;
    }
    ImGui::SliderInt(getJsonLangValue("number_of_players").c_str(), &numberOfPlayers, 2, 6);
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
    if (ImGui::Button(getJsonLangValue("start_game").c_str(), BUTTON_SIZE)) {
        viewController->switchTo(ViewEnum::game);
        viewController->getShared()->model.newGame();
    }
    if (ImGui::Button(getJsonLangValue("back").c_str(), BUTTON_SIZE)) {
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
    ImGui::Text("%s %i:", getJsonLangValue("player").c_str(), player_no + 1);
    ImGui::InputText("", player_name, 64);
    sprintf(nameBuffer, "Icon Selector##player%i", player_no);
    if (ImGui::ImageButton(sprite, {64, 64})) {
        ImGui::OpenPopup(nameBuffer);
    }
    if (ImGui::BeginPopupModal(nameBuffer, nullptr, ImGuiWindowFlags_NoDecoration)) {
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
        if (ImGui::Button(getJsonLangValue("select").c_str()))
            ImGui::CloseCurrentPopup();
        ImGui::EndPopup();
    }
    ImGui::End();
}
