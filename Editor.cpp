#include "Editor.h"
#include <sstream>

Editor::Editor(Document &d) : doc(d) { row = 0; }

//convert from string to interger
int Editor::to_integer(const std::string &s)
{
    int n;
    std::stringstream helper(s);
    helper >> n;
    return n;
}

std::vector<std::string> Editor::split(std::string str, std::string sep)
{
    char *cstr = const_cast<char *>(str.c_str());
    char *current;
    std::vector<std::string> arr;
    current = strtok(cstr, sep.c_str());
    while (current != NULL)
    {
        arr.push_back(current);
        current = strtok(NULL, sep.c_str());
    }
    return arr;
}

//check if the string is a number
bool Editor::is_number(const std::string &s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it))
        ++it;
    return !s.empty() && it == s.end();
}

//check the validity of the commend
bool Editor::is_valid(int req)
{
    if (req > doc.v.size() - 1 || req < 0 || doc.v.size() == 0)
        return false;
    return true;
}

//Interface for user commends
void Editor::loop()
{
    std::string commend;
    getline(std::cin, commend);
    int req;
    //commend for exit from the editor - 'q'
    while (commend != "q")
    {
        //check if is a number
        if (is_number(commend))
        {
            //convert to integer
            req = to_integer(commend) - 1;
            //check if the index valid
            if (!is_valid(req))
                std::cout << "?" << std::endl;
            else
            {
                row = req;
                std::cout << doc.v[row] << std::endl;
            }
        }
        else if (commend == "a")
        {
            if (doc.v.size() == 0)
                doc.addLine(row);
            else
                doc.addLine(row + 1);
        }
        else if (commend == "i")
        {
            doc.addLine(row);
        }
        else if (commend == "c")
        {
            doc.replaceLine(row);
        }
        else if (commend == "d")
        {
            doc.deleteLine(row);
        }
        else if (commend == "j")
        {
            doc.mergeLine(row);
        }
        else if (commend[0] == 36)
        {
            row = doc.v.size() - 1;
            std::cout << doc.v[row] << std::endl;
        }

        else if (commend[0] == '+' || commend[0] == '-')
        {
            if (is_number(commend.substr(1, commend.length() - 1)))
            {
                req = row + (to_integer(commend));
                if (is_valid(req))
                {
                    row = req;
                    std::cout << doc.v[row] << std::endl;
                }
                else
                    std::cout << "?" << std::endl;
            }
            else
                std::cout << "?" << std::endl;
        }
        // case -> find the line with the word "/text/""
        else if (commend[0] == '/' &&
                 commend[commend.length() - 1] == '/')
        {
            std::vector<std::string> temp = split(commend, "/");
            row = doc.findWord(temp[0], row + 1);
        }
        //case -> replace between words "s/old/new/""
        else if (commend[0] == 's' &&
                 commend[commend.length() - 1] == '/')
        {
            std::vector<std::string> temp = split(commend, "/");

            //replace between the words
            if (temp.size() == 3)
                doc.replaceWord(temp[1], temp[2], row);
            //if the "new" word is empty
            else if (temp.size() == 2)
                doc.removeWord(temp[1], row);
            //there is no word to replace (s//)
            else
                std::cout << "?" << std::endl;
        }
        else if (commend[0] == 'w')
            doc.createFile(commend.substr(2, commend.length() - 2));
        else
            std::cout << "?" << std::endl;

        getline(std::cin, commend);
    }
}
