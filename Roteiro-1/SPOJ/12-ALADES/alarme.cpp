#include <iostream>

int main() 
{
    int h1, h2, m1, m2;
    int saida = 0;
    std::cin >> h1 >> m1 >> h2 >> m2;
    while(h1 != 0 || m1 != 0 || h2 != 0 || m2 !=0)
    {
        if(h2 < h1 ||(h1 == h2 && m2 < m1))
            saida = 60 * (24 - h1) + 60 * h2 + (m2 - m1);
        else
            saida = 60 * (h2 - h1) + (m2 - m1);
        std::cout << saida << std::endl;
        std::cin >> h1 >> m1 >> h2 >> m2;
    }
    return 0;
}