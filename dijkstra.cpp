#include <iostream>
#include <limits.h>
using namespace std;
int min_vertex(int distance[], int no_of_vertices, bool visited[20])
{
	int min_v = INT_MAX, min_index;
	for (int i = 0; i < no_of_vertices; i++)
	{
		if (distance[i] < min_v && visited[i] == false)
		{
			min_v = distance[i];
			min_index = i;
		}
	}
	return min_index;
}
void dijkstra(int graph[20][20], int no_of_vertices, int source)
{
	int distance[no_of_vertices];
	bool visited[no_of_vertices];
	for (int i = 0; i < no_of_vertices; i++)
	{
		distance[i] = INT_MAX;
		visited[i] = false;
	}
	distance[source] = 0;
	for (int i = 0; i < no_of_vertices - 1; i++)
	{
		int u = min_vertex(distance, no_of_vertices, visited);
		visited[u] = true;
		for (int v = 0; v < no_of_vertices; v++)
		{
			if (!visited[v] && graph[u][v] && distance[v] > distance[u] + graph[u][v])
			{
				distance[v] = distance[u] + graph[u][v];
			}
		}
	}
	for (int i = 0; i < no_of_vertices; i++)
	{
		cout << "Distance from " << source << " to " << i << " is " << distance[i] << endl;
	}
}
int main()
{
	int no_of_vertices, source;
	cout << "Enter the number of vertices : ";
	cin >> no_of_vertices;
	int graph[20][20];
	cout << "Enter the adjacency matrix of the graph" << endl;
	for (int i = 0; i < no_of_vertices; i++)
	{
		for (int j = 0; j < no_of_vertices; j++)
		{
			cout << "G[" << i << "][" << j << "] : ";
			cin >> graph[i][j];
		}
	}
	cout << endl
		 << "Enter the source vertex: ";
	cin >> source;
	dijkstra(graph, no_of_vertices, source);
	return 0;
}
