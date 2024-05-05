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
void prims_algo(int graph[20][20], int no_of_vertices)
{
	bool visited[no_of_vertices];
	int parent[no_of_vertices], distance[no_of_vertices];
	for (int i = 0; i < no_of_vertices; i++)
	{
		distance[i] = INT_MAX;
		visited[i] = false;
	}
	distance[0] = 0;
	parent[0] = -1;
	for (int i = 0; i < no_of_vertices - 1; i++)
	{
		int u = min_vertex(distance, no_of_vertices, visited);
		visited[u] = true;
		for (int v = 0; v < no_of_vertices; v++)
		{
			if (!visited[v] && graph[u][v] && distance[v] > graph[u][v])
			{
				parent[v] = u;
				distance[v] = graph[u][v];
			}
		}
	}
	cout << "Source\t"
		 << "Destination\t"
		 << "Distance" << endl;
	for (int i = 0; i < no_of_vertices; i++)
	{
		cout << parent[i] << "\t" << i << "\t" << graph[i][parent[i]] << endl;
	}
}
int main()
{
	int no_of_vertices;
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
	prims_algo(graph, no_of_vertices);
	return 0;
}
