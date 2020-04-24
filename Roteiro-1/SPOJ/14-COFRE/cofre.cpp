#include <iostream>

int main()
{
    int n, teste, j, z, delta;
    teste = 1;
    std::cin >> n;
    while (n)
    {
        delta = 0;
        int *resultado = new int [n];
        for(int i = 0; i < n; i++)
        {
            std::cin >> j >> z;
            delta += (j - z);
            resultado[i] = delta;
        }
        std::cout << std::endl << "Teste " << teste << std::endl;    
        for(int i = 0; i < n; i++)
            std::cout << resultado[i] << std::endl;
        std::cout << std::endl;
        delete [] resultado;
        teste++;
        std::cin >> n;
    }
    return 0;
}
