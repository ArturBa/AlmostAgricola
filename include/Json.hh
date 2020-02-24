//
// Created by artur on 14/02/2020.
//

#pragma once

#include <nlohmann/json.hpp>
#include <string>
#include <fstream>

using json = nlohmann::json;

/**
 * @brief Load json from file
 * @param _fileName file name
 * @return json pointer from loaded file
 */
json *LoadJsonFromFile(const std::string &_fileName);

/**
 * @brief Save json to a file
 * @param _json Json to save
 * @param _fileName save file name
 */
void SaveJsonToFile(const json &_json, const std::string &_fileName);

