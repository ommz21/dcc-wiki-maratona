#include <iostream>
#include <string>

int main()
{
    int quant;
    std::string palavra;
    std::string palavrad;
    std::cin >> quant;
    bool ordenada;
    for(int j = 0; j < quant; j++)
    {
        ordenada = true;
        std::cin >> palavra;
        palavrad = palavra;
        for (int i = 0; i < palavra.size(); i++)
            palavrad[i] = tolower(palavra[i]);
        for (int i = 0; i < palavrad.size() - 1; i++)
            if(palavrad[i] >= palavrad[i+1])
                ordenada = false;
        std::cout <<  palavra << ": ";
        if(ordenada)
            std::cout << "O";
        else
            std::cout << "N";
        std::cout << std::endl;
    } 
    return 0;
}