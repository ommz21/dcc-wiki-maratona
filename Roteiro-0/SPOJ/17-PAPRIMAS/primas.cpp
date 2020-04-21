#include <iostream>
#include <string>

int main()
{
    std::string linha;
    int soma, divisores;
    char troca;
    std::string molde = " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    while(std::getline(std::cin, linha) && !linha.empty())
    {
        divisores = 1;
        soma = 0;
        for(int i = 0; i < linha.length(); i++)
            for(int j = 1; j <= 52; j++)
                if(linha[i] == molde[j])
                {
                    soma += j;
                    break;
                }
        for(int i = 2; i < soma; i++)
            if(soma % i == 0)
            {
                divisores++;
                break;
            }
        if(divisores == 1 && soma != 0)
            std::cout << "It is a prime word." << std::endl;
        else
            std::cout << "It is not a prime word." << std::endl;
    }
	return 0;
}