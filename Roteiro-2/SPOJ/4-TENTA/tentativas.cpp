#include <iostream>
#include <vector>
#include <algorithm>

int fatorial(int n)
{
    int fatorial = 1;
    for (int i = 1; i < n+1; i++)
        fatorial *= i;
    return fatorial;
}

int main()
{
    int n, elemento;
    std::cin >> n;
    while(n)
    {
        std::vector< int > lista(n);
        for (int i = 0; i < n; i++)
        {
            std::cin >> elemento;
            lista[i] = elemento;
        }
        std::sort(lista.begin(), lista.end());
        do
        {
            for (int j = 0; j < n; j++)
            {
                std::cout << lista[j];
                if(j != n-1)
                    std::cout << " ";
            }
            std::cout << std::endl;
        } while (std::next_permutation(lista.begin(), lista.end()));
        std::cout << std::endl;
        std::cin >> n;
    }
    return 0;
}
