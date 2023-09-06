#ifndef WORKSPACE_H
#define WORKSPACE_H

#include <QWidget>
#include <QToolBar>

#include "core/image.h"
#include "core/toolManager.h"
#include "core/layerManager.h"

namespace Ui {
class Workspace;
}

class Workspace : public QWidget
{
    Q_OBJECT

public:
    explicit Workspace(QWidget *parent = nullptr);
    Workspace(int width, int height, QWidget* parent = nullptr);
    ~Workspace();

    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;

    void paintEvent(QPaintEvent* event) override;

private:
    Ui::Workspace *ui;
    QPainter m_painter;
    QPointF lastPoint;

    QToolBar m_toolbar;

    Image m_image;

    ToolManager m_toolManager;
    LayerManager m_layerManager;
};

#endif // WORKSPACE_H
