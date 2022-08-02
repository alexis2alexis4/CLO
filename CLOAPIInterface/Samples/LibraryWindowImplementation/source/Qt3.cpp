#include "Qt3.h"

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QUrl>

#include "LibraryWindowImplPlugin.h"
//#include "classes/APIStorage.h"
#include "classes/APIDefine.h"

#include "CLOAPIInterface.h"
#include "UtilityAPIInterface.h"

zfab::zfab()
{
    next = 0;
    isActive = 0;
}
zfab::~zfab()
{}

myzfab::myzfab()
{
    first = new zfab;
    lost = first;
    count = 0;
}
myzfab::~myzfab()
{}
void myzfab::add(QString name, QString id, int category, QString fileType)
{
    lost->name = name;
    lost->id = id;
    lost->category = category;
    lost->fileType = fileType;
    count++;
    lost->next = new zfab;
    lost = lost->next;
}

extern myzfab* materials;//Список материалов для загрузки

namespace CLOAPI
{
    extern LibraryWindowImplPlugin* tempPoint;//Необходимо для вызова функции перезагрузки плагина
}

//Класс окна библиотеки материалов
namespace CLOAPI
{
    // ---
    Qt3::Qt3(QWidget* parent)
        : QMainWindow(NULL)
        //: QMainWindow(this)
    {
        //this->windowModality();
        pageview = NULL;
        channel = NULL;
        downloader = NULL;
        
        pageview = new QWebEngineView();
        if (pageview == NULL)
        {
            QMessageBox::information(NULL, "pageview is NULL", "pageview is NULL");
        }

        channel = new QWebChannel(pageview->page());
        if (channel == NULL)
        {
            QMessageBox::information(NULL, "channel is NULL", "channel is NULL");
        }
        pageview->page()->setWebChannel(channel);
        channel->registerObject(QStringLiteral("cppobject"), this);

        downloader = new Downloader(this);
        if (downloader == NULL)
        {
            QMessageBox::information(NULL, "downloader is NULL", "downloader is NULL");
        }
        //downloader->p

        //QWebEngineProfile::defaultProfile()->setPersistentCookiesPolicy(QWebEngineProfile::ForcePersistentCookies);
        defaultProfile = QWebEngineProfile::defaultProfile();
        defaultProfile->setCachePath(SAMPLE_STORAGE_DIRECTORY + "tmp/");
        defaultProfile->setPersistentStoragePath(SAMPLE_STORAGE_DIRECTORY+"tmp/");
        defaultProfile->setPersistentCookiesPolicy(QWebEngineProfile::ForcePersistentCookies);
    }
    // ---
    Qt3::~Qt3()
    {
        
        /*QMessageBox::information(NULL, "Qt3 destructor", "Qt3 destructor");
        this->close();
        delete pageview;
        pageview = NULL;
        delete channel;
        channel = NULL;
        delete downloader;
        downloader = NULL;*/
    }
    // ---
    void Qt3::vebview()
    {
        try
        {
            pageview->load(QUrl("http://138.201.202.166/CLO/t3.html"));
            
            //QString urlstr = SAMPLE_STORAGE_DIRECTORY + "t3.html";
            //pageview->load(QUrl(urlstr));
            
            //pageview->load(QUrl("https://beproduct-cloplugin.azurewebsites.net/?target=materials"));
            
            //pageview->load(QUrl("http://localhost:44304/?target=materials"));

            //pageview->load(QUrl("https://localhost:44305"));
        }
        catch (...)
        {
        }

        this->setWindowTitle("BeProduct Material Library");
        this->setCentralWidget(pageview);
        this->resize(1280, 800);
        this->setMinimumWidth(1280);
        this->setMinimumHeight(800);
        this->show();
    }
    // ---
    void Qt3::sendTextToCpp3(const QString& text)
    {}
    // ---
    void Qt3::sendToCppAddMaterial(QString url, QString name, QString id, int category)
    {
        if (url.size() > 0 && name.size() > 0 && id.size() > 0)
        {
            if (category < 0 || category > 11)category = 1;

            QStringList list = url.split(".");//Делим на части разделённые точкой
            QString fileType = list.takeLast();//Берём последнюю часть

            QString path = SAMPLE_STORAGE_DIRECTORY + name + "." + fileType;
            if (materials)
            {
                materials->add(name, id, category, fileType);//Добавляем характеристики материала в список
            }
            downloader->getData(url, path, SAMPLE_STORAGE_DIRECTORY, id);

        }
        else
        {
            emit this->sendToWebUploaded(id, 1);//Ошибка. Пустые данные
        }
    }
    //
    void Qt3::sendToCppProjFilePath()
    {
        string path = UTILITY_API->GetProjectFilePath();
        emit sendToWebProjFilePath(path.data());
    }
    //
}

