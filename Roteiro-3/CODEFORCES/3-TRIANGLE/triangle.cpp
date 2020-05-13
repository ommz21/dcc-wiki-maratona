#include <iostream>
#include <math.h>

bool checa(std::pair <int, int> a, std::pair <int, int> b, std::pair <int, int> c)
{
    float cos, produto, normaab, normabc, normaac;
    cos = -1.;
    normaab = sqrt(pow(b.first - a.first, 2) + pow(b.second - a.second, 2));
    normabc = sqrt(pow(c.first - b.first, 2) + pow(c.second - b.second, 2));
    normaac = sqrt(pow(c.first - a.first, 2) + pow(c.second - a.second, 2));
    produto = (((b.first - a.first) * (c.first - b.first)) + ((b.second - a.second) * (c.second - b.second)));
    cos = produto / (normaab * normabc);
    if(cos == 0)
        return true;
    produto = (((b.first - a.first) * (c.first - a.first)) + ((b.second - a.second) * (c.second - a.second)));
    cos = produto / (normaab * normaac);
    if(cos == 0)
        return true;
    produto = (((c.first - a.first) * (c.first - b.first)) + ((c.second - a.second) * (c.second - b.second)));
    cos = produto / (normaac * normabc);
    if(cos == 0)
        return true;
    return false;
}

int main()
{
    int x, y;
    bool retangulo, quase;
    std::pair < int, int > a, b, c;
    std::cin >> x >> y;
    a = std::make_pair(x, y);
    std::cin >> x >> y;
    b = std::make_pair(x, y);
    std::cin >> x >> y;
    c = std::make_pair(x, y);
    retangulo = false;
    quase = false;
    while (true)
    {
        retangulo = checa(a, b, c);
        if(retangulo)
            break;
        quase = checa(a, b, std::make_pair(c.first, c.second + 1));
        if(quase)
            break;
        quase = checa(a, b, std::make_pair(c.first, c.second - 1));
        if(quase)
            break;
        quase = checa(a, b, std::make_pair(c.first + 1, c.second));
        if(quase)
            break;
        quase = checa(a, b, std::make_pair(c.first - 1, c.second));
        if(quase)
            break;
        quase = checa(a, std::make_pair(b.first, b.second + 1), c);
        if(quase)
            break;
        quase = checa(a, std::make_pair(b.first, b.second - 1), c);
        if(quase)
            break;
        quase = checa(a, std::make_pair(b.first + 1, b.second), c);
        if(quase)
            break;
        quase = checa(a, std::make_pair(b.first - 1, b.second), c);
        if(quase)
            break;
        quase = checa(std::make_pair(a.first, a.second + 1), b, c);
        if(quase)
            break;
        quase = checa(std::make_pair(a.first, a.second - 1), b, c);
        if(quase)
            break;
        quase = checa(std::make_pair(a.first + 1, a.second), b, c);
        if(quase)
            break;
        quase = checa(std::make_pair(a.first - 1, a.second), b, c);
        if(quase)
            break;
        break;    
    }
    if(retangulo)
        std::cout << "RIGHT";
    else if(quase)
        std::cout << "ALMOST";
    else
        std::cout << "NEITHER";
    std::cout << std::endl;
    return 0;
}
