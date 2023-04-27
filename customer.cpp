#include "include/json/json.h"
#include "customer.h"
#include <fstream>
#include <iostream>

Json::Value CustomerJSONReader()
{
    std::ifstream file_input("Customers.json");
    Json::Reader reader;
    Json::Value root;
    reader.parse(file_input, root);
    return root;
}

bool CheckLogin(Json::Value root, std::string& Username, std::string& Password)
{
    bool IsCorret = false;
    std::string CorrectPassword = "Password";
    if (root[Username][CorrectPassword] == Password)
    {
        IsCorret = true;
    }
    return IsCorret;
}

bool SetLoginStatus(std::string& Username, std::string& Password)
{
    bool IsLoggedIn = false;
    if (CheckLogin(CustomerJSONReader(),Username,Password))
    {
        IsLoggedIn = true;
    }

    return IsLoggedIn;
}



void Output(std::string &User, Json::Value root)
{
    std::cout << "Name:"     <<root [User]["Name"]          << std::endl;
    std::cout << "UserID:"   <<root [User]["UserID"]        << std::endl;
    std::cout << "Password:" <<root [User]["Password"]      << std::endl;
    std::cout << "Birthday:" <<root [User]["Birthday"]      << std::endl;
}