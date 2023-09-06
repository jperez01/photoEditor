//
// Created by Juan Perez on 8/23/23.
//

#ifndef PHOTOEDITOR_IMAGE_H
#define PHOTOEDITOR_IMAGE_H

#include <QWidget>
#include <QPainter>
#include <QSlider>
#include <QHBoxLayout>
#include <QLabel>
#include <QMouseEvent>

#include <iostream>
#include "layerManager.h"
#include "toolManager.h"

class Image : public QWidget {
public:
    Image(LayerManager* layerManager, ToolManager* toolManager);

    void paintEvent(QPaintEvent* event) override;

private:
    LayerManager* m_layerManager;
    ToolManager* m_toolManager;
};


#endif //PHOTOEDITOR_IMAGE_H
