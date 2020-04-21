#include <iostream>

int main()
{
    int valor, maior, posicao;
    maior = -1;
    for(int i = 1; i <= 100; i++)
    {
        std::cin >> valor;
        if(valor > maior)
        {
            maior = valor;
            posicao = i;
        }
    }
    std::cout << maior << std::endl << posicao << std::endl;
    return 0;
}