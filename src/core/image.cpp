//
// Created by Juan Perez on 8/23/23.
//

#include "image.h"

#include <iostream>

void Image::mousePressEvent(QMouseEvent *event) {
    QPoint point = cursor().pos();

    point = mapFromGlobal(point);

    for (int x = point.x() - m_stencilSize; x < point.x() + m_stencilSize; x++) {
        for (int y = point.y() - m_stencilSize; y < point.y() + m_stencilSize; y++) {
            if (x < 0 || x > m_image.size().width() || y < 0 || y > m_image.size().height())
                continue;

            m_image.setPixel(x, y, qRgb(200, 200, 0));
        }
    }
    update();
}

void Image::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

    painter.drawImage(0, 0, m_image,
                      0, 0, m_image.width(), m_image.height());
}

