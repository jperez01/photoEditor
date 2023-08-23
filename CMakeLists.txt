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

add_executable(photoEditor src/main.cpp)
target_link_libraries(photoEditor
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

