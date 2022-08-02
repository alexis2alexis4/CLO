/********************************************************************************
** Form generated from reading UI file 'APISignInDialogSample.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APISIGNINDIALOGSAMPLE_H
#define UI_APISIGNINDIALOGSAMPLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogSignIn
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit_ID;
    QLabel *label_2;
    QLineEdit *lineEdit_Passwd;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacerForButton;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *DialogSignIn)
    {
        if (DialogSignIn->objectName().isEmpty())
            DialogSignIn->setObjectName(QString::fromUtf8("DialogSignIn"));
        DialogSignIn->resize(268, 137);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DialogSignIn->sizePolicy().hasHeightForWidth());
        DialogSignIn->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(DialogSignIn);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame = new QFrame(DialogSignIn);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_ID = new QLineEdit(frame);
        lineEdit_ID->setObjectName(QString::fromUtf8("lineEdit_ID"));

        gridLayout->addWidget(lineEdit_ID, 0, 1, 1, 1);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit_Passwd = new QLineEdit(frame);
        lineEdit_Passwd->setObjectName(QString::fromUtf8("lineEdit_Passwd"));

        gridLayout->addWidget(lineEdit_Passwd, 1, 1, 1, 1);


        verticalLayout->addWidget(frame);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacerForButton = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacerForButton);

        okButton = new QPushButton(DialogSignIn);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setMinimumSize(QSize(73, 29));
        okButton->setMaximumSize(QSize(16777215, 29));

        horizontalLayout->addWidget(okButton);

        cancelButton = new QPushButton(DialogSignIn);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setMinimumSize(QSize(73, 29));
        cancelButton->setMaximumSize(QSize(16777215, 29));

        horizontalLayout->addWidget(cancelButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(DialogSignIn);

        QMetaObject::connectSlotsByName(DialogSignIn);
    } // setupUi

    void retranslateUi(QDialog *DialogSignIn)
    {
        DialogSignIn->setWindowTitle(QCoreApplication::translate("DialogSignIn", "SignIn", nullptr));
        label->setText(QCoreApplication::translate("DialogSignIn", "Email", nullptr));
        label_2->setText(QCoreApplication::translate("DialogSignIn", "Password", nullptr));
        okButton->setText(QCoreApplication::translate("DialogSignIn", "OK", nullptr));
        cancelButton->setText(QCoreApplication::translate("DialogSignIn", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogSignIn: public Ui_DialogSignIn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APISIGNINDIALOGSAMPLE_H
