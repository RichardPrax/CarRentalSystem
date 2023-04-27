#pragma once

#include "include/json/json.h"

Json::Value CustomerJSONReader();
bool CheckLogin(Json::Value root, std::string& Username, std::string& Password);
bool SetLoginStatus(std::string& Username, std::string& Password);
void Output(std::string &User, Json::Value root);