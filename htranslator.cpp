#include "htranslator.h"
#include <QDebug>

HTranslator::HTranslator(QObject *parent) : QTranslator(parent) {

}

HTranslator::~HTranslator() {

}

QString HTranslator::getSourceText(const QString translatedText) {
    qDebug() << __FUNCTION__ << translatedText;

    // TODO: we cannot access to QTranslatorPrivate

    return QString("Hello");
}
