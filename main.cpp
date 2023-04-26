#include <iostream>
#include <fstream>
#include "json/json.h"


int main()
{
std::ifstream file_input("input.json");
Json::Reader reader;
Json::Value root;
reader.parse(file_input, root);
cout << root;
    return 0;
}

