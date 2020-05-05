#include <iostream>
#include <set>
#include <string>
#include <algorithm>

int main()
{
    int n;
    std::string seq;
    
    std::cin >> n;
    while (n)
    {
        std::set < std::string > colecao;
        for (int i = 0; i < n; i++)
        {
            std::cin >> seq;
            std::sort(seq.begin(), seq.end());
            colecao.insert(seq);
        }
        std::cout << colecao.size() << std::endl;
        std::cin >> n;
    }
    return 0;
}
