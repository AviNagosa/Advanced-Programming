#include "Editor.hpp"
#include <sstream>

void Editor::setEditor(std::vector<std::string> v)
{
    this->file = new Document(v);
    int row = 0;
}

void Editor::loop()
{
    std::string commend;
    std::cin >> commend;

    //commend for exit from the editor - 'q'
    while (commend != "q")
    {
        if (commend.length() == 1)
        {
            if (commend == "a")
            {
                this->file->addLine(this->row + 1);
            }
            else if (commend == "i")
            {
                this->file->addLine(this->row - 1);
            }
            else if (commend == "c")
            {
                this->file->replaceLine(this->row);
            }
            else if (commend == "d")
            {
                this->file->deleteLine(this->row);
            }
            else if (commend == "j")
            {
                this->file->mergeRows(this->row);
            }
            else //get the text in row 'i'
            {
                if (commend == "$")
                {
                    this->row = this->file->v.size() - 1;

                    std::cout << this->file->v[this->row];
                }
                else
                {
                    std::stringstream helper(commend);
                    helper >> this->row;

                    std::cout << this->file->v[this->row];
                }
            }
        }
        else if (commend.length() == 2)
        {
            int i = 0;
            if (commend[0] == '+')
            {
                std::stringstream helper(commend);
                helper >> i;
                this->row = this->row + i;

                std::cout << this->file->v[this->row];
            }
            else if (commend[0] == '-')
            {
                std::stringstream helper(commend);
                helper >> this->row;
                this->row = this->row - i;

                std::cout << this->file->v[this->row];
            }
        }
        else
        {
            if (commend[0] == '/' &&
                commend[commend.length() - 1] == '/') // case -> /text/
            {
                std::string word = commend.substr(1, 4);
                this->row = this->file->findWord(word, this->row + 1);
            }
            else if (commend[0] == 's' &&
                     commend[commend.length() - 1] == '/') //case -> s/old/new/
            {
                std::string _old = commend.substr(2, 3);
                std::string _new = commend.substr(6, 3);

                this->file->replaceWord(_old, _new, this->row);
            }
            else if (commend == "w file")
            {
                this->file->createFile();
            }
        }

        std::cin >> commend;
    }

    std::cout << "Exit" << std::endl;
}