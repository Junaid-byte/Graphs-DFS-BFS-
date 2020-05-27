#include<iostream>
#include<conio.h>
#include<list>
#include<stdbool.h>

#define MAX 6

using namespace std;

struct Vertex
{
	char label;
	bool visited;
};

int Queue[MAX];
int rear = -1;
int front = 0;
int queueCount = 0;

struct Vertex* Vertices[MAX];

int AdjacencyMatrix[MAX][MAX];
int vertexCount = 0;

void Insert(int data)
{
	Queue[++rear] = data;
	queueCount++;
}
int Remove()
{
	queueCount--;
	return Queue[front++];
}

bool isQueueEmpty()
{
	return queueCount == 0;
}

void AddVertex(char label)
{
	struct Vertex* vertex = (struct Vertex*) malloc(sizeof(struct Vertex));
	vertex->label = label;
	vertex->visited = false;
	Vertices[vertexCount++] = vertex;

}
void addEdge(int start, int end) 
{
	AdjacencyMatrix[start][end] = 1;
	AdjacencyMatrix[end][start] = 1;
}
void Display(int vertexIndex)
{
	cout << Vertices[vertexIndex]->label;
}

int getAdjUnvisitedVertex(int vertexIndex) 
{
	int i;
	for (i = 0; i < vertexCount; i++) 
	{
		if (AdjacencyMatrix[vertexIndex][i] == 1 && Vertices[i]->visited == false)
		{
			return i;
		}
	}

	return -1;
}
void BreadthFirstSearch() 
{
	int i;

	Vertices[0]->visited = true;

	Display(0);

	Insert(0);
	int unvisitedVertex;

	while (!isQueueEmpty()) 
	{
		int tempVertex = Remove();

		while ((unvisitedVertex = getAdjUnvisitedVertex(tempVertex)) != -1)
		{
			Vertices[unvisitedVertex]->visited = true;
			Display(unvisitedVertex);
			Insert(unvisitedVertex);
		}

	}

	for (i = 0; i < vertexCount; i++) 
	{
		Vertices[i]->visited = false;
	}
}

int main()
{
	int x, y;

	for (x = 0; x < MAX; x++)
	{
		for (y = 0; y < MAX; y++)
		{
			AdjacencyMatrix[x][y] = 0;
		}
	}


	addEdge(0, 1);    // S - A
	addEdge(0, 2);    // S - B
	addEdge(1, 2);    // S - C
	addEdge(2, 0);    // A - D
	addEdge(2, 3);    // B - D
	addEdge(3, 3);    // C - D



	cout << "Following is Breadth First Traversal (starting from vertex 2) :- ";
	BreadthFirstSearch();

	_getch();
	return 0;
}


