/********************************************************************************
** Form generated from reading UI file 'PLMSettingsSample.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLMSETTINGSSAMPLE_H
#define UI_PLMSETTINGSSAMPLE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PLMSettings
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *hLayout_PLMServerURL;
    QLabel *labelURL_8;
    QSpacerItem *horizontalSpacer_8;
    QLineEdit *lineEdit_PLMServerURL;
    QHBoxLayout *hLayoutProtocol;
    QLabel *labelURL_9;
    QSpacerItem *horizontalSpacer_9;
    QComboBox *comboBox_Protocol;
    QHBoxLayout *hLayout_EndPoint;
    QLabel *labelURL_6;
    QSpacerItem *horizontalSpacer_6;
    QLineEdit *lineEdit_EndPoint;
    QHBoxLayout *hLayout_ConfigurationFile;
    QLabel *labelURL_5;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *lineEdit_ConfigurationFile;
    QPushButton *pbOpen;
    QPushButton *pbRefresh;

    void setupUi(QWidget *PLMSettings)
    {
        if (PLMSettings->objectName().isEmpty())
            PLMSettings->setObjectName(QString::fromUtf8("PLMSettings"));
        PLMSettings->resize(496, 127);
        gridLayout = new QGridLayout(PLMSettings);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        hLayout_PLMServerURL = new QHBoxLayout();
        hLayout_PLMServerURL->setSpacing(0);
        hLayout_PLMServerURL->setObjectName(QString::fromUtf8("hLayout_PLMServerURL"));
        labelURL_8 = new QLabel(PLMSettings);
        labelURL_8->setObjectName(QString::fromUtf8("labelURL_8"));

        hLayout_PLMServerURL->addWidget(labelURL_8);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hLayout_PLMServerURL->addItem(horizontalSpacer_8);

        lineEdit_PLMServerURL = new QLineEdit(PLMSettings);
        lineEdit_PLMServerURL->setObjectName(QString::fromUtf8("lineEdit_PLMServerURL"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_PLMServerURL->sizePolicy().hasHeightForWidth());
        lineEdit_PLMServerURL->setSizePolicy(sizePolicy);
        lineEdit_PLMServerURL->setMinimumSize(QSize(300, 20));
        lineEdit_PLMServerURL->setMaximumSize(QSize(300, 20));

        hLayout_PLMServerURL->addWidget(lineEdit_PLMServerURL);


        gridLayout->addLayout(hLayout_PLMServerURL, 0, 0, 1, 1);

        hLayoutProtocol = new QHBoxLayout();
        hLayoutProtocol->setSpacing(0);
        hLayoutProtocol->setObjectName(QString::fromUtf8("hLayoutProtocol"));
        labelURL_9 = new QLabel(PLMSettings);
        labelURL_9->setObjectName(QString::fromUtf8("labelURL_9"));

        hLayoutProtocol->addWidget(labelURL_9);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hLayoutProtocol->addItem(horizontalSpacer_9);

        comboBox_Protocol = new QComboBox(PLMSettings);
        comboBox_Protocol->addItem(QString());
        comboBox_Protocol->addItem(QString());
        comboBox_Protocol->addItem(QString());
        comboBox_Protocol->setObjectName(QString::fromUtf8("comboBox_Protocol"));
        sizePolicy.setHeightForWidth(comboBox_Protocol->sizePolicy().hasHeightForWidth());
        comboBox_Protocol->setSizePolicy(sizePolicy);
        comboBox_Protocol->setMinimumSize(QSize(300, 20));
        comboBox_Protocol->setMaximumSize(QSize(300, 20));

        hLayoutProtocol->addWidget(comboBox_Protocol);


        gridLayout->addLayout(hLayoutProtocol, 1, 0, 1, 1);

        hLayout_EndPoint = new QHBoxLayout();
        hLayout_EndPoint->setSpacing(0);
        hLayout_EndPoint->setObjectName(QString::fromUtf8("hLayout_EndPoint"));
        labelURL_6 = new QLabel(PLMSettings);
        labelURL_6->setObjectName(QString::fromUtf8("labelURL_6"));

        hLayout_EndPoint->addWidget(labelURL_6);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hLayout_EndPoint->addItem(horizontalSpacer_6);

        lineEdit_EndPoint = new QLineEdit(PLMSettings);
        lineEdit_EndPoint->setObjectName(QString::fromUtf8("lineEdit_EndPoint"));
        sizePolicy.setHeightForWidth(lineEdit_EndPoint->sizePolicy().hasHeightForWidth());
        lineEdit_EndPoint->setSizePolicy(sizePolicy);
        lineEdit_EndPoint->setMinimumSize(QSize(300, 20));
        lineEdit_EndPoint->setMaximumSize(QSize(300, 20));

        hLayout_EndPoint->addWidget(lineEdit_EndPoint);


        gridLayout->addLayout(hLayout_EndPoint, 2, 0, 1, 1);

        hLayout_ConfigurationFile = new QHBoxLayout();
        hLayout_ConfigurationFile->setSpacing(0);
        hLayout_ConfigurationFile->setObjectName(QString::fromUtf8("hLayout_ConfigurationFile"));
        labelURL_5 = new QLabel(PLMSettings);
        labelURL_5->setObjectName(QString::fromUtf8("labelURL_5"));

        hLayout_ConfigurationFile->addWidget(labelURL_5);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hLayout_ConfigurationFile->addItem(horizontalSpacer_5);

        lineEdit_ConfigurationFile = new QLineEdit(PLMSettings);
        lineEdit_ConfigurationFile->setObjectName(QString::fromUtf8("lineEdit_ConfigurationFile"));
        sizePolicy.setHeightForWidth(lineEdit_ConfigurationFile->sizePolicy().hasHeightForWidth());
        lineEdit_ConfigurationFile->setSizePolicy(sizePolicy);
        lineEdit_ConfigurationFile->setMinimumSize(QSize(262, 20));
        lineEdit_ConfigurationFile->setMaximumSize(QSize(270, 20));

        hLayout_ConfigurationFile->addWidget(lineEdit_ConfigurationFile);

        pbOpen = new QPushButton(PLMSettings);
        pbOpen->setObjectName(QString::fromUtf8("pbOpen"));
        sizePolicy.setHeightForWidth(pbOpen->sizePolicy().hasHeightForWidth());
        pbOpen->setSizePolicy(sizePolicy);
        pbOpen->setMinimumSize(QSize(19, 19));
        pbOpen->setMaximumSize(QSize(19, 19));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Resources/btn_icon_open_none.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pbOpen->setIcon(icon);

        hLayout_ConfigurationFile->addWidget(pbOpen);

        pbRefresh = new QPushButton(PLMSettings);
        pbRefresh->setObjectName(QString::fromUtf8("pbRefresh"));
        sizePolicy.setHeightForWidth(pbRefresh->sizePolicy().hasHeightForWidth());
        pbRefresh->setSizePolicy(sizePolicy);
        pbRefresh->setMinimumSize(QSize(19, 19));
        pbRefresh->setMaximumSize(QSize(19, 19));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Resources/btn_icon_refresh_none.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pbRefresh->setIcon(icon1);

        hLayout_ConfigurationFile->addWidget(pbRefresh);


        gridLayout->addLayout(hLayout_ConfigurationFile, 3, 0, 1, 1);


        retranslateUi(PLMSettings);

        QMetaObject::connectSlotsByName(PLMSettings);
    } // setupUi

    void retranslateUi(QWidget *PLMSettings)
    {
        PLMSettings->setWindowTitle(QCoreApplication::translate("PLMSettings", "Form", nullptr));
        labelURL_8->setText(QCoreApplication::translate("PLMSettings", "PLM Server URL", nullptr));
        labelURL_9->setText(QCoreApplication::translate("PLMSettings", "Protocol", nullptr));
        comboBox_Protocol->setItemText(0, QCoreApplication::translate("PLMSettings", "https", nullptr));
        comboBox_Protocol->setItemText(1, QCoreApplication::translate("PLMSettings", "http", nullptr));
        comboBox_Protocol->setItemText(2, QCoreApplication::translate("PLMSettings", "ssh", nullptr));

        labelURL_6->setText(QCoreApplication::translate("PLMSettings", "End Point", nullptr));
        labelURL_5->setText(QCoreApplication::translate("PLMSettings", "Configuration File", nullptr));
        pbOpen->setText(QString());
        pbRefresh->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PLMSettings: public Ui_PLMSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLMSETTINGSSAMPLE_H
