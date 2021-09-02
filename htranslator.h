#ifndef HTRANSLATOR_H
#define HTRANSLATOR_H

#include <QObject>
#include <QTranslator>

class HTranslator : public QTranslator
{
    Q_OBJECT
public:
    explicit HTranslator(QObject *parent = nullptr);
    ~HTranslator();

    QString getSourceText(const QString translatedText);
};

#endif // HTRANSLATOR_H