//Класс для сетевой загрузки
namespace CLOAPI
{
    //extern int viewMode;    

    Downloader::Downloader(QObject* parent) : QObject(parent)
    //Downloader::Downloader(Qt3* parent) : QObject(parent)
    {
        //plag = parent;
        //Инициализируем менеджер
        manager = new QNetworkAccessManager();
        //Подключаем сигнал о завершении получения данных к обработчику полученного ответа
        connect(manager, &QNetworkAccessManager::finished, this, &Downloader::onResult);

        p = (Qt3*)parent;
    }

    void Downloader::getData(QString urlstr, QString name, QString dirName, QString id_)
    {
        //Создание необходимой директории. Если нужно.
        QDir dir;
        if (!dir.exists(dirName))
        {
            if (dir.mkpath(dirName))
            {
                //QMessageBox::information(NULL, "Ohoho", "Dir created");
            }
        }

        //filePuth = name;
        //id = id_;

        QUrl url(urlstr);
        QNetworkRequest request;
        request.setUrl(url);
        auto reply = manager->get(request);
        reply->setProperty("filePuth", name);
        reply->setProperty("id", id_);
    }

    void Downloader::onResult(QNetworkReply* reply)
    {
        QString id = reply->property("id").toString();
        QString filePuth = reply->property("filePuth").toString();

        if (reply->error() != QNetworkReply::NoError)//Если в процесе получения данных произошла ошибка
        {
            //QMessageBox::information(NULL, "Load error", reply->errorString());
            emit p->sendToWebUploaded(id,2);//Отправка сигнала на веб страницу о завершении загрузки
        }
        else
        {
            //QMessageBox::information(NULL, "test step", "Ohoho 1234");
            //QFile* file = new QFile("C:\\Users\\Public\\Documents\\CLO\\Assets\\Materials\\test 1\\Cotton_14_Wale_Corduroy.zfab");
            QFile* file = new QFile(filePuth);
            //QFile* file = new QFile(reply->property("filePuth").toString());
            // Создаём файл или открываем его на перезапись ...
            if (file->open(QFile::WriteOnly))
            {
                file->write(reply->readAll());  //Записываем всю информацию со страницы в файл
                file->close();                  // закрываем файл
                //qDebug() << "Downloading is completed";
            }
            else
            {
                emit p->sendToWebUploaded(id, 3);//Отправка сигнала на веб страницу о завершении загрузки
            }
            delete[] file;
            //filePuth.clear();

            //QMessageBox::information(NULL, "test", "1");
            string result = "{\"BeProductId\":123098}";
            UTILITY_API->SetAPIMetaData(filePuth.toStdString(), result);
            //QMessageBox::information(NULL, "test", "2");

            ////
            //saveFile(reply->readAll().data(), reply->readAll().size(), "C:\\Users\\Public\\Documents\\CLO\\Assets\\Materials\\test 1\\Cotton_14_Wale_Corduroy.zfab", "C:\\Users\\Public\\Documents\\CLO\\Assets\\Materials\\test 1");
            ////
            /*if (num > 0 && num < 9)
            {
                zfab* a = materials->first;
                for (int i = 1; i < num; i++)
                {
                    a = a->next;
                }
                a->isActive = 1;
            }*/
            zfab *a = materials->first;
            for (int i = 0; i < materials->count; i++)
            {
                if (a->id == id)
                {
                    a->isActive = 1;
                    emit p->sendToWebUploaded(id,0);//Отправка сигнала на веб страницу о завершении загрузки
                    break;
                }
                a = a->next;
            }
            
            //emit onReady(); // Посылаем сигнал о завершении получения файла
            //DESTROY_API_STORAGE;
            tempPoint->test();
            //tempPoint->ResetPLMSettingsWidget();
            //API_STORAGE->GenerateAPIItemListForSample();
            //API_STORAGE
            //SetFabricAPI
            //viewMode = 1;
            /*QMessageBox::information(NULL, "a", "1");
            UTILITY_API->RefreshColorwayDialog();
            QMessageBox::information(NULL, "b", "2");
            UTILITY_API->ResetClothArrangement();
            QMessageBox::information(NULL, "c", "3");
            UTILITY_API->UpdateColorways();*/
            
            //FABRIC_API->ChangeMetaDataValueForFabric()
            //QMessageBox::information(NULL, "c", "3");
            //FABRIC_API->ExportZFab();
            //QMessageBox::information(NULL, "c", "3");
        }
    }

