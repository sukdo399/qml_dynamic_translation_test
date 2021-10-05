TEMPLATE = app
QT       += core gui quick widgets

CONFIG += c++11

SOURCES += \
    main.cpp \

HEADERS += \

DISTFILES += \
    main.qml \
    t1_fr.qm \
    t1_sp.qm

TRANSLATIONS += t1_sp.ts t1_fr.ts

QmlFiles.path = $$OUT_PWD
QmlFiles.files += $$files($$PWD/*.qml)

QmFiles.path = $$OUT_PWD
QmFiles.files += $$files($$PWD/*.qm)

INSTALLS += QmlFiles QmFiles
