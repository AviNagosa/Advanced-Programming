#include "‫‪Document‬‬.h"

//constructor
Document::Document(std::vector<std::string> text)
{
    for (int i = 0; i < text.size(); i++)
        v.push_back(text[i]);
}

/**
 * Get     -  integer for line[i]
 * Insert  -  one row or more before/after line[i]
 * Commend -  'a' or 'i'
 **/
void Document::addLine(int i)
{
    std::string text;
    getline(std::cin, text);
    while (text != ".")
    {
        v.insert(v.begin() + i, text);
        i++;

        getline(std::cin, text);
    }
}

/**
 * Get     -  integer for line[i]
 * Replace -  line[i] in new text 
 * Commend -  'c'
 **/
void Document::replaceLine(int i)
{
    std::string text;
    getline(std::cin, text);
    if (text != ".")
    {
        v[i] = text;
        i++;
    }
    addLine(i);
}

/**
 * Get    - integer for line[i]
 * Remove - line[i] 
 **/
void Document::deleteLine(int i)
{
    v.erase(v.begin() + i);
}

/**
 * Get     - integer for line[i]
 * Merge   - line[i] = line[i] + line[i+1]
 * Remove  - line[i+1]
 **/
void Document::mergeLine(int i)
{
    v[i] += v[i + 1];
    deleteLine(i + 1);
}

/**
 * Get        - string and integer (word,search started line)
 * not found  - search in line+1 (till line[size]),
 *                 still not start search from line[0]
 * found      - return line index
 **/
int Document::findWord(const std::string &word, int line)
{
    for (int i = line; i < v.size(); i++)
    {
        std::size_t found = v[i].find(word);
        if (found != std::string::npos)
            return i;
    }

    for (int i = 0; i < line; i++)
    {
        std::size_t found = v[i].find(word);
        if (found != std::string::npos)
            return i;
    }

    //The word doesn't in the text
    return line;
}

/**
 * Get     - string,string,int
 * Replace - old word,new word,row
 **/
void Document::replaceWord(std::string &_old, std::string &_new, int line)
{
    std::size_t found = v[line].find(_old);
    if (found != std::string::npos)
        v[line].replace(found, _old.length(), _new);
}

void Document::removeWord(std::string &word, int line)
{
    std::size_t found = v[line].find(word);
    if (found != std::string::npos)
        v[line].erase(found, word.length());
}

/**
 * Get - string as file name
 * return new txt file 
 **/
void Document::createFile(const std::string &doc_name)
{
    std::ofstream new_doc(doc_name);

    if (!new_doc)
        std::cerr << "Cannot open the output file." << std::endl;

    for (int i = 0; i < v.size(); i++)
        new_doc << v[i] + "\n";
    new_doc.close();
}