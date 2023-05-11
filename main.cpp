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
    int ChoiceOuterMenue;
    do
    {
        std::cout<<"Welcome to our car rental system!"<<std::endl;
        std::cout<<"(1) Register a new account (2) Login (3) Exit"<<std::endl;
        std::cin>>ChoiceOuterMenue;

        switch (ChoiceOuterMenue)
        {
        case 1:
            Customer.RegisterCustomer();
            Customer.WriteUserIntoJson();
            ChoiceOuterMenue = 1;
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
                ChoiceOuterMenue = 3;
            }
            else
            {
                std::cout<<"An error occured! Username or password inmcorrect!"<<std::endl;
            }
            break;

        case 3:
            system("cls");
            std::cout<<"See you next time!"<<std::endl;
            ChoiceOuterMenue = 3;
            break;

        default:
            std::cout<<"Invalid choice!"<<std::endl;
            break;
        }
        ChoiceOuterMenue = 0;
        if (IsLoggedIn)
        {
            Json::Value CustomerJSON = Customer.CustomerJSONReader();
            int ChoiceInnerMenue;
            do
            {
                std::cout<<"Welcome " << Username <<"! Pleas enter an option!"<<std::endl;
                std::cout<<"(1) Rent a car (2) Update account balance (3) Update personal information (4) See personal information (5) Logout"<<std::endl;
                std::cin>>ChoiceInnerMenue;

                switch (ChoiceInnerMenue)
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
                        case 5:
                            std::cout<<"Sucessfully logged out!"<<std::endl;
                            ChoiceInnerMenue = 5;
                            break;
                        default:
                            std::cout<<"Ivalid option!"<<std::endl;
                            break;
                    }
            } while (ChoiceInnerMenue != 5); 
            if (ChoiceInnerMenue !=3)
            {
                std::cout<<"(1) Register a new account (2) Login (3) Exit"<<std::endl;
                std::cin>>ChoiceOuterMenue;
            }
            
        }
    } while (ChoiceOuterMenue != 3);


    std::ifstream cars_input("Cars.json");
    Json::Reader reader;
    Json::Value TestCars;
    reader.parse(cars_input,TestCars);
    std::cout<<TestCars["Sport"]["Tesla"];
    std::cout<<TestCars["Hobby"]["BobbyCar"];
    return 0;
}