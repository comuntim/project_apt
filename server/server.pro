QT -= gui # Отключение графической оболочки

QT += network # Для работы с сетью
#QT += widgets
QT += sql


CONFIG += c++11 console # Конфигурация: версия с++ и тип приложения
CONFIG -= app_bundle

DEFINES += QT_DEPRECATED_WARNINGS # Игнорирование WARNING'ов при запуске

SOURCES += \ # Подключаем файлы исходного кода
    database.cpp \
    functions.cpp \
    main.cpp \
    server.cpp


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \  # Подключаем заголовочные файлы
    database.h \
    functions.h \
    server.h

