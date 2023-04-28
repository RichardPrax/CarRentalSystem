#include <iostream>
#include <fstream>
#include <string>
#include "include/json/json.h"
#include "customer.h"


int main()
{
    /*
    std::string Username;
    std::cout<<"Enter Username: ";
    std::getline(std::cin, Username);
    std::string Password;
    std::cout<<"Enter Password: ";
    std::getline(std::cin, Password);
    if (SetLoginStatus(Username,Password))
    {
        Output(Username,CustomerJSONReader());
    }
    else
    {
        std::cout<<"Invalid login!"<<std::endl;
    }
    */

   CCustomer Customer1;
   Customer1.RegisterCustomer();
   Customer1.WriteUserIntoJson();

    return 0;
}

