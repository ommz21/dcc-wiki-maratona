#include <iostream>
#include <cmath>

int main()
{
    int cont, quant, instancia;
    instancia = 1;
    while(std::cin >> quant)
    {
        if(quant == 0)
            return 0;
        if(std::cin.eof())
    		return 0;
        cont = pow(2, quant) - 1; 
        std::cout << "Teste " << instancia << std::endl;
        std::cout << cont << std::endl << std::endl;
        instancia++;
    }
	return 0;
}