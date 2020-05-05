#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n, a, b, c, d;
    int cont = 0;
    std::cin >> n;
    std::vector < int > A(n), B(n), C(n), D(n), soma1(n*n), soma2(n*n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a >> b >> c >> d;
        A[i] = a;
        B[i] = b;
        C[i] = c;
        D[i] = d;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            soma1[i*n + j] = A[i] + B[j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            soma2[i*n + j] = C[i] + D[j];
    std::sort(soma1.begin(), soma1.end());
    std::sort(soma2.begin(), soma2.end());
    for(auto x : soma1)
    {
        auto lower = std::lower_bound(soma2.begin(), soma2.end(), -x);
        auto upper = std::upper_bound(soma2.begin(), soma2.end(), -x);
        cont += (upper - lower);
    }
    std::cout << cont << std::endl;
    return 0;
}
