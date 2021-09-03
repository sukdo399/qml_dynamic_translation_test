#ifndef HTRANSLATOR_H
#define HTRANSLATOR_H

#include <QtCore/qobject.h>
#include <QtCore/qbytearray.h>
#include <QTranslator>

QT_BEGIN_NAMESPACE


#ifndef QT_NO_TRANSLATION

class QLocale;
class HTranslatorPrivate;

class Q_CORE_EXPORT HTranslator : public QTranslator
{
    Q_OBJECT
public:
    explicit HTranslator(QObject *parent = nullptr);
    ~HTranslator();

    virtual QString translate(const char *context, const char *sourceText,
                              const char *disambiguation = nullptr, int n = -1) const;

    virtual bool isEmpty() const;

    QString language() const;
    QString filePath() const;

    bool load(const QString & filename,
              const QString & directory = QString(),
              const QString & search_delimiters = QString(),
              const QString & suffix = QString());
    bool load(const QLocale & locale,
              const QString & filename,
              const QString & prefix = QString(),
              const QString & directory = QString(),
              const QString & suffix = QString());
    bool load(const uchar *data, int len, const QString &directory = QString());

    QString getSourceText(const QString translatedText);

private:
    Q_DISABLE_COPY(HTranslator)
    Q_DECLARE_PRIVATE(HTranslator)
};

#endif // QT_NO_TRANSLATION

QT_END_NAMESPACE
#endif // HTRANSLATOR_H
