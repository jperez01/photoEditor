//
// Created by Juan Perez on 9/5/23.
//

#include <iostream>
#include "toolManager.h"

#include "tools/pencil.h"

ToolManager::ToolManager() {
    Pencil* pencil = new Pencil();

    m_tools.push_back(pencil);

    m_selectedTool = m_tools.at(0);
}

ToolManager::~ToolManager() {
    for (auto tool : m_tools) {
        delete tool;
    }
}

void ToolManager::selectTool(int index) {
    if (index < 0 || index >= m_tools.size())
        std::cout << "Invalid Index: " << index << "\n";

    m_selectedTool = m_tools.at(index);
}
