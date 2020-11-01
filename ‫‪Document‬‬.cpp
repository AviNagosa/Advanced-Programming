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

void Document::goToLine(std::string s) {}
void Document::goForward(std::string s) {}
void Document::getBack(std::string s) {}
void Document::lastRow(std::string s) {}
void Document::newRow(std::string s) {}
void Document::newChar(std::string s) {}
void Document::switchRow(std::string s) {}
void Document::replaceWord(std::string s) {}
void Document::replaceFirstWord(std::string s) {}
void Document::mergeRows(std::string s) {}
void Document::createFile(std::string s) {}
void Document::getOut(std::string s) {}