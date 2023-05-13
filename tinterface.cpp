//
// Created by kiril on 13.05.2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_TInterface.h" resolved

#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include "tinterface.h"
#include "ui_TInterface.h"


TInterface::TInterface(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::TInterface) {
    ui->setupUi(this);
}

void TInterface::getFile() {
    QMessageBox test;
    QFile file(QFileDialog::getOpenFileName(this,tr("Открыть текстовый файл")));
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QString data = QString::fromStdString(file.readAll().toStdString());
        if (fileValidaton(data)){
            //calling graph constructor
            test.setText("проверка пройдена");
            test.exec();
        };
    } else {
        test.setText("file error");
        test.exec();
    }
    file.close();
}

bool TInterface::fileValidaton(const QString& data) {
    QMessageBox errorBox;
    QStringList Points = data.split('\n');
    for (const auto& p: Points){
        QStringList pl = p.split(',');
        if (pl.size() == Points.size()){
            /// if ok
            for (const auto& link: pl){
                if (link != "1" && link != "0"){
                    errorBox.setText("связь может быть либо 1 (есть), либо 0 (нет)");
                    errorBox.exec();
                    return false;
                }
            }
        } else {
            errorBox.setText("где-то не сходится число связей с количеством точек");
            errorBox.exec();
            return false;
        }
    }
    return true;
};

TInterface::~TInterface() {
    delete ui;
}
