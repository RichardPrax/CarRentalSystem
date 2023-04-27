#include <iostream>
#include <fstream>
#include <string>
#include "include/json/json.h"
#include "customer.h"


int main()
{
    std::string Username;
    std::getline(std::cin, Username);
    std::string Password;
    std::getline(std::cin, Password);
    
    if (SetLoginStatus(Username,Password))
    {
        Output(Username,CustomerJSONReader());
    }
    else
    {
        std::cout<<"Invalid login!"<<std::endl;
    }




    /*
    std::cout << root << std::endl;
    std::cout << root["test"]["CarID"] << std::endl;
    std::cout << root ["test"]["Name"] << std::endl;
    std::string Car1 = "cars";
    Output(Car1,root);
    std::cout << sizeof(Json::Value *) <<std::endl;
    std::cout << sizeof(&root);
    */
    return 0;
}

