QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    Source/MainWindow.cpp \
    Source/ApplicationState.cpp \
    Source/EditLocations.cpp \
    Source/Item.cpp \
    Source/ItemSelection.cpp \
    Source/Location.cpp \
    Source/ManageItems.cpp \
    Source/ManageRoutes.cpp \
    Source/ManageTrucks.cpp \
    Source/Route.cpp \
    Source/Truck.cpp \
    Source/ViewRoutes.cpp

HEADERS += \
    Source/MainWindow.h \
    Source/ApplicationState.h \
    Source/EditLocations.h \
    Source/Item.h \
    Source/ItemSelection.h \
    Source/Location.h \
    Source/ManageItems.h \
    Source/ManageRoutes.h \
    Source/ManageTrucks.h \
    Source/Route.h \
    Source/Truck.h \
    Source/ViewRoutes.h

FORMS += \
    Source/MainWindow.ui\
    Source/EditLocations.ui\
    Source/ItemSelection.ui\
    Source/ManageItems.ui\
    Source/ManageRoutes.ui\
    Source/ManageTrucks.ui\
    Source/ViewRoutes.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
