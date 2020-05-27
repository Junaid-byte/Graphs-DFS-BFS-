#include<iostream>
#include<conio.h>
#include<string>
#include<vector>
#include<bits1_5.h>

using namespace std;


void Insert(vector<int> adj[], int x, int y)
{
	adj[x].push_back(y);
	adj[y].push_back(x);
}

void Delete(vector<int> adj[], int x, int y)
{
	for (int i = 0; i < adj[x].size();i++)
	{
		if(adj[x][i] == y)
		{
			adj[x].erase(adj[x].begin() + i);
			break;
		}

	}
	for (int i = 0; i < adj[y].size();i++)
	{
		if (adj[y][i] == x)
		{
			adj[y].erase(adj[y].begin() + i);
			break;
		}
	}
}

void Display(vector<int> adj[], int vertex)
{
	for (int v = 0; v < vertex; ++v)
	{
		cout << "Vertex:- " << v << " ";
		for (auto x : adj[v])
		{
			cout << "-> " << x;
		}
		cout << endl;
	}
	cout << endl;

}

int main()
{
	int vertex=5;
	vector<int> adj[5];

	cout << "Inserting edges:- " << endl<<endl;
	Insert(adj, 0, 1);
	Insert(adj, 0, 4);
	Insert(adj, 1, 2);
	Insert(adj, 1, 3);
	Insert(adj, 1, 4);
	Insert(adj, 2, 3);
	Insert(adj, 3, 4);

	Display(adj, vertex);

	cout << "After Deleting 1 & 4 edges from vertex 1 & 4:- " << endl;
	Delete(adj, 1, 4);
	cout << endl;
	Display(adj, vertex);
		
	_getch();
	return 0;

}