#include "Editor.h"
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <iostream>

/**
 * Get    - string as file path
 * Return - vector<string>  every row is line from the text
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
    Editor *editor;
    switch (argc)
    {
    case 1:
        editor = new Editor();
        break;
    case 2:
        Document d(fileReader(argv[1]));
        editor = new Editor(d);
        break;
    }
    editor->loop();

    delete editor;

    return 0;
}