#include "Graph.h"

Graph::Graph(const QStringList& rows) {
    G.clear();
    for (const auto& row : rows) {
        //Links linkRow(rows.size());
        Links linkRow;
        QStringList col = row.split(',');
        for (const auto& symbol : col) {
            linkRow.push_back(symbol.toShort());
        }
        G.push_back(linkRow);
    }
}

Graph::Graph() {
    G.clear(); //maybe such constructor shouldn't exist at all
}

QString Graph::show(int x, int y) {
    auto e = G[x][y];
    auto q = QString::number(e);
    return q;
}

int Graph::size() const {
    return G.size();
}

qint16 Graph::get(int x, int y) {
    return G[x][y];
}