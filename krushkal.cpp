#include <iostream>
#include <climits>
using namespace std;

int findSet(int v, int parent[10]) {
    if (parent[v] == 0)
        return v;
    return findSet(parent[v], parent); // Recursively find the root parent
}

void unionSet(int u, int v, int parent[10]) {
    int rootU = findSet(u, parent);
    int rootV = findSet(v, parent);
    parent[rootV] = rootU; // Merge the sets containing vertices u and v
}

int main() {
    int n, min, cost[10][10], edge = 0, a, b;
    int parent[10] = {0};

    cout << "Enter the number of vertices: ";
    cin >> n;

    cout << "Enter the adjacency matrix of the graph: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "G[" << i << "][" << j << "]: ";
            cin >> cost[i][j];
        }
    }

    cout << "Source \t \t Destination" << endl;
    while (edge < n - 1) {
        min = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (cost[i][j] < min) {
                    // Update minimum edge only when a smaller edge weight is found
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        int u = findSet(a, parent);
        int v = findSet(b, parent);
        if (u != v) {
            cout << a << "\t \t" << b << endl;
            unionSet(u, v, parent);
            edge++;
        }
        cost[a][b] = INT_MAX; // Mark the selected edge as visited
        cost[b][a] = INT_MAX;
    }
    return 0;
}
