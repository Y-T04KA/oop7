#include "GraphWidget.h"
#include <QRandomGenerator>

GraphWidget::GraphWidget(QWidget* parent)
{
	setFixedSize(400, 400);
}

GraphWidget::GraphWidget(Graph d, QWidget* parent)
{
    setFixedSize(400, 400);
    duke = d;
}

void GraphWidget::setGraph(const QStringList& data) {
    duke = Graph(data);
}

void GraphWidget::paintEvent(QPaintEvent*) {
    /*QPainter painter(this);
    painter.setPen(Qt::black);
    painter.setBrush(Qt::white);
    int nodeRadius = 50;
    int nodeDiameter = 2 * nodeRadius;
    for (int i = 0; i < duke.size(); i++) {
        for (int j = 0; j < duke.size(); j++) {
            if (duke.get(i, j) == 1) {
                painter.drawLine(QPoint(i * nodeDiameter + nodeRadius, j * nodeDiameter + nodeRadius),
                    QPoint(j * nodeDiameter + nodeRadius, i * nodeDiameter + nodeRadius));
            }
        }
    }
    painter.setBrush(Qt::red);
    for (int i = 0; i < duke.size(); i++) {
        painter.drawEllipse(QPoint(i * nodeDiameter + nodeRadius, i * nodeDiameter + nodeRadius), nodeRadius, nodeRadius);
        QString nodeLabel = QString::number(i);
        int labelWidth = painter.fontMetrics().horizontalAdvance(nodeLabel);
        int labelHeight = painter.fontMetrics().height();
        painter.drawText(QPoint(i * nodeDiameter + nodeRadius - labelWidth / 2, i * nodeDiameter + nodeRadius + labelHeight / 2), nodeLabel);
    }*/

    /*QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing); // For smoother lines

    int margin = 20; // Margin size for window borders
    int width = this->width() - 2 * margin;
    int height = this->height() - 2 * margin;

    painter.translate(margin, margin); // Move origin to margin position

    int vertexCount = duke.size();

    // Draw the edges between vertices
    for (int i = 0; i < vertexCount; i++) {
        for (int j = i + 1; j < vertexCount; j++) {
            if (duke.get(i,j) != 0) {
                // Draw an edge between vertices i and j
                int x1 = i * width / vertexCount + width / (2 * vertexCount) + QRandomGenerator::generate() % 50 - 25;
                int y1 = i * height / vertexCount + height / (2 * vertexCount) + qrand() % 50 - 25;
                int x2 = j * width / vertexCount + width / (2 * vertexCount) + qrand() % 50 - 25;
                int y2 = j * height / vertexCount + height / (2 * vertexCount) + qrand() % 50 - 25;
                painter.drawLine(x1, y1, x2, y2);
            }
        }
    }

    // Draw the vertices as circles
    for (int i = 0; i < vertexCount; i++) {
        int x = i * width / vertexCount + width / (2 * vertexCount) + qrand() % 50 - 25;
        int y = i * height / vertexCount + height / (2 * vertexCount) + qrand() % 50 - 25;
        painter.drawEllipse(x - 10, y - 10, 20, 20); // Draw circle with radius 10
    }*/
    QPainter painter(this);
    size_t height = duke.size();
    QPoint center(200, 200);
    if (height == 0)
    {
        return;
    }
    painter.setBrush(Qt::white);
    painter.setPen(Qt::black);

    double degree = 2 * 3.14 / height;

    int radius = 100;
    int size_node = 20;

    auto point = QPoint(0, -radius);

    for (size_t i = 0; i < height; i++)
    {
        auto a_cos = cos(degree * i);
        auto a_sin = sin(degree * i);
        auto d_point = QPoint(point.x() * a_cos - point.y() * a_sin, point.x() * a_sin + point.y() * a_cos);
        painter.drawEllipse(center + d_point, size_node, size_node);
        painter.drawText(center + d_point + QPoint(-2, 4), QString::number(i + 1));
    }
    painter.setPen(Qt::black);
    painter.setBrush(Qt::black);
    point = QPoint(0, -radius);
    for (size_t i = 0; i < height; i++)
    {
        for (size_t j = 0; j < height; j++)
        {
            if (duke.get(i,j) != 0) 
            {
                auto a_cos = cos(degree * i);
                auto a_sin = sin(degree * i);
                auto first = center + QPoint(point.x() * a_cos - point.y() * a_sin, point.x() * a_sin + point.y() * a_cos);
                a_cos = cos(degree * j);
                a_sin = sin(degree * j);
                auto second = center + QPoint(point.x() * a_cos - point.y() * a_sin, point.x() * a_sin + point.y() * a_cos);
                double dx = second.x() - first.x();
                double dy = second.y() - first.y();
                double angle = atan2(dy, dx);
                int size_arrow = 10;
                QPointF p2(second.x() - (size_node + size_arrow) * cos(angle), second.y() - (size_node + size_arrow) * sin(angle));
                QPointF p1(first.x() + size_node * cos(angle), first.y() + size_node * sin(angle));

                painter.drawLine(p1, p2);

                if (i == j)
                {
                    painter.save();
                    painter.translate(p2);
                    painter.rotate(180 / 3.14159 * angle);
                    painter.drawLine(QPoint(0, -size_arrow / 2), QPoint(size_arrow, 0));
                    painter.drawLine(QPoint(size_arrow, 0), QPoint(0, size_arrow / 2));
                    painter.restore();
                }
                else
                {
                    painter.save();
                    painter.translate(p2);
                    painter.rotate(180 / 3.14159 * angle);
                    painter.drawLine(QPoint(0, -size_arrow / 2), QPoint(size_arrow, 0));
                    painter.drawLine(QPoint(size_arrow, 0), QPoint(0, size_arrow / 2));
                    painter.restore();
                }
            }
        }
    }
}