    void Downloader::saveFile(char* data, int dataSize, const char* name, const char* dirName)
    {
        /*//QString e = ui->text_e->toPlainText();
        QFile file(name);
        file.open(QIODevice::WriteOnly | QIODevice::b);
        file.write(data);
        file.close();*/

        QDir dir;
        if (!dir.exists(dirName))
        {
            if (dir.mkpath(dirName))
            {
                QMessageBox::information(NULL, "Ohoho", "Dir created");
            }
        }

        /*if (!QDir(dirName).exists())
        {
            QDir().mkdir("C:\\Program Files\\CLO Standalone OnlineAuth\\");
            QDir().mkdir("C:\\Program Files\\CLO Standalone OnlineAuth\\Preset\\");
            QDir().mkdir("C:\\Program Files\\CLO Standalone OnlineAuth\\Preset\\Project\\");
            QDir().mkdir("C:\\Program Files\\CLO Standalone OnlineAuth\\Preset\\Project\\CLO\\");
            QDir().mkdir("C:\\Program Files\\CLO Standalone OnlineAuth\\Preset\\Project\\CLO\\test 1\\");
        }*/

        /*QDir dir(dirName);
        if (!dir.exists())
        {
            dir.mkpath(".");
        }*/

        /*ofstream out(name, ios::out | ios::binary);
        if (!out.fail())
        {
            out.write(data, dataSize);
        }
        else
        {
            QMessageBox::information(NULL, "Error", "File not created");
        }
        out.close();*/
    }
}

