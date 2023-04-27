#include <iostream>
#include <fstream>
#include <string>
#include "include/json/json.h"

void Output(std::string &Car, Json::Value &root)
{
    std::cout << root [Car]["Name"] << std::endl;
    std::cout << root [Car]["CarID"] << std::endl;
    std::cout << root [Car]["PricePerDay"] << std::endl;
}

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
    Output(Car1,root);
    std::cout << sizeof(Json::Value *) <<std::endl;
    std::cout << sizeof(&root);
    return 0;
}

