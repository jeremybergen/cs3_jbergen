#pragma once
#include <vector>
#include <iostream>

using namespace std;

class Graph
{
    private:
        // vector< object > _verticies;
        vector< vector< int > > _adjMatrix;
        vector< bool > _visited;
        // int* _adjMatrix2;

        void explore(int v)
        {
            // visited(v) = true
            // previsit(v)
            // for each edge (v, u) ∈ E:
            // if not visited(u): explore(u)
            // postvisit(v)
            // cout << "DEBUG: v: " << v << endl;
            _visited.at(v) = true;
            cout << v << " ";
            //previsit(v);
            for(size_t i = 0; i < _adjMatrix.size(); i++)
            {
                if(!_visited.at(i) && _adjMatrix[v][i] == 1) explore(i);
            }
            //postvisit(v);
        }
    public:
        Graph(int n)
        {
            // _adjMatrix2 = new int[n*n];
            _adjMatrix = vector< vector< int > >(n, vector< int >(n, 0));
            _visited = vector< bool >(n, false);
        }
        void addEdge(int u, int v)
        {
            //find the index first
            //set the edge value to those indexes
            _adjMatrix.at(u).at(v) = 1;
            // _adjMatrix[u][v] = 1;
            _adjMatrix.at(v).at(u) = 1;
            // _adjMatrix[v][u] = 1;
        }
        // void print()
        // Graph operator+(const Graph rhs)
        // {
        //     //do something to add
        //     // this + rhs
        //     return newGraph;
        // }
        friend ostream& operator<<(ostream& os, const Graph& g)
        {
            for(auto row : g._adjMatrix)
            {
                for(auto col : row)
                {
                    os << col << " ";
                }
                os << endl;
            }
            return os;
        }

        void dfs(int v)
        {
            _visited.clear();
            _visited = vector<bool>(_adjMatrix.size(), false);

            explore(v);
            for(size_t i = 0; i < _visited.size(); i++)
            {
                // cout << "DEBUG: i: " << i << endl;
                
                if(!_visited.at(i)) 
                {
                    cout << endl << "new unconnected graph: ";
                    explore(i);
                }
            }
        }
};
