#pragma once

#include <QtWidgets/QMainWindow>
//#include "ui_Qt3.h"

#include <QtWidgets/QApplication>
#include <QtWebEngineWidgets>
#include <QtWebChannel>

//#include "LibraryWindowImplPlugin.h"

class zfab
{
public:
    zfab();
    ~zfab();
    QString name;
    QString id;
    int category;
    QString fileType;
    zfab* next;
    int isActive;
};

class myzfab
{
public:
    myzfab();
    ~myzfab();
    void add(QString name, QString id, int category, QString fileType);

    int count;
    zfab* first;
    zfab* lost;
};

//����� ���� ���������� ���������� ----
namespace CLOAPI
{
    class Downloader;

    class Qt3 : public QMainWindow
    {
        Q_OBJECT

    public:
        Qt3(QWidget* parent = nullptr);
        //Qt3(LibraryWindowImplPlugin* parent = nullptr);
        ~Qt3();

        void vebview();

    public Q_SLOTS:
        void sendTextToCpp3(const QString& text);//����������������

    public Q_SLOTS:
        void sendToCppAddMaterial(QString url, QString name, QString id, int category);//��������� ������ �� js

    Q_SIGNALS:
        void sendToWebUploaded(QString id, int result);//������ � js

    public Q_SLOTS:
        void sendToCppProjFilePath();//������ �� ������ ���� � �����

    Q_SIGNALS:
        void sendToWebProjFilePath(QString filePath);//�������� ���� � �����

    private:
        QWebEngineView* pageview;
        QWebChannel* channel;
        Downloader* downloader;
        QWebEngineProfile* defaultProfile;
    };
}

//����� �������� �� ����
namespace CLOAPI
{
    class Downloader : public QObject
        //class Downloader : public Qt3
    {
        Q_OBJECT
    public:
        explicit Downloader(QObject* parent = 0);
        //explicit Downloader(Qt3* parent = 0);

        //Qt3* plag;

        void saveFile(char* data, int dataSize, const char* name, const char* dirName);

    signals:
        void onReady();

    public slots:
        void getData(QString urlstr, QString name, QString dirName, QString id_);     // ����� ������������� ������� �� ��������� ������
        void onResult(QNetworkReply* reply);    // ���� ��������� ������ � ���������� ������

    private:
        QNetworkAccessManager* manager; // �������� �������� �������

        //QString filePuth;//���� � ����� ��� ����������

        Qt3* p;
        //QString id;
    };
}

//����� ���� ���������� ������
namespace CLOAPI
{
    class Qt4 : public QMainWindow
    {
        Q_OBJECT

    public:
        Qt4(QWidget* parent = nullptr);
        ~Qt4();

        void vebview();

    public Q_SLOTS:
        void sendToCppAddColor(QString colorHex, QString colorName, QString palitName);//��������� ������ �� js

    Q_SIGNALS:
        void signalToWeb12(QString id);//������ � js. ����������������

    public Q_SLOTS:
        void sendToCppProjFilePath();//������ �� ������ ���� � �����

    Q_SIGNALS:
        void sendToWebProjFilePath(QString filePath);//�������� ���� � �����

    private:
        QWebEngineView* pageview;
        QWebChannel* channel;
        void addColor(int R_, int G_, int B_, QString colorName, QString palitName);
        QWebEngineProfile* defaultProfile;
    };
}

//����� ���� ����������
namespace CLOAPI
{
    class Qt5 : public QMainWindow
    {
        Q_OBJECT

    public:
        Qt5(QWidget* parent = nullptr);
        ~Qt5();

        void vebview();

    public Q_SLOTS:
        void sendToCppGetColorWays();//��������� colorWays

    Q_SIGNALS:
        void sendToWebColorWays(QString allColorWays);//�������� ������� colorWays

    public Q_SLOTS:
        void sendToCppRender(int turntable, int isCreateGLB, QString dirPath);//������ ������� � �����������

    Q_SIGNALS:
        void sendToWebRenderFinish(QString renderAnswer);//�������� ������� ������� � ���������� �������

    //public Q_SLOTS:
        //void sendToCppProjFilePath();//������ �� ������ ���� � �����

    //Q_SIGNALS:
        //void sendToWebProjFilePath(QString filePath);//�������� ���� � �����

    private:
        QWebEngineView* pageview;
        QWebChannel* channel;
    };
}

