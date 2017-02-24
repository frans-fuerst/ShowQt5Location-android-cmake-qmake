cmake_minimum_required(VERSION 3.4)
set (CMAKE_CXX_STANDARD 11)

project(TestGeoCMake)

find_package(Qt5Widgets)
find_package(Qt5UiTools)
find_package(Qt5Location)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

if(ANDROID)
    add_library(TestGeoCMake SHARED main.cpp    )
    set_target_properties(TestGeoCMake PROPERTIES
        VERSION 1.0.0
        SOVERSION 1
    )
    include(submodules/qt-android-cmake/AddQtAndroidApk.cmake)
    add_qt_android_apk(TestGeoCMake_android TestGeoCMake
        PACKAGE_SOURCES ${CMAKE_CURRENT_LIST_DIR}/android_stuff
    )
else()
    add_executable(TestGeoCMake main.cpp)
endif()

target_include_directories(TestGeoCMake
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(TestGeoCMake
    Qt5::Widgets
    Qt5::UiTools
    Qt5::Location
)

