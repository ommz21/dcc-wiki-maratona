#include <iostream>
#include <iomanip>

int main()
{
    int n, linha, inicial, aux, acum;
    std::cin >> n;
    
    while(n != 0)
    {
        int **mat = new int *[n];
        for(int i = 0; i < n; i++)
            mat[i] = new int [n];
        inicial = 2;
        for(int i = 0; i < n; i++)
        {
            aux = inicial;
            acum = 1;
            for(int j = 0; j < n; j++)
            {
                if(i == j)
                    mat[i][j] = 1;
                else if(i < j)
                {
                    mat[i][j] = acum + 1;
                    acum++;
                }
                else
                {
                    mat[i][j] = aux - 1;
                    aux--;
                }
            }
            inicial++;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {

                if(j != n - 1)
                    std::cout << std::setw(3) << std::right << mat[i][j] << " ";
                else
                    std::cout << std::setw(3) << std::right << mat[i][j] << std::endl;
            }
        }
        std::cout << std::endl;

        for(int i = 0; i < n; i++)
            delete [] mat[i];
        delete [] mat;

        std::cin >> n;
    }
    return 0;
}