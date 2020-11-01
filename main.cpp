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
}

int main(int argc, char **argv)
{
    Editor editor;
    switch (argc)
    {
    case 1:
        break;
    case 2:
        std::string text = argv[1];
        std::vector<std::string> v = fileReader(text);

        editor.setEditor(v);
        break;
    }
    //editor.loop();

    editor.file->printText();

    return 0;
}
