#include <iostream>
#include <string>
#include <iomanip>
#include <map>

int main()
{
    int testes, total;
    float porcem;
    std::string especie;
    std::cin >> testes;
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    for (int i = 1; i <= testes; i++)
    {
        total = 0;
        std::map < std::string, int > cat;
        while(std::getline(std::cin, especie) && !especie.empty())
        {
            cat[especie] += 1;
            total++;
        }
        for(auto x : cat)
        {
            porcem = 100 * (float)x.second / (float)total;
            std::cout << std::fixed << std::showpoint;
            std::cout << std::setprecision(4);
            std::cout << x.first << " " << porcem << std::endl;
        }
        if(i != testes)
            std::cout << std::endl;
    }
    return 0;
}