#include <iostream>
#include <algorithm>

int trocar(int chegada[], int indice_i, int indice_f)
{
    int trocas = 0;
    for (int i = indice_f; i > indice_i; i--, trocas++)
        std::swap(chegada[i],chegada[i-1]);
    return trocas;
}

int main()
{
    int quant, atual, trocas, *largada, *chegada;

    while (true)
    {
        try
        {
            std::cin >> quant;
            if(quant < 1 || quant > 100 || std::cin.fail() || std::cin.eof())
                throw std::exception();
        }
        catch(const std::exception& e)
        {
            std::cin.clear();
        	std::cin.ignore(1000, '\n');
        	return 0;
        }

        largada = new int [quant];
        chegada = new int [quant];

        for (int i = 0; i < quant; i++)
            std::cin >> largada[i];
        for (int i = 0; i < quant; i++)
            std::cin >> chegada[i];
        
        trocas = 0;

        for (int i = 0; i < quant; i++)
        {
            if(chegada[i] != largada[i])
            {
                for (int j = i; j < quant; j++)
                    if(chegada[j] == largada[i])
                        atual = j;
                trocas += trocar(chegada, i, atual);
            }
        }

        std::cout << trocas << std::endl;

        delete [] largada;
        delete [] chegada;
    }
    return 0;
}