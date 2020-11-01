#include "Editor.hpp"

void Editor::setEditor(std::vector<std::string> v)
{
    file = new Document(v);
}

void Editor::loop() {}