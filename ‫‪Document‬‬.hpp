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
    void addLine(int);
    void replaceLine(int);
    void deleteLine(int);
    void mergeRows(int);
    int findWord(std::string, int);
    void replaceWord(std::string, std::string, int);

    void createFile();
};
