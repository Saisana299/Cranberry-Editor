cmake_minimum_required(VERSION 3.19)
project(Cranberry-Editor LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets SerialPort)

qt_standard_project_setup()

qt_add_executable(Cranberry-Editor
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    settingsdialog.h settingsdialog.cpp settingsdialog.ui
    console.h console.cpp
)

target_link_libraries(Cranberry-Editor
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt::SerialPort
)

include(GNUInstallDirs)

install(TARGETS Cranberry-Editor
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET Cranberry-Editor
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
