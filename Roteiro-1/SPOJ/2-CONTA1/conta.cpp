#include <iostream>

int main()
{
    int consumo;
    std::cin >> consumo;
    int preco = 7;
    for(int contados = 0; consumo >= 0; contados++, consumo--)
    {
        if (contados <= 10)
        {/* continua */}    
        else if (contados <= 30)
            preco += 1;
        else if(contados <= 100)
            preco += 2;
        else
            preco += 5;
    }
    std::cout << preco;
    return 0;
}