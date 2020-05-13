#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n, soma, media, troca;
    while (std::cin >> n && n != -1)
    {
        std::vector < int > pacotes(n);
        soma = 0;
        for (int i = 0; i < n; i++)
        {
            std::cin >> pacotes[i];
            soma += pacotes[i];
        }
        if(soma % n == 0)
        {
            media = soma / n;
            troca = 0;
            std::sort(pacotes.begin(), pacotes.end());
            for (int i = 0; i < n; i++)
            {
                if (pacotes[i] < media)
                    troca += (media - pacotes[i]);
                else
                    break;
            }
            std::cout << troca;
        }
        else
            std::cout << -1;
        std::cout << std::endl;
    }
    return 0;
}