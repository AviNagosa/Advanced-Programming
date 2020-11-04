#include "Editor.hpp"
#include <sstream>

Editor::Editor(Document &d) : file(d) {}

//convert from string to interger
int Editor::to_integer(const std::string &s)
{
    int n;
    std::stringstream helper(s);
    helper >> n;
    return n;
}

//check if the string is a number
bool Editor::is_number(const std::string &s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it))
        ++it;
    return !s.empty() && it == s.end();
}

//check the valid of the commend
bool Editor::is_valid(const std::string &req)
{
    if (!is_number(req))
        return false;
    else if (to_integer(req) > file.v.size() || to_integer(req) < 0)
        return false;
    return true;
}

bool Editor::is_valid(int req)
{
    if (req > file.v.size() || req < 0)
        return false;
    return true;
}

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
            req = to_integer(commend);
            //check if the index valid
            if (!is_valid(req))
                std::cout << "?" << std::endl;
            else
            {
                row = req;
                std::cout << file.v[row] << std::endl;
            }
        }

        else if (commend == "a")
        {
            file.addLine(row + 1);
        }
        else if (commend == "i")
        {
            file.addLine(row - 1);
        }
        else if (commend == "c")
        {
            file.replaceLine(row);
        }
        else if (commend == "d")
        {
            file.deleteLine(row);
        }
        else if (commend == "j")
        {
            file.mergeRows(row);
        }
        else if (commend[0] == 36)
        {
            row = file.v.size() - 1;
            std::cout << file.v[row] << std::endl;
        }

        else if (commend[0] == '+')
        {
            if (is_number(commend.substr(1, commend.length() - 1)))
            {
                req = to_integer(commend);
                if (is_valid(row + req))
                {
                    row += req;
                    std::cout << file.v[row] << std::endl;
                }
                else
                    std::cout << "?" << std::endl;
            }
            else
                std::cout << "?" << std::endl;
        }

        else if (commend[0] == '-')
        {
            if (is_number(commend.substr(1, commend.length() - 1)))
            {
                req = to_integer(commend);
                if (is_valid(row - req))
                {
                    row -= req;
                    std::cout << file.v[row] << std::endl;
                }
                else
                    std::cout << "?" << std::endl;
            }
            else
                std::cout << "?" << std::endl;
        }

        else if (commend[0] == '/' &&
                 commend[commend.length() - 1] == '/') // case -> /text/
        {
            std::string word = commend.substr(1, 4);
            row = file.findWord(word, row + 1);
        }
        else if (commend[0] == 's' &&
                 commend[commend.length() - 1] == '/') //case -> s/old/new/
        {
            std::string _old = commend.substr(2, 3);
            std::string _new = commend.substr(6, 3);

            file.replaceWord(_old, _new, row);
        }
        else if (commend[0] == 'w')
        {
            file.createFile(commend.substr(2, commend.length() - 2));
        }
        else
            std::cout << "?" << std::endl;

        getline(std::cin, commend);
    }
}
