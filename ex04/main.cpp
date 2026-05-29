#include <iostream>
#include <fstream>
#include <string>

void replace(std::string filename, std::string s1, std::string s2)
{
    if (s1.empty())
    {
        std::cerr << "Error: s1 cannot be empty." << std::endl;
        return;
    }
    //open file
    std::ifstream infile(filename.c_str());
    if (!infile.is_open())
    {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }
    //create output file
    std::ofstream outfile((filename + ".replace").c_str());
    if (!outfile.is_open())
    {
        std::cerr << "Error: Could not create output file." << std::endl;
        return;
    }
    std::string line;
    //std::getline reads one line from infile without newline
    while (std::getline(infile, line))
    {
        std::string newLine;
        size_t pos = 0;
        size_t found;
        //search for s1 starting from pos
        //found is the index where s1 starts, or npos if not found
        while ((found = line.find(s1, pos)) != std::string::npos)
        {
            newLine.append(line, pos, found - pos);
            newLine.append(s2);
            pos = found + s1.length();
        }
        //after loop, add remaining part
        newLine.append(line, pos, std::string::npos);
        outfile << newLine;
        if (!infile.eof())
            outfile << std::endl;
    }
    infile.close();
    outfile.close();
}

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << "Usage: " << av[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    replace(av[1], av[2], av[3]);
    return 0;
}
