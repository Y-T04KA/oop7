#pragma once
#include <QWidget>
#include <QPainter>
#include "Graph.h"

class GraphWidget : public QWidget
{
	Q_OBJECT

		//TSample* S;
		Graph duke;
public:
	GraphWidget(QWidget* parent = 0);
	GraphWidget(Graph,QWidget* parent = 0);
	void setGraph(const QStringList& data);
protected:
	void paintEvent(QPaintEvent*);
};

