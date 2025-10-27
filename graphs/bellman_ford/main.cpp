#include <iostream>
#include "graph.h"

using namespace std;

int main(int argc, char* argv[])
{
    Graph g(8);

    g.addEdge(0, 1, 10);
    g.addEdge(0, 7, 8);
    g.addEdge(7, 6, 1);
    g.addEdge(6, 5, -1);
    g.addEdge(6, 1, -4);
    g.addEdge(1, 5, 2);
    g.addEdge(2, 1, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 3);
    g.addEdge(4, 5, -1);
    g.addEdge(5, 2, -2);

    cout << g << endl;
    g.dfs(0);
    cout << endl;

    g.bf(0);

    return 0;
}