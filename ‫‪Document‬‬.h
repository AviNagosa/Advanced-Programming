#pragma once
#include <iostream>
#include <fstream>
#include <vector>

class Document
{
public:
    std::vector<std::string> v;

    Document() {}
    Document(std::vector<std::string>);

    void addLine(int);
    void replaceLine(int);
    void deleteLine(int);
    void mergeLine(int);
    void removeWord(std::string &, int);
    int findWord(const std::string &, int);
    void replaceWord(std::string &, std::string &, int);
    void createFile(const std::string &);
};
