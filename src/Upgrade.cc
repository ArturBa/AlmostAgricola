//
// Created by artur on 22/02/2020.
//

#include "Upgrade.hh"

std::map <UpgradeEnum, std::string> Upgrade::mapOfUpgradeFileNames = {
        {UpgradeEnum::Kitchen_0, "kitchen0"}
};
std::string Upgrade::getUpgradeFileName(const UpgradeEnum &upgrade) {
    try{
        return mapOfUpgradeFileNames.at(upgrade);
    }catch (const std::exception&) {
        return "test";
    }
}

std::string Upgrade::getJsonText(JsonLang &langJson, const UpgradeEnum &upgrade) {
    return langJson.getText(getUpgradeFileName(upgrade));
}

std::map<UpgradeEnum, Upgrade *> UpgradeFactory::mapOfUpgrades;

Upgrade *UpgradeFactory::getUpgrade(UpgradeEnum upgrade, JsonLang &langJson) {
    auto searchUpgrade = mapOfUpgrades.find(upgrade);
    if (searchUpgrade != mapOfUpgrades.end()) {
        return searchUpgrade->second;
    } else {
        mapOfUpgrades.insert(std::pair<UpgradeEnum, Upgrade *>{upgrade, new Upgrade(upgrade, langJson)});
        return mapOfUpgrades.at(upgrade);
    }
}

Upgrade::Upgrade(const UpgradeEnum upgrade, JsonLang &langJson) :
        text(Upgrade::getJsonText(langJson, upgrade)) {
    char fileNameBuffer[64];
    sprintf(fileNameBuffer, "../res/img/upgrade/%s.png", getUpgradeFileName(upgrade).c_str());
    texture.loadFromFile(fileNameBuffer);
}

const sf::Texture &Upgrade::getTexture() const {
    return texture;
}

const std::string &Upgrade::getText() const {
    return text;
}
