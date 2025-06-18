cmake_minimum_required(VERSION 3.24)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.8)

set(QT_QML_GENERATE_QMLTYPES TRUE)
set(QT_QML_GENERATE_QMLLS_INI ON)

#set(QML_SINGLETON_FILES
#    UniThemeManager.qml
#)

#set_source_files_properties(
#    ${QML_SINGLETON_FILES}
#    PROPERTIES
#        QT_QML_SINGLETON_TYPE TRUE
#)

qt_add_qml_module(uniThemeManager
    URI UniThemeManager
    VERSION 1.1

    QML_FILES
 #       ThemeManager.qml


    SOURCES
        UniThemeManager.cpp
        UniThemeManager.h
        QML_FILES ThemeManager.qml
)

target_link_libraries(uniThemeManager
    PRIVATE
    Qt6::Quick
)
