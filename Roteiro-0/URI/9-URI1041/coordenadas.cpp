#include <iostream>

int main()
{
    float x, y;
    std::cin >> x;
    std::cin >> y;
    if(x == 0)
    {
        if(y == 0)
            std::cout << "Origem";
        else
            std::cout << "Eixo Y";     
    }
    else if (y == 0)
    {
        std::cout << "Eixo X";
    }
    else if(x > 0)
    {
        if(y > 0)
            std::cout << "Q1";
        else
            std::cout << "Q4";
    }
    else
    {
        if(y > 0)
            std::cout << "Q2";
        else
            std::cout << "Q3";
    }
    std::cout << std::endl;
    return 0;
}