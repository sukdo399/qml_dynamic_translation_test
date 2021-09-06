#include <QtGui>
#include <QQuickView>
#include <QApplication>
#include <QtQml>

class TranslationTest : public QObject {

    Q_OBJECT
    Q_PROPERTY(QString emptyString READ getEmptyString NOTIFY languageChanged)
public:
    TranslationTest(QObject *parent = nullptr) : QObject(parent) {
        translator1 = new QTranslator(this);
        translator2 = new QTranslator(this);
    }
    ~TranslationTest() {
        delete translator1;
        delete translator2;
    }
    QString getEmptyString() {
        return "";
    }
    Q_INVOKABLE void selectLanguage(QString language) {
        if(language == QString("fr")) {
            translator1->load("t1_fr", ".");
            qApp->installTranslator(translator1);
        }
        if(language == QString("ko")) {
            translator2->load("t1_ko", ".");
            qApp->installTranslator(translator2);
        }
        if(language == QString("en")) {
            qApp->removeTranslator(translator1);
            qApp->removeTranslator(translator2);
        }
        emit languageChanged();
    }
signals:
    void languageChanged();
private:
    QTranslator *translator1;
    QTranslator *translator2;
};

#include "main.moc"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    TranslationTest myObj;

//    myObj.selectLanguage("fr");

    QQuickView *view = new QQuickView;
    view->rootContext()->setContextProperty("rootItem", (QObject*)&myObj);
    view->setSource(QUrl::fromLocalFile("main.qml"));
    view->show();
    return app.exec();
}
