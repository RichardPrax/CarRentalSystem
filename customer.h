#pragma once

#include "include/json/json.h"

class CCustomer
{
    public:
        CCustomer();
        Json::Value CustomerJSONReader();
        bool CheckLogin(Json::Value root, std::string& Username, std::string& Password);
        bool SetLoginStatus(std::string& Username, std::string& Password);
        void Output(std::string &User, Json::Value root);

        void RegisterCustomer();
        void WriteUserIntoJson();
        
        std::string GetCustomer(std::string& Username);

    private:
        std::string m_FirstName;
        std::string m_LastName;
        int         m_UserId;
        std::string m_Password;
        std::string m_Birthday;
    
};





