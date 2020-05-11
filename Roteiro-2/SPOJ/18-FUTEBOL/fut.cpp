#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

bool sortranking(std::pair < int, std::pair< int, std::pair < int, std::pair < std::string, std::string  > > > > a, std::pair < int, std::pair< int, std::pair < int, std::pair < std::string, std::string  > > > > b)
{
    if (a.first != b.first)
        return a.first > b.first;
    
    if (a.second.first != b.second.first)
        return a.second.first > b.second.first;
    
    if (a.second.second.first != b.second.second.first)
        return a.second.second.first > b.second.second.first;
    if (a.second.second.second.first != b.second.second.second.first)
        return a.second.second.second.first < b.second.second.second.first;
    
    return a.second.second.second.second > b.second.second.second.second;
}

int main()
{
    int t, j, k, golmand, golvis, classi, auxf;
    float fporc;
    while (std::cin >> t >> j && t != 0 && j != 0)
    {
        std::string time, jogos, linha, palavras, mand, vis;
        std::istringstream stream;
        std::vector < std::pair < int, std::pair< int, std::pair < int, std::pair < std::string, std::string > > > > > ranking(t);
        std::pair < int, std::pair< int, std::pair < int, std::pair < std::string, std::string > > > > indtime;
        std::pair < int, std::pair < int, int > > anterior;
        std::map < std::string, std::pair < std::string, std::pair < int, std::pair < int, std::pair < int, int > > > > > mapa;
        std::pair < std::string, std::pair < std::string, std::pair < int, std::pair < int, std::pair < int, int > > > > > inftimes;
        inftimes.second.second.first = 0;
        inftimes.second.second.second.first = 0;
        inftimes.second.second.second.second.first = 0;
        inftimes.second.second.second.second.second = 0;
        for (int i = 0; i < t; i++)
        {
            std::cin >> time;
            inftimes.first = time;
            inftimes.second.first = time;
            for (int l = 0; l < time.size(); l++)
                inftimes.second.first[l] = tolower(time[l]);
            mapa.insert(inftimes);
        }
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        for (int i = 0; i < j; i++)
        {
            std::getline(std::cin, linha);
            stream = std::istringstream(linha);
            k = 0;
            while (std::getline(stream, palavras, ' '))
            {
                switch (k)
                {
                    case 0:
                        mand = palavras;
                        break;
                    case 1:
                        golmand = std::stoi(palavras);
                        break;
                    case 3:
                        golvis = std::stoi(palavras);
                        break;
                    case 4:
                        vis = palavras;
                        break;
                    default:
                        break;
                }
                k++;
            }
            if (golmand > golvis)
                mapa[mand].second.first += 3;
            else if (golmand < golvis)
                mapa[vis].second.first += 3;
            else
            {
                mapa[mand].second.first += 1;
                mapa[vis].second.first += 1;
            }
            mapa[mand].second.second.first += 1;
            mapa[vis].second.second.first += 1;
            mapa[mand].second.second.second.first += golmand;
            mapa[mand].second.second.second.second += golvis;
            mapa[vis].second.second.second.first += golvis;
            mapa[vis].second.second.second.second += golmand;
        }
        k = 0;
        for(auto x : mapa)
        {
            indtime.first = x.second.second.first;
            indtime.second.first = x.second.second.second.second.first - x.second.second.second.second.second; 
            indtime.second.second.first = x.second.second.second.second.first;
            indtime.second.second.second.first = x.second.first;
            indtime.second.second.second.second = x.first;
            ranking[k] = indtime;
            k++; 
        }
        std::sort(ranking.begin(), ranking.end(), sortranking);
        classi = 1;
        anterior.first = -1;
        anterior.second.first = -1;
        anterior.second.second = -1;
        fporc = 0.0;
        std::string sporc;
        for(auto x : ranking)
        {
            std::string indice = x.second.second.second.second;
            if(mapa[indice].second.second.first)
                fporc = ((float)(x.first) / (float)(3 * mapa[indice].second.second.first)) * 100.F;
            else
                sporc = "N/A";
            if(anterior.first != -1 || anterior.second.first != -1 || anterior.second.second != -1)
            {
                if (anterior.first != x.first || anterior.second.first != x.second.first || anterior.second.second != x.second.second.first)
                    std::cout << std::setw(2) << std::right << classi << ". ";
                else
                    std::cout << "    ";
            }
            else
                std::cout << std::setw(2) << std::right << classi << ". ";
            std::cout << std::setw(15) << std::right << indice << ' ';
            std::cout << std::setw(3) << std::right << x.first << ' '; 
            std::cout << std::setw(3) << std::right << mapa[indice].second.second.first << ' ';
            std::cout << std::setw(3) << std::right << x.second.second.first << ' '; 
            std::cout << std::setw(3) << std::right << mapa[indice].second.second.second.second << ' '; 
            std::cout << std::setw(3) << std::right << x.second.first; 
            if(mapa[indice].second.second.first)
                std::cout << std::setw(7) << std::right << std::fixed  << std::setprecision(2) << fporc;
            else    
                std::cout << std::setw(7) << std::right << sporc;
            std::cout << " " << std::endl;
            anterior.first = x.first;
            anterior.second.first = x.second.first;
            anterior.second.second = x.second.second.first;
            classi++;
        }
        std::cout << std::endl;
    }
    return 0;
}