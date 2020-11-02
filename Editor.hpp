#pragma once
#include "‫‪Document‬‬.hpp"

class Editor
{

public:
    Document *file;
    int row;

    Editor() {}
    void setEditor(std::vector<std::string>);
    void loop();
};
