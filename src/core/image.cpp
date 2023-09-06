//
// Created by Juan Perez on 8/23/23.
//

#include "image.h"

#include <iostream>

Image::Image(LayerManager* layerManager, ToolManager* toolManager)
    : m_layerManager(layerManager), m_toolManager(toolManager) {
    setMouseTracking(true);
}

void Image::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QPointF pos = cursor().pos();
    pos = mapFromGlobal(pos);

    if (m_layerManager) {
        QImage image = m_layerManager->getCurrentLayer()->image;
        painter.drawImage(0, 0, image,
                          0, 0, image.width(), image.height());

        m_toolManager->getCurrentTool()->paintEvent(pos, painter);
    }
}

