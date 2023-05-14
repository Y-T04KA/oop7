#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TInterface.h"
#include <QPushButton>
#include <qmessagebox.h>
#include <QFile>
#include <QFileDialog>
#include "Graph.h"
#include "GraphWidget.h"

class TInterface : public QMainWindow
{
    Q_OBJECT

        

public:
    TInterface(QWidget *parent = nullptr);
    QPushButton* fileButton;
    GraphWidget* gw;
    ~TInterface();
public slots:
    void getFile();
private:
    Ui::TInterfaceClass ui;
    static bool fileValidaton(const QString&);
    void graphChore(const QStringList&);
};
