//
// Created by kiril on 13.05.2023.
//

#ifndef OOP7_TINTERFACE_H
#define OOP7_TINTERFACE_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class TInterface; }
QT_END_NAMESPACE

class TInterface : public QMainWindow {
Q_OBJECT

public:
    explicit TInterface(QWidget *parent = nullptr);

    ~TInterface() override;
public slots:
    void getFile();

private:
    Ui::TInterface *ui;
    static bool fileValidaton(const QString&);
};


#endif //OOP7_TINTERFACE_H
