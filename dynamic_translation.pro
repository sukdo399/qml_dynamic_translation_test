TEMPLATE = app
QT       += core gui quick widgets core-private

CONFIG += c++11

SOURCES += \
    htranslator.cpp \
    main.cpp \

HEADERS += \
    htranslator.h

DISTFILES += \
    MyText.qml \
    main.qml \
    Button.qml

TRANSLATIONS += t1_fr.ts t1_ko.ts

QmlFiles.path = $$OUT_PWD
QmlFiles.files += $$files($$PWD/*.qml)

QmFiles.path = $$OUT_PWD
QmFiles.files += $$files($$PWD/*.qm)

INSTALLS += QmlFiles QmFiles
