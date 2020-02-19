//
// Created by artur on 19/02/2020.
//

#pragma once

#include "Json.hh"
#include "Observer.hh"


class JsonLang : public Observer {
private:
    nlohmann::json *textJson;

    JsonLang(Sender *sender);

public:
    std::string getText(const std::string &key, const std::string &default_value);

    void update() override;

};


