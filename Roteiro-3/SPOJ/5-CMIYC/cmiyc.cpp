#include <iostream>

int main()
{
    int testes;
    long long int comprimento;
    std::cin >> testes;
    for (int i = 0; i < testes; i++)
    {
        std::cin >> comprimento;
        if ((comprimento % 3) == 0)
            std::cout << comprimento / 3;
        else
            std::cout << 0;
        std::cout << std::endl;
    }
    return 0;
}
