#include "Editor.hpp"

void Editor::setEditor(std::vector<std::string> v)
{
    this->file = new Document(v);
}

void Editor::loop() {}