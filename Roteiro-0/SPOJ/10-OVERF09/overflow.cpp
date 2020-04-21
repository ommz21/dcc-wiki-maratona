#include <iostream>

int main()
{
    int n, p, q;
    char c;
    std::cin >> n;
    std::cin >> p;
    std::cin >> c;
    std::cin >> q;
    if(c == '+')
    {
        if(p + q > n)
            std::cout << "OVERFLOW";
        else
            std::cout << "OK";
    }
    else if (c == '*')
    {
        if(p * q > n)
            std::cout << "OVERFLOW";
        else
            std::cout << "OK";
    }
    return 0;
}