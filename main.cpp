#include <QtGui>
#include <QQuickView>
#include <QApplication>
#include <QtQml>
#include <QQmlApplicationEngine>
#include <htranslator.h>

class TranslationTest : public QObject {

    Q_OBJECT
public:
    TranslationTest(QObject *parent = nullptr) : QObject(parent) {
        translator = new HTranslator(this);
    }
    ~TranslationTest() {
        delete translator;
    }
    Q_INVOKABLE void selectLanguage(QString language) {
        if(language == QString("fr")) {
            translator->load("t1_fr.qm", ".");
            qApp->installTranslator(translator);
        }
        if(language == QString("ko")) {
            translator->load("t1_ko", ".");
            qApp->installTranslator(translator);
        }
        if(language == QString("en")) {
            qApp->removeTranslator(translator);
        }
        emit languageChanged();

        // we do not want call qmlengine->retranslate() which re-evaluate all expressions
        //qobject_cast<QQmlApplicationEngine*>(parent())->retranslate();
    }
    Q_INVOKABLE QString getSourceText(const QString translatedText) {
        return translator->getSourceText(translatedText);
    }

signals:
    void languageChanged();
private:
    HTranslator *translator;
};

#include "main.moc"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    TranslationTest myObj(&engine);

    // for test
    myObj.selectLanguage("fr");

    engine.rootContext()->setContextProperty("rootItem", (QObject*)&myObj);
    const QUrl url(QStringLiteral("main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated, &app,
                     [url](QObject *obj, const QUrl &objUrl) {
                         if (!obj && url == objUrl) QCoreApplication::exit(-1);
                     },
                     Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
