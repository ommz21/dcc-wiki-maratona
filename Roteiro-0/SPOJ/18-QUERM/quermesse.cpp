#include <iostream>
#include <string>

int main()
{
    int pessoa, quant, instancia, flag;
    instancia = 1;


    while(std::cin >> quant)
    {
        flag = 0;
        if(quant == 0)
            return 0;
        if(std::cin.eof())
    		return 0;
        for(int i = 0; i < quant; i++)
        {
            std::cin >> pessoa;
            if(pessoa == i + 1)
                flag = pessoa;
        }
        std::cout << "Teste " << instancia << std::endl;
        std::cout << flag << std::endl << std::endl;
        instancia++;
    }
	return 0;
}