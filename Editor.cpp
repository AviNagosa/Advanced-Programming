#include "Editor.hpp"

void Editor::setEditor(std::vector<std::string> v)
{
    this->file = new Document(v);
}

void Editor::loop()
{
    std::string commend;
    std::cin >> commend;

    while (commend != "q")
    {
        if (commend == "3")
        {
        }
        else if (commend == "+2")
        {
        }
        else if (commend == "-1")
        {
        }
        else if (commend == "$")
        {
        }
        else if (commend == ".")
        {
        }
        else if (commend == "i")
        {
        }
        else if (commend == "j")
        {
        }
        else if (commend == "/text/")
        {
        }
        else if (commend == "s/old/new/")
        {
        }
        else if (commend == "w file")
        {
        }
        std::cin >> commend;
    }
}