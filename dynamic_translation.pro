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

TRANSLATIONS += t1_sp.ts t1_fr.ts

QmlFiles.path = $$OUT_PWD
QmlFiles.files += $$files($$PWD/*.qml)

QmFiles.path = $$OUT_PWD
QmFiles.files += $$files($$PWD/*.qm)

INSTALLS += QmlFiles QmFiles
