//
// Created by Juan Perez on 9/5/23.
//

#include "tool.h"

Tool::~Tool() = default;

Tool::Tool() {
    ui = std::make_unique<QWidget>();
}
