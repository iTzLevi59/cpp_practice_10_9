#include <iostream>
#include <cmath>

int main()
{
    double a, b, c;
    std::cout << "a, b, c: ";
    std::cin >> a >> b >> c;

    if (a == 0) 
    {
        std::cout << "Not a quadratic equation!" << std::endl;
        return 0;
    }

    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) 
    {
        double sqrtD = std::sqrt(discriminant);
        double x1 = (-b + sqrtD) / (2 * a);
        double x2 = (-b - sqrtD) / (2 * a);

        std::cout << "Roots: " << x1 << ", " << x2 << std::endl;
    }

    else if (discriminant == 0)
    {
        double x = -b / (2 * a);
        std::cout << "Root: " << x << std::endl;
    }

    else
    {
        std::cout << "No real roots!" << std::endl;
    }

    return 0;
}