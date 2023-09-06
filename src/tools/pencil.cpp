//
// Created by Juan Perez on 9/5/23.
//

#include "pencil.h"

Pencil::Pencil() {
    name = "Pencil";
    m_pen = QPen(QColor(200, 200, 200));

    mouseTracking = true;

    m_label.setText("Size");
    m_slider.setRange(1, 50);
    m_slider.setOrientation(Qt::Horizontal);
    QObject::connect(&m_slider, &QSlider::valueChanged, &m_layout, [&] {
        m_pen.setWidth(m_slider.value());
    });

    m_layout.addWidget(&m_label);
    m_layout.addWidget(&m_slider);
    ui.get()->setLayout(&m_layout);
}

void Pencil::paintEvent(const QPointF& position, QPainter& painter) {
    int ellipseSize = m_pen.width();
    int finalSize = ellipseSize / 2 + 2;

    painter.setPen(Qt::black);
    painter.setBrush(Qt::transparent);
    painter.drawEllipse(position.x() - finalSize, position.y() - finalSize,
                        ellipseSize, ellipseSize);
}

void Pencil::mousePressEvent(const QPointF &position, QPainter &painter) {
    lastPosition = position;

    paintEvent(position, painter);
}

void Pencil::mouseReleaseEvent(const QPointF &position, QPainter &painter) {

}

void Pencil::mouseMoveEvent(const QPointF &position, QPainter &painter) {
    painter.setPen(m_pen);
    painter.drawLine(position, lastPosition);

    lastPosition = position;
}
