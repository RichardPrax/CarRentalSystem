#include <iostream>
#include <fstream>
#include <string>
#include "include/json/json.h"
#include "customer.h"



int main()
{
    std::string Username;
    std::string Password;
    CCustomer Customer;
    bool IsLoggedIn = false;
    int choice;
    do
    {
        std::cout<<"Welcome to our car rental system!"<<std::endl;
        std::cout<<"(1) Register a new account (2) Login (3) Exit"<<std::endl;
        std::cin>>choice;

        switch (choice)
        {
        case 1:
            Customer.RegisterCustomer();
            Customer.WriteUserIntoJson();
            choice = 1;
            break;

        case 2:
            
            std::cout<<"Enter Username: ";
            std::cin >> Username;
            std::cout<<"Enter Password: ";
            std::cin >> Password;

            if(Customer.SetLoginStatus(Username,Password))
            {
                std::cout<<"Sucessfully logged in!"<<std::endl;
                IsLoggedIn = true;
                choice = 3;
            }
            else
            {
                std::cout<<"An error occured! Username or password inmcorrect!"<<std::endl;
            }
            break;

        case 3:
            system("cls");
            std::cout<<"Successfully logged out!"<<std::endl;
            std::cout<<"See you next time!"<<std::endl;
            choice = 3;
            break;

        default:
            std::cout<<"Invalid choice!"<<std::endl;
            break;
        }

    } while (choice != 3);
    
    if (IsLoggedIn)
    {
        Json::Value CustomerJSON = Customer.CustomerJSONReader();
        int choice;
        std::cout<<"Welcome " << Username <<"! Pleas enter an option!"<<std::endl;
        std::cout<<"(1) Rent a car (2) Update account balance (3) Update personal information (4) See personal information"<<std::endl;
        std::cin>>choice;
        
        switch (choice)
        {
        case 1:
            std::cout<<"No car available!"<<std::endl;
            break;
        case 2:
        std::cout<<"Enter account balance: ";
            break;
        case 3:
            Customer.EditCustomerInformation(CustomerJSON, Username, Customer.ChoosePropertie(), Customer.SetValueForNewPropertie());
            break;
        case 4:
            Customer.GetCustomerInformation(Username,CustomerJSON);
            break;
        default:
            std::cout<<"Ivalid option!"<<std::endl;
            break;
        }
    }
    

    return 0;
}