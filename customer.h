#pragma once

#include "include/json/json.h"

class CCustomer
{
    public:
        CCustomer();
        Json::Value CustomerJSONReader();
        bool CheckLogin(Json::Value root, std::string& Username, std::string& Password);
        bool SetLoginStatus(std::string& Username, std::string& Password);
        
        void RegisterCustomer();
        void WriteUserIntoJson();
        std::string GetBirthday();

        void GetCustomerInformation(std::string &Username, Json::Value root);
        void EditCustomerInformation(Json::Value root, std::string &Username, std::string Propertie, std::string Value);        
        std::string ChoosePropertie();
        std::string SetValueForNewPropertie(); 

    private:
        std::string m_FirstName;
        std::string m_LastName;
        int         m_UserId;
        std::string m_Username; // Username has format Example: rprax, Name Richard Prax, mwolfram, Name Max Wolfram 
        std::string m_Password;
        std::string m_Birthday;
    
};





