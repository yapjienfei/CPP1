#include "Harl.hpp"
#include <iostream>

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cerr << "Usage: " << av[0] << " <level>" << std::endl;
        return 1;
    }

    Harl harl;
    harl.complainFilter(av[1]);

    return 0;
}