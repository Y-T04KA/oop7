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
    QFile file(QFileDialog::getOpenFileName(this,tr("Открыть текстовый файл"), "~"));
    test.setText(file.fileName());
    test.exec();
}

TInterface::~TInterface() {
    delete ui;
}
