#include <iostream>

int main()
{
    int n, x, soma = 0;
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::cin >> x;
        soma += x;
    } 
    std::cout << soma << std::endl;
}