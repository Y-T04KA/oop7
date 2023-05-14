#include "TInterface.h"

TInterface::TInterface(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    fileButton = new QPushButton("open file",this);
    fileButton->setGeometry(0, 0, 100, 50);
    connect(fileButton, SIGNAL(pressed()), this, SLOT(getFile()));
}

TInterface::~TInterface()
{}

void TInterface::getFile() {
    QMessageBox test;
    QFile file(QFileDialog::getOpenFileName(this, tr("Выберите файл")));
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QString data = QString::fromStdString(file.readAll().toStdString());
        if (fileValidaton(data)) {
            graphChore(data.split('\n'));
        }
    }
    else {
        test.setText("file error");
        test.exec();
    }
    file.close();
}

bool TInterface::fileValidaton(const QString& data) {
    QMessageBox errorBox;
    QStringList Points = data.split('\n');
    for (const auto& p : Points) {
        QStringList pl = p.split(',');
        if (pl.size() == Points.size()) {
            for (const auto& link : pl) {
                if (link != "1" && link != "0") {
                    errorBox.setText("значения в матрице могут быть либо 1 либо 0");
                    errorBox.exec();
                    return false;
                }
            }
        }
        else {
            errorBox.setText("mismatch");
            errorBox.exec();
            return false;
        }
    }
    return true;
}

void TInterface::graphChore(const QStringList& data) {
    Graph duke(data);
    //QMessageBox test;
    //test.setText(duke.show(1,1));
    //test.exec();
    gw = new GraphWidget(duke);
    gw->show();
}