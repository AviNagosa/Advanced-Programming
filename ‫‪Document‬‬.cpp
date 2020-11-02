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

/**
 * void method
 * Get an Integer who represent the row
 * insert one row or more before/after the curr row
 **/
void Document::addLine(int i)
{
    std::string text;
    std::cin >> text;
    while (text != ".")
    {
        this->v.insert(v.begin() + i, text);
        i++;

        std::cin >> text;
    }
}

void Document::replaceLine(int i)
{
    std::string text;
    std::cin >> text;
    if (text != ".")
    {
        this->v[i] = text;
        i++;
    }
    addLine(i);
}

void Document::deleteLine(int i)
{
    this->v.erase(this->v.begin() + i);
}

void Document::mergeRows(int i)
{
    this->v[i] += this->v[i + 1];
    deleteLine(i + 1);
}

int Document::findWord(std::string word, int line)
{
    for (int i = line; i < v.size(); i++)
    {
        std::size_t found = this->v[i].find(word);
        if (found != std::string::npos)
            return i;
    }

    for (int i = 0; i < line; i++)
    {
        std::size_t found = this->v[i].find(word);
        if (found != std::string::npos)
            return i;
    }

    //The word doesn't in the text
    return line;
}

void Document::replaceWord(std::string _old, std::string _new, int line)
{
    std::size_t found = this->v[line].find(_old);
    if (found != std::string::npos)
        this->v[line].replace(found, _old.length() - 1, _new);
}

void Document::createFile()
{
    this->printText();
}