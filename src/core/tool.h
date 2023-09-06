//
// Created by Juan Perez on 9/5/23.
//

#pragma once

#include <QWidget>
#include <QPainter>

class Tool {
public:
    Tool();
    virtual ~Tool();

    QWidget* getToolbarUI() { return ui.get(); }
    inline bool isMouseTrackingEnabled() { return mouseTracking; }

    virtual void mousePressEvent(const QPointF& position, QPainter& painter) = 0;
    virtual void mouseReleaseEvent(const QPointF& position, QPainter& painter) = 0;
    virtual void mouseMoveEvent(const QPointF& position, QPainter& painter) = 0;

    virtual void paintEvent(const QPointF& position, QPainter& painter) = 0;

protected:
    std::string name;
    std::unique_ptr<QWidget> ui;

    bool mouseTracking;
};
