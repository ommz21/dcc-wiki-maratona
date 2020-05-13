#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n, vencedor, atual;
    while (std::cin >> n && n != 0)
    {
        std::vector < int > votos(n);
        for (int i = 0; i < n; i++)
            votos[i] = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                std::cin >> atual;
                votos[j] += atual;
            }
        }
        std::sort(votos.begin(), votos.end());
        std::cout << votos[n-1] << std::endl;
    }
    return 0;
}