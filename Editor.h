#pragma once
#include "‫‪Document‬‬.h"
#include <string.h>
#include <stdio.h>

class Editor
{
public:
    Document doc;
    int row;

    Editor() { row = 0; }
    Editor(Document &);

    void loop();
    bool is_number(const std::string &);
    int to_integer(const std::string &);
    bool is_valid(int);
    std::vector<std::string> split(std::string, std::string);
};
