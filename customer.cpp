#include "include/json/json.h"
#include "include/json/writer.h"
#include "customer.h"
#include <fstream>
#include <iostream>
#include <algorithm>

CCustomer::CCustomer()
    : m_FirstName   ("")
    , m_LastName    ("")
    , m_UserId      (0)
    , m_Password    ("")
    , m_Birthday    ("")
{
}

Json::Value CCustomer::CustomerJSONReader()
{
    std::ifstream customer_input("Customers.json");
    Json::Reader reader;
    Json::Value root;
    reader.parse(customer_input, root);
    return root;
}

bool CCustomer::CheckLogin(Json::Value root, std::string &Username, std::string &Password)
{
    bool IsCorret = false;
    std::string CorrectPassword = "Password";
    if (root[Username][CorrectPassword] == Password)
    {
        IsCorret = true;
    }
    return IsCorret;
}

bool CCustomer::SetLoginStatus(std::string &Username, std::string &Password)
{
    bool IsLoggedIn = false;
    if (CCustomer::CheckLogin(CCustomer::CustomerJSONReader(),Username,Password))
    {
        IsLoggedIn = true;
    }

    return IsLoggedIn;
}

void CCustomer::RegisterCustomer()
{
    // local Variables
    std::string FirstName="";
    std::string LastName="";
    std::string UserId="";
    std::string Password="";
    std::string Birthday="";

    std::cout<<"Firstname: ";
    std::cin>>FirstName;

    std::cout<<"Lastname: ";
    std::cin>>LastName;
    
    std::cout<<"UserId: ";
    std::cin>>UserId;

    std::cout<<"Password: ";
    std::cin>>Password;

    
    Birthday = GetBirthday();

    m_FirstName = FirstName;
    m_LastName = LastName;
    m_UserId = std::stoi(UserId);
    m_Password = Password;
    m_Birthday = Birthday;
    m_Username = m_FirstName.at(0) + m_LastName;
    // transform Username to lower case
    std::transform(m_Username.begin(), m_Username.end(), m_Username.begin(), ::tolower);
}

std::string CCustomer::GetBirthday()
{
    std::string Birthday;
    do
    {
        std::cout<<"Birthday (DD.MM.YYYY): ";
        std::cin>>Birthday;
    } while (Birthday.length() !=10 || Birthday.at(2) != '.' || Birthday.at(5) != '.');

    return Birthday;
}

void CCustomer::WriteUserIntoJson()
{
    // load old customer file into event
    Json::Value event = CCustomer::CustomerJSONReader(); 
    
    // defines new customer based on Firstname
    event[m_Username]["Firstname"] = m_FirstName;
    event[m_Username]["Lastname"]  = m_LastName;
    event[m_Username]["UserId"]    = m_UserId;
    event[m_Username]["Password"]  = m_Password;
    event[m_Username]["Birthday"]  = m_Birthday;

    // writes old + new Users into file
    Json::StreamWriterBuilder builder;
    builder["commentStyle"] = "None";
    builder["indentation"] = "    ";
    std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
    
    //Windows 
    //std::ofstream outputFileStream("C:/Users/Anwender/OneDrive/Code/privat/C++/OOP/CarRentalSystem/Customers.json");
    
    // MacOS
    std::ofstream outputFileStream("/Users/mwolfram/Desktop/Test/CarRentalSystem/Customers.json");
    writer -> write(event, &outputFileStream);
}

void CCustomer::GetCustomerInformation(std::string &Username, Json::Value root)
{
    std::cout << "Firstname:"   <<root [Username]["Firstname"] << std::endl;
    std::cout << "Lastname:"    <<root [Username]["Lastname"]  << std::endl;
    std::cout << "Password:"    <<root [Username]["Password"]  << std::endl;
    std::cout << "Birthday:"    <<root [Username]["Birthday"]  << std::endl;
    std::cout << "UserId:"      <<root [Username]["UserId"]    << std::endl;

}