//Класс окна библиотеки цветов
namespace CLOAPI
{
    //extern Qt3* myWindowMaterial;
    // ---
    Qt4::Qt4(QWidget* parent)
        : QMainWindow(NULL)
    {
        pageview = NULL;
        channel = NULL;

        pageview = new QWebEngineView();
        if (pageview == NULL)
        {
            QMessageBox::information(NULL, "pageview is NULL", "pageview is NULL");
        }

        channel = new QWebChannel(pageview->page());
        if (channel == NULL)
        {
            QMessageBox::information(NULL, "channel is NULL", "channel is NULL");
        }
        pageview->page()->setWebChannel(channel);
        channel->registerObject(QStringLiteral("cppobjectcolor"), this);

        //QWebEngineProfile::defaultProfile()->setPersistentCookiesPolicy(QWebEngineProfile::ForcePersistentCookies);
        defaultProfile = QWebEngineProfile::defaultProfile();
        defaultProfile->setCachePath(SAMPLE_STORAGE_DIRECTORY + "tmp/");
        defaultProfile->setPersistentStoragePath(SAMPLE_STORAGE_DIRECTORY + "tmp/");
        defaultProfile->setPersistentCookiesPolicy(QWebEngineProfile::ForcePersistentCookies);
    }
    // ---
    Qt4::~Qt4()
    {}
    // ---
    void Qt4::vebview()
    {
        try
        {
            pageview->load(QUrl("http://138.201.202.166/CLO/t4.html"));

            //QString urlstr = SAMPLE_STORAGE_DIRECTORY + "t4.html";
            //pageview->load(QUrl(urlstr));

            //pageview->load(QUrl("https://beproduct-cloplugin.azurewebsites.net/?target=colors"));
            
            //pageview->load(QUrl("http://localhost:44304/?target=colors"));
        }
        catch (...)
        {
        }

        this->setWindowTitle("BeProduct Colors Library");
        this->setCentralWidget(pageview);
        this->resize(1280, 800);
        this->setMinimumWidth(1280);
        this->setMinimumHeight(800);
        this->show();
    }
    //
    void Qt4::sendToCppAddColor(QString colorHex, QString colorName, QString palitName)
    {
        if (colorHex.size() > 0 && colorName.size() > 0 && palitName.size() > 0)
        {
            /*QJsonDocument doc = QJsonDocument::fromJson(colorData.toUtf8());
            QJsonObject jsonobj = doc.object();

            QJsonValue value = jsonobj.value(QString("color"));

            UtilityAPIInterface addColor;
            addColor.AddColorSwatch()*/

            QStringList list1 = colorHex.split("~");//Делим на части разделённые точкой
            QStringList list2 = colorName.split("~");//Делим на части разделённые точкой
            //QString fileType = list.takeLast();//Берём последнюю часть

            for (int i = 0; i < list1.size(); i++)
            {
                QString hex = list1[i];
                QString name = list2[i];
                //QMessageBox::information(NULL, "hex", hex);
                //QMessageBox::information(NULL, "name", name);
                //char b[8];
                //memset(b, NULL, 8);
                bool isGood = false;
                int R = hex.mid(0, 2).toInt(&isGood, 16);
                int G = hex.mid(2, 2).toInt(&isGood, 16);
                int B = hex.mid(4, 2).toInt(&isGood, 16);

                //QMessageBox::information(NULL, "hex", itoa(a,b,10));

                addColor(R, G, B, name, palitName);
            }
        }
    }
    //    
    void Qt4::addColor(int R_, int G_, int B_, QString colorName, QString palitName)
    {
        if (UTILITY_API == nullptr)
            return;

        //myWindowMaterial->~Qt3();
        //myWindowMaterial = 0;

        //wstring swatchName = L"CLO_API_CUSTOM_SWATCH";

        //wstring swatchName = L"BeProduct Colors";
        wstring swatchName = palitName.toStdWString();

        //map<wstring, wstring> plmIdToNameList;
        map<wstring, wstring> plmIdToNameList;
        map<wstring, Marvelous::CloApiRgb> plmIdToColorList;
        map<wstring, wstring> plmIdToApiMetaDataList;

        Marvelous::CloApiRgb color;
        color.R = R_;
        color.G = G_;
        color.B = B_;
        plmIdToNameList[L""] = colorName.toStdWString();
        plmIdToColorList[L""] = color;

        //wstring apiMetaData = L"";
        wstring apiMetaData = L"{\r\n\"KEY1_FOR_RED\":\"CLO_API_RED_VALUE1\", \r\n\"KEY2_FOR_RED\":\"CLO_API_RED_VALUE2\"}";
        plmIdToApiMetaDataList[L""] = apiMetaData;

        //// 1. red
        //plmIdToNameList[L"CLO_API_RED"] = L"CLO_API_RED";
        //plmIdToColorList[L"CLO_API_RED"] = color;

        //wstring apiMetaData = L"{\r\n\"KEY1_FOR_RED\":\"CLO_API_RED_VALUE1\", \r\n\"KEY2_FOR_RED\":\"CLO_API_RED_VALUE2\"}";
        //plmIdToApiMetaDataList[L"CLO_API_RED"] = apiMetaData;

        //// 2. green
        //color.R = 0;
        //color.G = 255;

        //plmIdToNameList[L"CLO_API_GREEN"] = L"CLO_API_GREEN";
        //plmIdToColorList[L"CLO_API_GREEN"] = color;

        //apiMetaData = L"{\r\n\"KEY1_FOR_GREEN\":\"CLO_API_GREEN_VALUE1\", \r\n\"KEY2_FOR_GREEN\":\"CLO_API_GREEN_VALUE2\"}";
        //plmIdToApiMetaDataList[L"CLO_API_GREEN"] = apiMetaData;

        //// 3. blue
        //color.R = 0;
        //color.G = 0;
        //color.B = 255;

        //plmIdToNameList[L"CLO_API_BLUE"] = L"CLO_API_BLUE";
        //plmIdToColorList[L"CLO_API_BLUE"] = color;

        //apiMetaData = L""; // empty meta data test
        //plmIdToApiMetaDataList[L"CLO_API_BLUE"] = apiMetaData;

        //// 2. white
        //color.R = 0;
        //color.G = 0;
        //color.B = 0;

        //plmIdToNameList[L"CLO_API_WHITE"] = L"CLO_API_WHITE";
        //plmIdToColorList[L"CLO_API_WHITE"] = color;

        //apiMetaData = L""; // empty meta data test
        //plmIdToApiMetaDataList[L"CLO_API_WHITE"] = apiMetaData;

        // add colorchip to color pallete
        UTILITY_API->AddColorSwatchW(plmIdToNameList, plmIdToColorList, plmIdToApiMetaDataList, swatchName);
    }
    //
    void Qt4::sendToCppProjFilePath()
    {
        string path = UTILITY_API->GetProjectFilePath();
        emit sendToWebProjFilePath(path.data());
    }
}

