#include <iostream>

class CCar
{
    public:
        CCar(); 
        void SetProperties(int weight, float height, float length, std::string& color, std::string& modell, float price);

    private:
        int          m_Weight;
        float        m_Height;
        float        m_Length;
        std::string  m_Color;
        std::string  m_Modell;
        float        m_PricePerDay;
};

CCar::CCar()
    : m_Weight      (0)
    , m_Height      (0)
    , m_Length      (0.0)
    , m_Color       ("")
    , m_Modell      ("")
    , m_PricePerDay (0.0)
{
}

void CCar::SetProperties(int weight, float height, float length, std::string& color, std::string& modell, float price)
{
    m_Weight        = weight;
    m_Height        = height;
    m_Length        = length;
    m_Color         = color;
    m_Modell        = modell;
    m_PricePerDay   = price;
}

// this is a test