#include <QtGui>
#include <QQuickView>
#include <QApplication>
#include <QtQml>
#include <QQmlApplicationEngine>

class TranslationTest : public QObject {

    Q_OBJECT
public:
    TranslationTest(QObject *parent = nullptr) : QObject(parent) {
        translator1 = new QTranslator(this);
    }
    ~TranslationTest() {
        delete translator1;
    }
    Q_INVOKABLE void selectLanguage(QString language) {
        if(language == QString("fr")) {
            qDebug() << "set fr";
            translator1->load("t1_fr.qm", ".");
            qApp->installTranslator(translator1);
        }
        if(language == QString("sp")) {
            qDebug() << "set sp";
            translator1->load("t1_sp", ".");
            qApp->installTranslator(translator1);
        }
        if(language == QString("en")) {
            qDebug() << "set en";
            qApp->removeTranslator(translator1);
        }
        qobject_cast<QQmlApplicationEngine*>(parent())->retranslate();
    }
signals:
    void languageChanged();
private:
    QTranslator *translator1;
};

#include "main.moc"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    TranslationTest myObj(&engine);
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
