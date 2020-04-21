#include <iostream>

void hanoi(int n, int orig, int dest, int temp, int &cont)
{
    if(n == 1)
        cont++;
    else
    {
        hanoi(n - 1, orig, temp, dest, cont);
        cont++;
        hanoi(n - 1, temp, dest, orig, cont);
    }
    return;
}

int main()
{
    int cont, quant, instancia;
    instancia = 1;
    while(std::cin >> quant)
    {
        cont = 0;
        if(quant == 0)
            return 0;
        if(std::cin.eof())
    		return 0;
        hanoi(quant, 1, 2, 3, cont);
        std::cout << "Teste " << instancia << std::endl;
        std::cout << cont << std::endl << std::endl;
        instancia++;
    }
	return 0;
}