#include "include/json/json.h"
#include "include/json/writer.h"
#include "customer.h"
#include <fstream>
#include <iostream>

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

bool CCustomer::CheckLogin(Json::Value root, std::string& Username, std::string& Password)
{
    bool IsCorret = false;
    std::string CorrectPassword = "Password";
    if (root[Username][CorrectPassword] == Password)
    {
        IsCorret = true;
    }
    return IsCorret;
}

bool CCustomer::SetLoginStatus(std::string& Username, std::string& Password)
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
    std::string FirstName;
    std::string LastName;
    int         UserId;
    std::string Password;
    std::string Birthday;

    std::cout<<"Firstname: ";
    std::getline(std::cin,FirstName);
    m_FirstName = FirstName;

    std::cout<<"Lastname: ";
    std::getline(std::cin,LastName);
    m_LastName = LastName;

    std::cout<<"UserId: ";
    std::cin>>UserId;
    std::cout<<std::endl;
    m_UserId = UserId;

    std::cout<<"Password: ";
    std::getline(std::cin,Password);
    m_Password = Password;

    std::cout<<"Birthday: ";
    std::getline(std::cin,Birthday);
    m_Birthday = Birthday;
}

void CCustomer::WriteUserIntoJson()
{
    Json::Value event;
    event[m_FirstName]["Firstname"] = m_FirstName;
    event[m_FirstName]["Lastname"]  = m_LastName;
    event[m_FirstName]["UserId"]    = m_UserId;
    event[m_FirstName]["Password"]  = m_Password;
    event[m_FirstName]["Birthday"]  = m_Birthday;

    Json::StreamWriterBuilder builder;
    builder["commentStyle"] = "None";
    builder["indentation"] = " ";

    std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
    std::ofstream outputFileStream("/test.json");
    writer -> write(event, &outputFileStream);
}

std::string CCustomer::GetCustomer(std::string& Username)
{

}

void CCustomer::Output(std::string &User, Json::Value root)
{
    std::cout << "Name:"     <<root [User]["Name"]          << std::endl;
    std::cout << "UserID:"   <<root [User]["UserID"]        << std::endl;
    std::cout << "Password:" <<root [User]["Password"]      << std::endl;
    std::cout << "Birthday:" <<root [User]["Birthday"]      << std::endl;
}