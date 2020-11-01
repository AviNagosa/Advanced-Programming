#include "‫‪Document‬‬.hpp"

Document::Document(std::vector<std::string> text)
{
    for (int i = 0; i < text.size(); i++)
        this->v.push_back(text[i]);
}

void Document::printText()
{
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << std::endl;
    }
}