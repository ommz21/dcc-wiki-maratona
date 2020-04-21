#include <iostream>

int main()
{
    int foi, volta, cont;
    while(true)
    {
        std::cin >> foi;
        std::cin >> volta;
        if(std::cin.eof())
            break;
        if(foi != volta)
        {
            int *reg = new int[foi];
            for(int i = 0; i < foi; i++)
                reg[i] = 0;
            for(int i = 0; i < volta; i++)
            {
                std::cin >> cont;
                reg[cont-1] = 1;
            }
            for(int i = 0; i < foi; i++)
                if(reg[i] == 0)
                    std::cout << i + 1 << " ";
        }
        else
        {
            for(int i = 0; i < volta; i++)
                std::cin >> cont;
            std::cout << "*";    
        }
        std::cout << std::endl;
    }
	return 0;
}
