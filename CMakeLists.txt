cmake_minimum_required(VERSION 3.4)
set (CMAKE_CXX_STANDARD 11)

project(TestQt5LocationCMake)

find_package(Qt5Widgets)
find_package(Qt5UiTools)
find_package(Qt5Location)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

if(ANDROID)
    add_library(TQTL SHARED
        ${PROJECT_FILES}
        ${RESOURCES}
    )
    set_target_properties(TQTL PROPERTIES
        VERSION 1.0.0
        SOVERSION 1
    )
    include(submodules/qt-android-cmake/AddQtAndroidApk.cmake)
    add_qt_android_apk(tqtl_android TQTL
        PACKAGE_SOURCES ${CMAKE_CURRENT_LIST_DIR}/android_stuff
    )
else()
    add_executable(TQTL main.cpp)
endif()

target_include_directories(TQTL
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(TQTL
    Qt5::Widgets
    Qt5::UiTools
    Qt5::Location
)

