#include <iostream>

int main()
{
    int n;
    while(true)
    {
        std::cin >> n;
        if (std::cin.eof())
            break;
        int **mat = new int *[n];
        for(int i = 0; i < n; i++)
            mat[i] = new int [n];
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i + j == n - 1)
                    mat[i][j] = 2;
                else if (i == j)
                    mat[i][j] = 1;
                else
                    mat[i][j] = 3;
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                std::cout << mat[i][j];
            std::cout << std::endl;
        }
        for(int i = 0; i < n; i++)
            delete [] mat[i];
        delete [] mat;
    }
	return 0;
}