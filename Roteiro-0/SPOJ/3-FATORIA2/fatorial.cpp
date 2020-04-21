#include <iostream>

int main()
{
    int n, fatorial = 1;
    std::cin >> n;
    while(n > 1)
    {
        fatorial *= n;
        n--;
    } 
    std::cout << std::endl << fatorial << std::endl;
}