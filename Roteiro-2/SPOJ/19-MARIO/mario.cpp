#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

bool comp (std::pair< int, int > a, std::pair< int, int > b)
{
    return a.second < b.second;
}

int trocar (std::vector < std::pair< int, int > > &armarios, int elemento, int contiguos, int ind)
{
    int trocas, procurado, dif;
    trocas = 0;
    auto indi = armarios.begin() + ind;
    auto indf = armarios.begin() + ind;
    procurado = elemento + contiguos - 1;
    indf = std::upper_bound(indi, armarios.end(), std::make_pair(0, procurado), comp);
    if((indf-1)->second == procurado || indf == armarios.end())
        indf--;
    dif = indf - indi;
    if(indf->second == procurado)
        trocas = contiguos - 1 - dif;
    else
    {
        trocas = contiguos - 1 - dif;
        if(indf->second > procurado) 
            trocas += (indf->second - procurado);
        //else    
            //trocas += (procurado - indf->second);
    }
    return trocas;
}

int main()
{
    int elemento, contiguos, livres, trocas, menor;
    while (std::cin >> contiguos >> livres && contiguos != 0 && livres != 0)
    {
        std::vector < std::pair< int, int > > armarios(livres + 1);
        armarios[0].first = 0;
        armarios[0].second = 0;
        for (int i = 1; i <= livres; i++)
        {
            std::cin >> elemento;
            armarios[i].second = elemento; 
        }
        menor = 100000;
        for (int i = 1; i <= livres; i++)
        {
            trocas = trocar(armarios, armarios[i].second, contiguos, i);
            std::cout << i << ": " << armarios[i].second << ", " << trocas << std::endl;
            armarios[i].first = trocas;
            if (trocas <= menor)
                menor = trocas;
        }
        std::cout << menor << std::endl;
    }
    return 0;
}