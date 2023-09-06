//
// Created by Juan Perez on 9/5/23.
//

#pragma once

#include <vector>
#include "core/tool.h"

class ToolManager {
public:
    ToolManager();
    ~ToolManager();

    void selectTool(int index);

    Tool* getCurrentTool() { return m_selectedTool; }
private:
    std::vector<Tool*> m_tools;
    Tool* m_selectedTool;
};

