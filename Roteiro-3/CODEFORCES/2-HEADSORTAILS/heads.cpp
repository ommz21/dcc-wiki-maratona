#include <iostream>
#include <vector>

int main()
{
    int x, y, inx, iny, foi;
    foi = 0;
    scanf("%d %d %d %d", &x,  &y, &inx, &iny);
    std::vector< std::pair < int, int > > saida;
    for (int i = inx; i <= x; i++)
    {
        for (int j = iny; j <= y && j < i; j++)
            saida.push_back(std::make_pair(i, j));
    }
    printf("%d\n", saida.size());
    for(auto x : saida)
        printf("%d %d\n", x.first, x.second);
    return 0;
}