//
// Created by Juan Perez on 8/23/23.
//

#ifndef PHOTOEDITOR_IMAGE_H
#define PHOTOEDITOR_IMAGE_H

#include <QWidget>
#include <QPainter>
#include <QSlider>

#include <iostream>

class Image : public QWidget {
public:
    Image(int height, int width) {
        m_data = new char[height * width * 4];

        m_width = width;
        m_height = height;
        m_stencilSize = 1;

        m_image = QImage(width, height, QImage::Format_ARGB32);

        m_slider = new QSlider(Qt::Horizontal, this);
        m_slider->setMinimum(1);
        m_slider->setMaximum(50);
        connect(m_slider, &QSlider::valueChanged, [&] {
            m_stencilSize = m_slider->value();
        });

        setMouseTracking(true);
    }

    char getPixelData(int x, int y, int type) {
        return m_data[m_width * x + y + type];
    }

    inline char* getData() { return m_data; }

    void mousePressEvent(QMouseEvent* event) override;

    void paintEvent(QPaintEvent* event) override;

private:
    QImage m_image;
    char* m_data;
    int m_height;
    int m_width;

    QSlider* m_slider;
    int m_stencilSize;
};


#endif //PHOTOEDITOR_IMAGE_H
