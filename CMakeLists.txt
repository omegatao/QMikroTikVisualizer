cmake_minimum_required(VERSION 3.16)

project(QMikroTikVisualizer VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick WebEngineQuick Core REQUIRED)
find_package(spdlog REQUIRED)

add_subdirectory(thirdParty/tikpp)

qt_add_executable(appQMikroTikVisualizer
    main.cpp
    iplookupinterface.h
    iplookupgeoip2.h
    iplookupgeoip2.cpp
    routerinfohandler.h
    routerinfohandler.cpp
)

#qt_add_qml_module(appQMikroTikVisualizer
#    URI QMikroTikVisualizer
#    VERSION 1.0
#    QML_FILES ./resources/qml/main.qml
#)

set(resources_resource_files
    "resources/pages/echarts.js"
    "resources/pages/echarts-gl.min.js"
    "resources/pages/world.js"
    "resources/pages/index.html"
    "resources/pages/cpuInfo.html"
    "resources/pages/connectionInfo.html"
    "resources/qml/main.qml"
    "resources/qml/EchartsView.qml"
    "resources/qml/StatusBar.qml"
    "resources/qml/StackViewPage.qml"
    "resources/qml/GridOne.qml"
    "resources/qml/CPUInfoPage.qml"
    "resources/qml/ConnectionInfoPage.qml"
    "resources/qml/SettingPage.qml"
)

qt_add_resources(appQMikroTikVisualizer "resources"
    PREFIX
        "/"
    BASE
        "resources"
    FILES
        ${resources_resource_files}
)


set_target_properties(appQMikroTikVisualizer PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appQMikroTikVisualizer
    PRIVATE Qt6::Quick Qt::WebEngineQuick spdlog::spdlog_header_only maxminddb tikpp)

install(TARGETS appQMikroTikVisualizer
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
