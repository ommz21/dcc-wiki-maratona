#include <iostream>
#include <iomanip>
#include <math.h>

int main()
{
    float x1, x2, y1, y2, d;
    std::cin >> x1 >> y1;
    std::cin >> x2 >> y2;
    d = sqrt(pow((x2 -x1), 2) + pow((y2 -y1), 2));
    std::cout << std::fixed << std::showpoint;
    std::cout << std::setprecision(4);
    std::cout << d << std::endl;
    return 0;
}
