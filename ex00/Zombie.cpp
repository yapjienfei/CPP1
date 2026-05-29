#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name) : name(name)
{
    std::cout << "Zombie " << name << " is created." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << name << " is destroyed." << std::endl;
}

void Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
