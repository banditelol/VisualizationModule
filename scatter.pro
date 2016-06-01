TEMPLATE = app

QT += datavisualization\
      core

contains(TARGET, qml.*) {
    QT += qml quick
}

SOURCES += main.cpp scatterdatamodifier.cpp \
    visualconfigdialog.cpp \
    mainwindow.cpp
HEADERS += scatterdatamodifier.h \
    visualconfigdialog.h \
    mainwindow.h

QT += widgets

OTHER_FILES += doc/src/* \
               doc/images/*
