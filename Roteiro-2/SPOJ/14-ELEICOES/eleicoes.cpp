#include <iostream>
#include <map>
#include <string>
#include <algorithm>

int main()
{
    int n;
    std::map < std::string, int > votacoes;
    std::pair < std::string, int > vencedor;
    vencedor.first = "";
    vencedor.second = 0;
    std::string voto;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> voto;
        votacoes[voto]++;
    }
    for(auto x : votacoes)
        if(x.second >= vencedor.second)
            vencedor = x;
    std::cout << vencedor.first << std::endl;
    return 0;
}
