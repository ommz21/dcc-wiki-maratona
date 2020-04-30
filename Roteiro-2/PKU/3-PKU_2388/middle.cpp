#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;
    std::vector< int > vacas, resposta;
    int leite, mediana;
    for (int i = 0; i < n; i++)
    {
        std::cin >> leite;
        vacas.push_back(leite);
    }
    std::sort(vacas.begin(), vacas.end());
    std::cout << vacas[vacas.size()/2] << std::endl;
    
    return 0;
}
