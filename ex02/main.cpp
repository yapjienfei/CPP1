#include <string>
#include <iostream>
#include <iomanip> //std::setw

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;

    std::cout << std::left; //left align
    std::cout << std::setw(35) << "Memory Address of str" << ": " << &str << std::endl;
    std::cout << std::setw(35) << "Memory Address held by stringPTR" << ": " << stringPTR << std::endl;
    std::cout << std::setw(35) << "Memory Address of stringREF" << ": " << &stringREF << std::endl;
    std::cout << std::setw(35) << "Value of str" << ": " << str << std::endl;
    std::cout << std::setw(35) << "Value pointed to by stringPTR" << ": " << *stringPTR << std::endl;
    std::cout << std::setw(35) << "Value pointed to by stringREF" << ": " << stringREF << std::endl;
    return 0;
}