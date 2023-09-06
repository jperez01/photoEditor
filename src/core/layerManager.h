//
// Created by Juan Perez on 9/1/23.
//

#pragma once

#include <QBitmap>
#include <QImage>

enum LayerBlendMode {
    NORMAL = 0
};

struct Layer {
    Layer(std::string name, int height, int width) :
        name(name), image(width, height, QImage::Format_ARGB32),
        opacity(1.0f), layerActive(false), mode(NORMAL) {}

    std::string name;
    QImage image;

    LayerBlendMode mode;
    float opacity;
    bool layerActive;
};

class LayerManager {
public:
    LayerManager();

    void addLayer(std::string name, int height, int width);
    void addLayer(Layer& layer);

    void removeLayer(int index);
    void selectLayer(int index);

    inline Layer* getCurrentLayer() { return m_selectedLayer; }

private:
    std::vector<Layer> m_layers;
    Layer* m_selectedLayer;
};
