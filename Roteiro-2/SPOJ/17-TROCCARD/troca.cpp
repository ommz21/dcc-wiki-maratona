#include <iostream>
#include <set>
#include <algorithm>

int main()
{
    int A, B, elemento, quant, quant2; 
    while (std::cin >> A >> B && (A || B))
    {
        quant = 0;
        quant2 = 0;
        std::set < int > carda, cardb;
        for (int i = 0; i < A; i++)
        {
            std::cin >> elemento;
            carda.insert(elemento);
        }
        for (int i = 0; i < B; i++)
        {
            std::cin >> elemento;
            cardb.insert(elemento);
        }
        for (auto x : carda)
            if(!std::binary_search(cardb.begin(), cardb.end(), x))
                quant++;
        for (auto x : cardb)
            if(!std::binary_search(carda.begin(), carda.end(), x))
                quant2++;
        if(quant <= quant2)
            std::cout << quant << std::endl;
        else
            std::cout << quant2 << std::endl;
    }
    return 0;
}
