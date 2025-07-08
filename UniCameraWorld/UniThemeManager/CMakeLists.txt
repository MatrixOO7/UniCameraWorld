cmake_minimum_required(VERSION 3.24)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)

qt_standard_project_setup(REQUIRES 6.8)

set(QT_QML_GENERATE_QMLTYPES TRUE)
set(QT_QML_GENERATE_QMLLS_INI ON)

qt_add_qml_module(uniThemeManager
    URI UniThemeManager
    VERSION 1.1

    QML_FILES

    SOURCES

        UniThemeManager.cpp
        UniThemeManager.h

    RESOURCES
        # dark theme
        Theme/dark/button.json
        Theme/dark/label.json
        Theme/dark/mainWindow.json
        Theme/dark/setting.json
        Theme/dark/sideMenu.json
        Theme/dark/theme.json

        # modern dark theme
        Theme/modern_dark/button.json
        Theme/modern_dark/label.json
        Theme/modern_dark/mainWindow.json
        Theme/modern_dark/setting.json
        Theme/modern_dark/sideMenu.json
        Theme/modern_dark/theme.json

        # light theme
        Theme/light/button.json
        Theme/light/label.json
        Theme/light/mainWindow.json
        Theme/light/setting.json
        Theme/light/sideMenu.json
        Theme/light/theme.json

        # modern light theme
        Theme/modern_light/button.json
        Theme/modern_light/label.json
        Theme/modern_light/mainWindow.json
        Theme/modern_light/setting.json
        Theme/modern_light/sideMenu.json
        Theme/modern_light/theme.json

        # unicorn theme
        Theme/unicorn/button.json
        Theme/unicorn/label.json
        Theme/unicorn/mainWindow.json
        Theme/unicorn/setting.json
        Theme/unicorn/sideMenu.json
        Theme/unicorn/theme.json
        SOURCES unibaseinfo.h unibaseinfo.cpp
        SOURCES unifont.h unifont.cpp
        SOURCES unistyle.h unistyle.cpp
        SOURCES unicolorsolid.h unicolorsolid.cpp
        SOURCES unicolorgradient.h unicolorgradient.cpp
        SOURCES unicolorstate.h unicolorstate.cpp
        SOURCES unibuttonitem.h unibuttonitem.cpp
        SOURCES unibutton.h unibutton.cpp

)

target_link_libraries(uniThemeManager
    PRIVATE
    Qt6::Quick
)
target_link_libraries(uniThemeManager PRIVATE Qt6::Core)
target_link_libraries(uniThemeManager PRIVATE Qt6::Core)
target_link_libraries(uniThemeManager PRIVATE Qt6::Core)
target_link_libraries(uniThemeManager PRIVATE Qt6::Core)
target_link_libraries(uniThemeManager PRIVATE Qt6::Core)
target_link_libraries(uniThemeManager PRIVATE Qt6::Core)
target_link_libraries(uniThemeManager PRIVATE Qt6::Core)
target_link_libraries(uniThemeManager PRIVATE Qt6::Core)
