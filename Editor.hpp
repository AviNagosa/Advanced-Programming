#pragma once
#include "‫‪Document‬‬.hpp"

class Editor
{

public:
    Document *file;

    Editor() {}
    void setEditor(std::vector<std::string>);
    void loop();
};
