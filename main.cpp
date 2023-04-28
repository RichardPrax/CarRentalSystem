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

    CCustomer Customer;
    int choice;
    do
    {
        std::cout<<"Welcome to our car rental system!"<<std::endl;
        std::cout<<"(1) Register a new account (2) Exit"<<std::endl;
        std::cin>>choice;

        switch (choice)
        {
        case 1:
            choice = 1;
            Customer.RegisterCustomer();
            Customer.WriteUserIntoJson();
            break;
        case 2:
            std::cout<<"See you next time!"<<std::endl;
            choice = 0;
            break;

        default:
            std::cout<<"Invalid choice!"<<std::endl;
            break;
        }

    } while (choice != 0);
    

    return 0;
}

