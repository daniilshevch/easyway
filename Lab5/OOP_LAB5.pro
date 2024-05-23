QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    tr_map.cpp \
    trolleybus22.cpp \
    trolleybus23.cpp \
    trolleybus24.cpp \
    trolleybus25.cpp \
    trolleybus27.cpp \
    trolleybus30.cpp \
    trolleybus31.cpp \
    trolleybus32.cpp \
    trolleybus33.cpp \
    trolleybus38.cpp \
    trolleybus_list.cpp

HEADERS += \
    classes.h \
    mainwindow.h \
    tr_map.h \
    trolleybus22.h \
    trolleybus23.h \
    trolleybus24.h \
    trolleybus25.h \
    trolleybus27.h \
    trolleybus30.h \
    trolleybus31.h \
    trolleybus32.h \
    trolleybus33.h \
    trolleybus38.h \
    trolleybus_list.h

FORMS += \
    mainwindow.ui \
    tr_map.ui \
    trolleybus22.ui \
    trolleybus23.ui \
    trolleybus24.ui \
    trolleybus25.ui \
    trolleybus27.ui \
    trolleybus30.ui \
    trolleybus31.ui \
    trolleybus32.ui \
    trolleybus33.ui \
    trolleybus38.ui \
    trolleybus_list.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    recource.qrc
