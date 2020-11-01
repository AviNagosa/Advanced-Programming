#pragma once
#include <iostream>
#include <vector>

class Document
{
public:
    std::vector<std::string> v;

    Document() {}
    Document(std::vector<std::string>);
    void printText();
};
