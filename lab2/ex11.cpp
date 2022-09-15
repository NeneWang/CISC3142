#include <iostream>

int main()
{
    int v1, v2;
    std::cout << "Enter two numbers:" << std::endl;
    std::cin >> v1 >> v2;
    for (int idx = v1 + 1; idx < v2; idx++)
    {
        std::cout << idx << std::endl;
    }
}