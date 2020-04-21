#include <iostream>

int main()
{
    int n, divisores;
    divisores = 1;
    std::cin >> n;
    for(int i = 2; i < n; i++)
    {
        if(n % i == 0)
        {
            divisores++;
            break;
        }
    }
    
    if(divisores == 1 && n != 0 && n != 1)
        std::cout << "sim";
    else
        std::cout << "nao";

    return 0;
}