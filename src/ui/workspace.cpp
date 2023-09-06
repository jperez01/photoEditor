#include "workspace.h"
#include "ui_workspace.h"

Workspace::Workspace(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Workspace),
    m_image(&m_layerManager, &m_toolManager)
{
    ui->setupUi(this);
}

Workspace::Workspace(int width, int height, QWidget *parent) :
        QWidget(parent), ui(new Ui::Workspace), m_image(&m_layerManager, &m_toolManager) {
    ui->setupUi(this);
    setMouseTracking(true);

    m_toolbar.setMouseTracking(true);
    m_toolbar.setOrientation(Qt::Vertical);
    QAction* pencilAction = m_toolbar.addAction("Pencil");
    connect(pencilAction, &QAction::triggered, [&] {
        m_toolManager.selectTool(0);

        QWidget* toolBarUI = m_toolManager.getCurrentTool()->getToolbarUI();
        ui->toolInfo->addWidget(toolBarUI);
    });

    QAction* eraserAction = m_toolbar.addAction("Eraser");

    ui->mainLayout->addWidget(&m_toolbar);
    ui->mainLayout->addWidget(&m_image);
}

Workspace::~Workspace()
{
    delete ui;
}

void Workspace::mousePressEvent(QMouseEvent *event) {
    QPointF point = cursor().pos();
    point = m_image.mapFromGlobal(point);

    m_painter.begin(&m_layerManager.getCurrentLayer()->image);
    m_painter.setRenderHint(QPainter::Antialiasing);
    m_toolManager.getCurrentTool()->mousePressEvent(point, m_painter);
    m_painter.end();
}

void Workspace::mouseMoveEvent(QMouseEvent *event) {
    QPointF point = cursor().pos();
    point = m_image.mapFromGlobal(point);
    lastPoint = point;

    if (event->buttons() == Qt::LeftButton && m_toolManager.getCurrentTool()->isMouseTrackingEnabled()) {
        m_painter.begin(&m_layerManager.getCurrentLayer()->image);
        m_painter.setRenderHint(QPainter::Antialiasing);

        m_toolManager.getCurrentTool()->mouseMoveEvent(point, m_painter);

        m_painter.end();
    }

    m_image.repaint();
}

void Workspace::paintEvent(QPaintEvent *event) {
    QPainter newPainter(this);
}
