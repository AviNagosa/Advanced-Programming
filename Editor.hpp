#pragma once
#include "‫‪Document‬‬.hpp"

class Editor
{
public:
    Document file;
    int row;

    Editor() {}
    Editor(Document &);
    //Editor(Document&);
    //void setEditor(std::vector<std::string>);
    void loop();

    bool is_number(const std::string &);
    int to_integer(const std::string &);
    bool is_valid(const std::string &);
    bool is_valid(int);
};
