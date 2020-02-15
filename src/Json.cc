//
// Created by artur on 14/02/2020.
//
#include <Json.hh>

json *LoadJsonFromFile(const std::string &_fileName) {
    std::ifstream input_stream(_fileName);
    if (!input_stream) {
        return nullptr;
    }
    json *json_temp = new json(json::parse(input_stream));
    return json_temp;
}
