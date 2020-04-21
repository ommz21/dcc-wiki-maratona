#include <iostream>

int main()
{
    int r, a, b, valor, teste;
    r = 1;
    teste = 0;
    while(r)
    {
        std::cin >> r;
        if(r == 0)
            break;
        a = 0;
        b = 0;
        teste++;
        for(int i = 0; i < r; i++)
        {
            std::cin >> valor;
            a += valor;
            std::cin >> valor;
            b += valor;
        }
        std::cout << "Teste " << teste << std::endl;
        if(a >= b)
            std::cout << "Aldo" << std::endl;
        else
            std::cout << "Beto" << std::endl;
        std::cout << std::endl;
    }
}