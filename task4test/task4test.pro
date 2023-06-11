QT += testlib network sql
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_test4.cpp \
../server/database.cpp \
../server/functions.cpp \
../server/functions.h \
