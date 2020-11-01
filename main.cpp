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
    Editor editor;
    switch (argc)
    {
    case 1:
        break;
    case 2:
        std::vector<std::string> v = fileReader(argv[1]);
        editor.setEditor(v);
        break;
    }
    //editor.loop();
    editor.file->printText();

    return 0;
}
