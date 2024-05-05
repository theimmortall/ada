#include <iostream>
using namespace std;



int minDistance(int dist[], bool sptSet[], int V)
{
	
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}


void printSolution(int dist[],int V)
{
	printf("Vertex Distance from Source\n");
	for (int i = 0; i < V; i++)
		printf("\t%d \t\t\t\t %d\n", i, dist[i]);
}

void dijkstra(int graph[20][20], int src, int V)
{
	int dist[V]; 

	bool sptSet[V]; 
	
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	
	dist[src] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < V - 1; count++) {
		
		int u = minDistance(dist, sptSet, V);

		
		sptSet[u] = true;

		
		for (int v = 0; v < V; v++)
			if (!sptSet[v] && graph[u][v]
				&& dist[u] != INT_MAX
				&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}

	
	printSolution(dist, V);
}


int main()
{

	int V;
    cout<<"Enter the number of vertices:";
    cin>>V;
    int graph[20][20];
    cout<<"Enter the adjacency matrix of the graph"<<endl;
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cout<<"G["<<i<<","<<j<<"]";
            cin>>graph[i][j];
        }
    }
    dijkstra(graph,0,V);
}
