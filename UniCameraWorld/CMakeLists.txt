cmake_minimum_required(VERSION 3.16)

project(UniCameraWorld VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick )

add_subdirectory (UniThemeManager)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(appUniCameraWorld
    main.cpp
)

qt_add_qml_module(appUniCameraWorld
    URI UniCameraWorld
    VERSION 1.0
    QML_FILES
        Main.qml
        UniButton.qml
        QML_FILES UniLabel.qml

    RESOURCES
        Resource/Image/logo.png
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appUniCameraWorld PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appUniCameraWorld
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appUniCameraWorld
    PRIVATE
    Qt6::Quick
    uniThemeManager
)

include(GNUInstallDirs)
install(TARGETS appUniCameraWorld
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