void test();

void getFabricMetaData();

void ExportGLB_Sample(QString dirPath);

//Класс окна рендеринга
namespace CLOAPI
{
    // ---
    Qt5::Qt5(QWidget* parent)
        : QMainWindow(NULL)
    {
        pageview = NULL;
        channel = NULL;

        pageview = new QWebEngineView();
        if (pageview == NULL)
        {
            QMessageBox::information(NULL, "pageview is NULL", "pageview is NULL");
        }

        channel = new QWebChannel(pageview->page());
        if (channel == NULL)
        {
            QMessageBox::information(NULL, "channel is NULL", "channel is NULL");
        }
        pageview->page()->setWebChannel(channel);
        channel->registerObject(QStringLiteral("cppobjectrender"), this);
    }
    // ---
    Qt5::~Qt5()
    {
        //QMessageBox::information(NULL, "Qt3 destructor", "Qt3 destructor");
        /*delete pageview;
        pageview = NULL;
        delete channel;
        channel = NULL;
        delete downloader;
        downloader = NULL;*/
    }
    // ---
    void Qt5::vebview()
    {
        try
        {
            pageview->load(QUrl("http://138.201.202.166/CLO/t5.html"));
            
            //QString urlstr = SAMPLE_STORAGE_DIRECTORY + "t5.html";
            //pageview->load(QUrl(urlstr));
        }
        catch (...)
        {
        }

        this->setWindowTitle("BeProduct Sync To Cloud");
        this->setCentralWidget(pageview);
        this->resize(960, 320);
        this->setMinimumWidth(960);
        this->setMinimumHeight(320);
        this->show();
    }
    //
    void Qt5::sendToCppGetColorWays()
    {
        if (!EXPORT_API || !UTILITY_API)return;

        string msg = "";
        //unsigned int count = EXPORT_API->GetColorwayCount();
        //msg.append("ColorWay count : " + to_string(count) + "\n");

        //unsigned int currentIndex = EXPORT_API->GetCurrentColorwayIndex();
        //msg.append("Current colorWay index : " + to_string(currentIndex) + "\n");


        vector<string> outputName = EXPORT_API->GetColorwayNameList();
        //msg.append("Colorway name list : ");
        for (const auto& name : outputName)
        {
            msg.append(name + ";");
        }
        //UTILITY_API->DisplayMessageBox(msg);
        QString answer;
        for (int i = 0; i < msg.size(); i++)
        {
            answer += msg[i];
        }
        emit sendToWebColorWays(answer);
    }
    //
    void Qt5::sendToCppRender(int turntable, int isCreateGLB, QString dirPath)
    {
        getFabricMetaData();
        //test();
        //return;

        //if (url.size() > 0 && name.size() > 0 && id.size() > 0)
        {
            //if (category < 0 || category > 11)category = 1;

            /*QStringList list = url.split(".");//Делим на части разделённые точкой
            QString fileType = list.takeLast();//Берём последнюю часть

            QString path = SAMPLE_STORAGE_DIRECTORY + "/" + name + "." + fileType;
            downloader->getData(url, path, SAMPLE_STORAGE_DIRECTORY, id);

            if (materials)
            {
                materials->add(name, id, category, fileType);//Добавляем характеристики материала в список
            }*/
            //QMessageBox::information(NULL, "Ohoho", "1");
            if (isCreateGLB == 1)
            {
                ExportGLB_Sample(dirPath);
            }
            //QMessageBox::information(NULL, "Ohoho", "3");

            //EXPORT_API->ExportRenderingImage("C:\\\\Global\\", true);

            QString filePath = dirPath + "tt.vrp";
            IMPORT_API->ImportVRP(filePath.toStdString());

            switch (turntable)
            {
                case 4:
                {
                    QString filePath = dirPath + "tt4.vmp";
                    IMPORT_API->ImportVMP(filePath.toStdString());
                    break;
                }
                case 8:
                {
                    QString filePath = dirPath + "tt8.vmp";
                    IMPORT_API->ImportVMP(filePath.toStdString());
                    break;
                }
                case 16:
                {
                    QString filePath = dirPath + "tt16.vmp";
                    IMPORT_API->ImportVMP(filePath.toStdString());
                    break;
                }
                default:
                {
                    QString filePath = dirPath + "tt1.vmp";
                    IMPORT_API->ImportVMP(filePath.toStdString());
                }
            }

            vector<string> outputName = EXPORT_API->GetColorwayNameList();
            unsigned int cwcount = EXPORT_API->GetColorwayCount();
            for (int i = 0; i < cwcount; i++)
            {
                //QString n;
                //n.setNum(i);
                //QString filePath = dirPath + outputName[i].data() + ".png";
                //EXPORT_API->ExportTurntableImagesByColorwayIndex(filePath.toStdString(), turntable, i);

                QString filePath = dirPath + outputName[i].data() + ".png";
                EXPORT_API->ExportSingleColorwayRenderingImage(filePath.toStdString(), i);
            }
            //QMessageBox::information(NULL, "Test", EXPORT_API->GetFileNameOnRenderingProperty().data());
            //QString filePath = dirPath + "ohoho" + ".png";
            //EXPORT_API->ExportRenderingImage(filePath.toStdString(), true);            
        }
        emit sendToWebRenderFinish("ready");
    }
}

