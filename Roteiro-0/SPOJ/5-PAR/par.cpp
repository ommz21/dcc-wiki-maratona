#include <iostream>
#include <string>
#include <vector>

int main()
{
    int n, a, b, resultado, teste, soma;
    std::vector<int> placar;
    std::string par;
    std::string impar; 
    teste = 0;
    if(!std::cin >> n)
        exit(EXIT_FAILURE);
    while(n)
    {
        placar.clear();
        std::cin >> par;
        std::cin >> impar;
        teste++;
        for(int i = 0; i < n; i++)
        {
            std::cin >> a;
            std::cin >> b;
            placar.push_back(a + b);
        }
        std::cout << "Teste " << teste << std::endl;
        for(int x : placar)
        {
            if(x % 2)
                std::cout << impar << std::endl;
            else
                std::cout << par << std::endl;
        }
        std::cout << std::endl;
        std::cin >> n;
    }
    return 0;
}