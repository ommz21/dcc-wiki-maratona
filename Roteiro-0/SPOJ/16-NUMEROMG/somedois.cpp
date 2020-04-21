#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

int main()
{
    std::string linha;
    std::string palavra;
    std::istringstream stream;
    int multi, soma, res, quoc, flag;
    char troca;
    std::string hex;
    std::string molde = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    while(std::getline(std::cin, linha) && !linha.empty())
    {
        hex = "";
        flag = 0;
        soma = 0;
        stream = std::istringstream(linha);
        while(std::getline(stream, palavra, ' '))
        {
            if(palavra == "0")
                flag++;
            if(flag == 2)
                return 0;
            multi = palavra.size() - 1;
            for(int i = 0; i < palavra.size(); i++, multi--)
                for(int j = 1; j < 36; j++)
                    if(palavra[i] == molde[j])
                        soma += j * (std::pow(36, multi));
        }
        while(soma)
        {
            res = soma % 36;
            soma = soma / 36;
            hex += molde[res];
        }
        soma = hex.length();
        for(int i = 0; i < soma / 2; i++)
        {
            troca = hex[i];
            hex[i] = hex[soma - i - 1];
            hex[soma - i - 1] = troca;
        }
        std::cout << hex << std::endl;
    }
	return 0;
}