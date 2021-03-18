TEMPLATE = app
QT       += core gui quick widgets

CONFIG += c++11

SOURCES += \
    main.cpp \

HEADERS += \

DISTFILES += \
    MyText.qml \
    main.qml \
    Button.qml

QmlFiles.path = $$OUT_PWD
QmlFiles.files += $$files($$PWD/*.qml)

TsFiles.path = $$OUT_PWD
TsFiles.files += $$files($$PWD/*.ts)

QmFiles.path = $$OUT_PWD
QmFiles.files += $$files($$PWD/*.qm)

INSTALLS += QmlFiles TsFiles QmFiles



