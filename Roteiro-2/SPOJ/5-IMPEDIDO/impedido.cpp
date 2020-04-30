#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int A, D;
    char impedido;
    std::cin >> A >> D;
    while(A != 0 || D != 0)
    {
        impedido = 'N';
        std::vector< int > atacantes(A);
        std::vector< int > defensores(D);
        for (int i = 0; i < A; i++)
            std::cin >> atacantes[i];
        for (int i = 0; i < D; i++)
            std::cin >> defensores[i];
        sort(atacantes.begin(), atacantes.end());
        sort(defensores.begin(), defensores.end());
        if(atacantes[0] < defensores[1])
            impedido = 'Y';
        std::cout << impedido << std::endl;
        std::cin >> A >> D;
    }
    return 0;
}
