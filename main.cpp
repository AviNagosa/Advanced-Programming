#include "Editor.hpp"
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <iostream>

/**
 * get file path as a string
 * return a string vector - every row is line from the text
 **/
std::vector<std::string> fileReader(std::string filePath)
{
    std::vector<std::string> v;
    std::ifstream file(filePath);
    std::string line;

    while (std::getline(file, line))
    {
        v.push_back(line);
    }

    return v;
}

int main(int argc, char **argv)
{
    //Editor editor;
    if (argc == 1)
    {
        Editor editor;
        editor.loop();
    }
    else if (argc == 2)
    {
        Document d(fileReader(argv[1]));
        Editor editor(d);
        editor.loop();
    }
    else
        std::cout << "Invalid input" << std::endl;
    return 0;
}
