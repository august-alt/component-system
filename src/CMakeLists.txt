find_package(Qt5 COMPONENTS Widgets Core REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

set(HEADERS
    abstractcompositesnapin.h
    abstractsnapin.h
    common.h
    compositesnapindetailsdialog.h
    factory.h
    icompositesnapin.h
    isnapin.h
    isnapindetailsdialog.h
    isnapinmanager.h
    model.h
    plugin.h
    pluginstorage.h
    snapindetailsdialog.h
    snapindetailsfactory.h
    snapindetailswidget.h
    snapinloader.h
    snapinmanagementsettings.h
    snapinmanagementwidget.h
    snapinmanager.h
)

set(SOURCES
    abstractcompositesnapin.cpp
    abstractsnapin.cpp
    compositesnapindetailsdialog.cpp
    model.cpp
    plugin.cpp
    pluginstorage.cpp
    snapindetailsdialog.cpp
    snapindetailsfactory.cpp
    snapindetailswidget.cpp
    snapinloader.cpp
    snapinmanagementwidget.cpp
    snapinmanager.cpp
    snapinstate.h
)

set(UI_FORMS
    compositesnapindetailsdialog.ui
    snapindetailsdialog.ui
    snapindetailswidget.ui
    snapinmanagementwidget.ui
)

set(SOURCES ${SOURCES} ${HEADERS} ${UI_FORMS})

add_library(component-system_static STATIC ${SOURCES})
target_link_libraries(component-system_static Qt5::Core Qt5::Widgets)
