#include <iostream>
#include <sstream>
#include <string>

int main()
{
    std::string palavra;
    int n, quant, soma, instancia;
    bool sair = false;
    instancia = 1;

    while(std::cin >> quant)
    {
        if(quant == 0)
        {
        	std::cin.clear();
        	std::cin.ignore(1000, '\n');
        	return 0;
        }
            
        soma = 0;
        for(int i = 0; i < quant; i++)
        {
            std::cin >> n;
            if(n == soma)
                break;
            soma += n;
        }
        std::cout << "Instancia " << instancia << std::endl;
        if(n == soma)
        {
        	std::cout << n;
        	std::cin.clear();
        	std::cin.ignore(1000, '\n');
        }
        else
            std::cout << "nao achei";
        std::cout << std::endl << std::endl;
        instancia++;
    }
	return 0;
}