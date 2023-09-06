//
// Created by Juan Perez on 9/5/23.
//

#pragma once

#include <QPen>
#include <QHBoxLayout>
#include <QSlider>
#include <QLabel>

#include "core/tool.h"

class Pencil : public Tool {
public:
    Pencil();

    void paintEvent(const QPointF& position, QPainter& painter) override;
    void mousePressEvent(const QPointF& position, QPainter& painter) override;
    void mouseReleaseEvent(const QPointF& position, QPainter& painter) override;
    void mouseMoveEvent(const QPointF& position, QPainter& painter) override;

private:
    QPen m_pen;

    QHBoxLayout m_layout;
    QLabel m_label;
    QSlider m_slider;

    float size = 10;
    QPointF lastPosition;
};
