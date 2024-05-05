#include<iostream>
using namespace std;

void floydWarshall(int distance[][20], int n)
{
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(distance[i][j] == 0)
			{
				distance[i][j]=INT_MAX;		
			}	
			if(i==j)
			{
				distance[i][j] = 0;
			}
		}
	}
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if((distance[i][j] > (distance[i][k] +distance[k][j])) && distance[i][k]!=INT_MAX && distance[k][j]!=INT_MAX)
				{
					distance[i][j] = distance[i][k] + distance[k][j];
				}
			}
		}
	}
	
}

int main()
{
	int no_of_vertices, source;
	cout<<"Enter the number of vertices : ";
	cin>>no_of_vertices;
	int graph[20][20];
	cout<<"Enter the adjacency matrix of the graph"<<endl;
	for(int i=0;i<no_of_vertices;i++)
	{
		for(int j=0;j<no_of_vertices;j++)
		{
			cin>>graph[i][j];
		}
	}
	floydWarshall(graph,no_of_vertices);
	for(int i=0;i<no_of_vertices;i++)
	{
		for(int j=0;j<no_of_vertices;j++)
		{
			cout<<graph[i][j]<<"  ";
		}
		cout<<endl;
	}
	return 0;
}
