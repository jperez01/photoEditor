cmake_minimum_required(VERSION 3.26)
project(photoEditor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/Users/juperez/Developer/libraries/Qt/6.5.2/macos/lib/cmake")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(photoEditor src/main.cpp
        src/core/image.cpp
        src/core/image.h
        src/ui/mainwindow.h src/ui/mainwindow.cpp src/ui/mainwindow.ui
        src/ui/projectwizard.h src/ui/projectwizard.cpp src/ui/projectwizard.ui
        src/ui/workspace.h src/ui/workspace.cpp src/ui/workspace.ui
        src/core/layerManager.cpp
        src/core/layerManager.h
        src/core/toolManager.cpp
        src/core/toolManager.h
        src/tools/pencil.cpp
        src/tools/pencil.h
        src/core/tool.cpp
        src/core/tool.h
)
target_include_directories(photoEditor PUBLIC "./src")

target_link_libraries(photoEditor
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

