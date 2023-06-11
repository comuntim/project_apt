QT += testlib network sql
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle
CONFIG += debug

TEMPLATE = app

SOURCES +=  tst_task3test.cpp\
    ../server/database.cpp \
    ../server/functions.cpp \
    ../server/functions.h \

