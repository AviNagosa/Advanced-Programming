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

    void goToLine(std::string);
    void goForward(std::string);
    void getBack(std::string);
    void lastRow(std::string);
    void newRow(std::string);
    void newChar(std::string);
    void switchRow(std::string);
    void replaceWord(std::string);
    void replaceFirstWord(std::string);
    void mergeRows(std::string);
    void createFile(std::string);
    void getOut(std::string);
};
