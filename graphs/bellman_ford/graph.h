#pragma once
#include <vector>
#include <iostream>
#include <cmath>
#include <limits>

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
                if(!_visited.at(i) && _adjMatrix[v][i] != 0) explore(i);
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
        void addEdge(int u, int v, int w)
        {
            //find the index first
            //set the edge value to those indexes
            _adjMatrix.at(u).at(v) = w;
            // _adjMatrix[u][v] = 1;
            // _adjMatrix.at(v).at(u) = w;
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

        void bf(int s)
        {
            vector<int> d(_visited.size(), 1000000);

            d.at(s) = 0;
            // for(size_t i = 0; i < d.size(); i++)
            while(true)
            {
                bool updated = false;
                for(size_t row = 0; row < d.size(); row++)
                {
                    for(size_t col = 0; col < d.size(); col++)
                    {
                        if(_adjMatrix.at(row).at(col) != 0)
                        {
                            // if(!isinf(d.at(row)))
                            // cout << d.at(row) << endl;
                            // if(d.at(row) < numeric_limits<int>::infinity())
                            if(d.at(row) < 1000000)
                            {
                                // cout << d.at(row) << ", " << d.at(col) + _adjMatrix.at(row).at(col) << endl;
                                //  d[1]  =        inf         0     +          10
                                //  d[7]  =        inf         0     +          8
                                d.at(col) = min(d.at(col), d.at(row) + _adjMatrix.at(row).at(col));
                                updated = true;
                            }
                        }
                    }
                    if(!updated) break;
                    // cout << "next row" << endl;
                }
            }
            for(auto n : d)
            {
                cout << n << " ";
            }
            cout << endl;
        }
};
