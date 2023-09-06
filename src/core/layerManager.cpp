//
// Created by Juan Perez on 9/1/23.
//

#include <iostream>
#include "layerManager.h"

LayerManager::LayerManager() {
    addLayer("Layer 1", 500, 500);

    selectLayer(0);
}

void LayerManager::removeLayer(int index) {
    if (index < 0 || index >= m_layers.size())
        std::cout << "Invalid index: " << index << "\n";

    m_layers.erase(m_layers.begin() + index);
}

void LayerManager::selectLayer(int index) {
    if (index < 0 || index >= m_layers.size())
        std::cout << "Invalid index: " << index << "\n";

    m_selectedLayer = &m_layers.at(index);
}

void LayerManager::addLayer(Layer &layer) {
    m_layers.push_back(layer);
}

void LayerManager::addLayer(std::string name, int height, int width) {
    Layer layer(name, height, width);
    layer.image.fill(Qt::white);

    m_layers.push_back(layer);
}
