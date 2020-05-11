#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n, ponto, triangulos, inicial, soma, cada, atual, contpart;
    while (true)
    {
        try
        {
            std::cin >> n;
            if(n < 1 || std::cin.fail() || std::cin.eof())
                throw std::exception();
        }
        catch(const std::exception& e)
        {
            std::cin.clear();
        	std::cin.ignore(1000, '\n');
        	return 0;
        }
        bool maisum = false;
        bool conf = false;
        std::vector < int > pontos(n);
        std::vector < int > pref(n+1);
        pref[0] = 0;
        soma = 0;
        for (int i = 0; i < n; i++)
        {
            std::cin >> pontos[i];
            soma += pontos[i];
            pref[i+1] = pref[i] + pontos[i];
        }
        cada = soma / 3;
        triangulos = 0;
        for (int i = 1; i < n+1; i++)
        {
            maisum = std::binary_search(pref.begin(), pref.end(), pref[i] + cada);
            conf = std::binary_search(pref.begin(), pref.end(), pref[i] + 2 * cada);
            if (maisum && conf)
                triangulos++;        
        }
        std::cout << triangulos << std::endl;
    }
    return 0;
}