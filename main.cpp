#include <iostream>
#include <fstream>
#include "include/json/json.h"


int main()
{
    std::ifstream file_input("cars.json");
    Json::Reader reader;
    Json::Value root;
    reader.parse(file_input, root);
    std::cout << root << std::endl;
    std::cout << root["test"]["CarID"];
    return 0;
}

