#include <iostream>

int main()
{
    int q, d, p, dias, paginas;
    while(true)
    {
        std::cin >> q;
        if(q == 0)
            break;
        std::cin >> d;
        std::cin >> p;
        paginas = p * d * q / (p - q);
        if(paginas != 1)
            std::cout << paginas << " paginas";
        else
            std::cout << "1 pagina";
        std::cout << std::endl;
    }
	return 0;
}