#include <iostream>
#include "graph.h"

using namespace std;

int main(int argc, char* argv[])
{
    Graph g(7);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 4);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(5, 6);

    // g.print();
    cout << g << endl;

    cout << "DFS: ";
    g.dfs(0);
    cout << endl;

    cout << "DFS: " << endl;
    g.dfs(6);
    cout << endl;
    
    return 0;
}