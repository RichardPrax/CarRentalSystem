#include <iostream>
#include <fstream>
#include <string>
#include "include/json/json.h"


int main()
{
    std::ifstream file_input("cars.json");
    Json::Reader reader;
    Json::Value root;
    reader.parse(file_input, root);
    std::cout << root << std::endl;
    std::cout << root["test"]["CarID"] << std::endl;
    std::cout << root ["test"]["Name"] << std::endl;
    std::string Car1 = "cars";
    std::cout << root [Car1]["Name"] << std::endl;
    return 0;
}

