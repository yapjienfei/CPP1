#include "Harl.hpp"
#include <iostream>

void Harl::debug(void)
{
    std::cout << "[DEBUG] I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "[INFO] I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[WARNING] I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error(void)
{
    std::cout << "[ERROR] This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*functions[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i])
        {
            (this->*functions[i])();
            return;
        }
    }
    std::cout << "[UNKNOWN] Did not match any log levels." << std::endl;
}

void Harl::complainFilter(std::string level)
{
    static const char* levelNames[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    const int numLevels = sizeof(levelNames) / sizeof(levelNames[0]);

    int idx = -1;
    for (int i = 0; i < numLevels; i++)
    {
        if (level == levelNames[i])
        {
            idx = i;
            break;
        }
    }
    //fall through needed to silence compiler warning
    switch (idx)
    {
        case 0:
            complain("DEBUG");
            /* fall through */
        case 1:
            complain("INFO");
            /* fall through */
        case 2:
            complain("WARNING");
            /* fall through */
        case 3:
            complain("ERROR");
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}