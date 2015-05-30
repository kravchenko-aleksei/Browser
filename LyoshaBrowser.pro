#-------------------------------------------------
#
# Project created by QtCreator 2015-05-29T18:13:13
#
#-------------------------------------------------

QT       += core gui network webkit webkitwidgets
CONFIG += console

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LyoshaBrowser
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    bookmarks.cpp \
    application.cpp \
    history.cpp \
    webpageinfo.cpp \
    urlchoosedialog.cpp \
    pageskeeper.cpp \
    settingsdialog.cpp

HEADERS  += mainwindow.h \
    bookmarks.h \
    application.h \
    history.h \
    webpageinfo.h \
    urlchoosedialog.h \
    pageskeeper.h \
    settingsdialog.h

FORMS    += mainwindow.ui \
    urlchoosedialog.ui \
    settingsdialog.ui