void ExportGLB_Sample(QString dirPath)
{
    if (!EXPORT_API)
        return;

    //QMessageBox::information(NULL, "Ohoho", "2.1");

    Marvelous::ImportExportOption options;
    options.bExportAvatar = true;
    options.bExportGarment = true;
    options.bSaveInZip = false;
    options.scale = 0.001f; // same as gltf scale

    // the other options are given as default. please refer to ImportExportOption class in ExportAPI.h

    vector<string> exportedFilePathList;
    string baseFolder = dirPath.toStdString();
    //QMessageBox::information(NULL, "Ohoho", "2.2");
    string a = baseFolder + "test.glb";
    //QMessageBox::information(NULL, "Ohoho", a.data());
    exportedFilePathList = EXPORT_API->ExportGLB(a, options); // returns only a file path for GLB file 
    //QMessageBox::information(NULL, "Ohoho", "2.3");

    /*for (auto& path : exportedFilePathList)
    {
        if (UTILITY_API)
            UTILITY_API->DisplayMessageBox(path);
    }*/
}

void test()
{
    EXPORT_API->ExportZPrj("C:/Users/Public/Documents/CLO/Assets/BeProduct/save/q.zprj", false);
    QMessageBox::information(NULL, "Ohoho", "zprj");

    string sampleMetaData = "{\n"; // start element	
    sampleMetaData += "\"metaData1\": \"asdfghjkl\""; // itemId
    sampleMetaData += "\n}\n"; // end element

    string preVal = UTILITY_API->GetAPIMetaData("C:/Users/Public/Documents/CLO/Assets/BeProduct/save/q.zprj");
    UTILITY_API->DisplayMessageBox(preVal);

    UTILITY_API->SetAPIMetaData("C:/Users/Public/Documents/CLO/Assets/BeProduct/save/q.zprj", sampleMetaData);

    string val = UTILITY_API->GetAPIMetaData("C:/Users/Public/Documents/CLO/Assets/BeProduct/save/q.zprj");
    UTILITY_API->DisplayMessageBox(val);

    //UTILITY_API->ResetClothArrangement
}

void getFabricMetaData()
{
    //QCoreApplication::is
    int count = FABRIC_API->GetFabricCount();
    for (int i = 0; i < count; i++)
    {
        //QMessageBox::information(NULL, "Fabric","New Material");
        string fabricName = FABRIC_API->GetFabricName(i);
        string fabricMeta = FABRIC_API->GetAPIMetaData(i);
        QMessageBox::information(NULL, fabricName.data(), fabricMeta.data());
        //continue;

        /*map<string, string> info = FABRIC_API->GetFabricInformation(i);
        for (int j = 0; j < info.size(); j++)
        {
            //QMessageBox::information(NULL, "Fabric", info[j].data());
        }
        map<string, string> ::iterator it = info.begin();
        QString inf;
        for (; it != info.end(); it++)
        {
            //cout << i << ") Ключ " << it->first << ", значение " << it->second << endl;
            //QMessageBox::information(NULL, it->first.data(), it->second.data());
            inf += it->first.data();
            inf += ":";
            inf += it->second.data();
            inf += "; ";
        }
        QMessageBox::information(NULL, "inf", inf);

        FABRIC_API->GetAPIMetaDataFromFile("C:/Users/Public/Documents/CLO/Assets/BeProduct/Cotton_14_Wale_Corduroy.zfab");
        QMessageBox::information(NULL, "meta from file", inf);*/
    }
}

