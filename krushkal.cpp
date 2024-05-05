#include <iostream>
#include <limits.h>
using namespace std;
int findSet(int v, int parent[10])
{
    while (parent[v] != 0)
    {
        v = parent[v];
    }
    return v;
}
int unionSet(int u, int v, int parent[10])
{
    while (u != v)
    {
        parent[v] = u;
        return 1;
    }
    return 0;
}
int main()
{
    int n, min, cost[10][10], edge = 1, u, v, a, b, parent[10] = {0};
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the adjacency matrix of the graph" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "G[" << i << "][" << j << "] : ";
            cin >> cost[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (cost[i][j] == 0)
            {
                cost[i][j] = INT_MAX;
            }
        }
    }
    cout << "Source \t\t"
         << "Destination";
    while (edge < n)
    {
        min = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = i;
                    u = i;
                    b = j;
                    v = j;
                }
            }
        }
        u = findSet(u, parent);
        v = findSet(v, parent);
        if (unionSet(u, v, parent) != 0)
        {
            cout << a << "\t\t" << b << endl;
        }
        cost[a][b] = INT_MAX;
        cost[b][a] = INT_MAX;
        edge++;
    }
    return 0;
}
