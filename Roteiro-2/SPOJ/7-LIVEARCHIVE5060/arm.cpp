#include <iostream>
#include <queue>
#include <vector>
#include <math.h>

int main()
{
    int quant, potencia, rodada, k, forca, perdedor;
    std::pair< int, int > compet, compet2, aux; 
    std::cin >> quant;
    for (int i = 0; i < quant; i++)
    {
        std::queue< std::pair < int, int > > fila;
        std::vector< std::pair < int, int > > historico;
        std::cin >> potencia >> k;
        rodada = pow(2, potencia);
        for (int j = 1; j <= rodada; j++)
        {
            std::cin >> forca;
            compet.first = j;
            compet.second = forca;
            fila.push(compet);
        }
        rodada = rodada / 2;
        for (int j = 0; rodada > 0; j++, rodada = rodada / 2)
        {
            for (int l = 0; l < rodada; l++)
            {
                compet = fila.front();
                fila.pop();
                compet2 = fila.front();
                fila.pop();
                if(compet.second >= compet2.second)
                {
                    aux.first = compet.first;
                    perdedor = compet2.first;
                    if(compet.second - compet2.second + k < compet.second) 
                        aux.second = compet.second - compet2.second;
                }
                else
                {
                    aux.first = compet2.first;
                    perdedor = compet.first;
                    if(compet2.second - compet.second + k < compet2.second) 
                        aux.second = compet2.second - compet.second;
                }
                compet.first = aux.first;
                compet.second = perdedor;
                historico.push_back(compet);
                fila.push(aux);
            }
        }
        compet = fila.front();
        std::cout << compet.first << std::endl;
        for(auto x : historico)
            if(x.first == compet.first)
                std::cout << x.second << " ";
        std::cout << std::endl;
    }
    return 0;
}
