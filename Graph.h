#pragma once
#include <QVector>

class Graph {
public:
    Graph();
    explicit Graph(const QStringList&);
    QString show(int, int);
    int size() const;
    qint16 get(int, int);
private:
    typedef QVector<qint16> Links;
    typedef QVector<Links> Points;
    Points G;
    size_t size_ = 0;
};

