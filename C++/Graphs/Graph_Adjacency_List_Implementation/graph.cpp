// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <queue>
#include <list>
using namespace std;

class Node{
public:
	int data;
	bool visisted = false;
	Node* next;

	Node() {

		data = 0;
		next = NULL;
	}
	Node(int x) {

		data = x;
		next = NULL;
	}

	void destroyList() {

		Node* current = this;

		/*while (current!= NULL) {
			next = current->next;
			delete current;
			current = next;
		}*/
	}

	void print() {
		Node* current = this;
		while (current->next != NULL) {

			cout << current->data << " ";
			current = current->next;

		}
	}

	void insert(int x) {

		Node* newNode;
		newNode = new Node;
		newNode->data = x;
		newNode->next = NULL;

		Node* current = this;

		if (current==NULL) {
			cout << "xx" << endl;
			current = newNode;
		}
		else {
			
			cout << "aa" << endl;
			while (current->next != NULL) {
				current = current->next;
			}

			current->next = newNode;

		}


	}
};

class AdjList{
public:
	Node* head =NULL;
	int maxSize;
	int currVertices;

	AdjList(int maxVertices) {
		maxSize = maxVertices;
		currVertices = 0;
		head = new Node[maxSize];
	}

	~AdjList() {
		clearGraph();
	}


	void clearGraph() {

		for (int i = 0; i < currVertices; i++)
			head[i].destroyList();
		currVertices = 0;
	}

	void printGraph() {
		for (int i = 0; i < currVertices; i++) {
			
			head[i].print();
			cout << endl;
		}
	}

	void createGraph() {

		int index;
		int vertex;
		

		cout << "Input number of vertices\n";
		cin >> currVertices;
	
		for (int i = 0; i < currVertices; i++) {
			int j = 1;
			int adjacentVertex = 0;
			cout << "Input vertex " << i + 1 << endl;
			cin >> vertex;
			head[i].insert(vertex);
			
			while (adjacentVertex != -1) {

				cout << "Input adjacent vertex " << j++ << endl;
				cout << "Input -1 when you're done\n";
				cin >> adjacentVertex;
				head[i].insert(adjacentVertex);
				
			}


		}


	}

	void BFS(int startNode) {
		bool* visited = new bool[currVertices];
		for (int i = 0; i < currVertices; i++)
			visited[i] = false;

		queue<int> q1;
		visited[startNode] = true;
		q1.push(startNode);
		list<int>::iterator i;

		while (!q1.empty())
		{
			// Dequeue a vertex from queue and print it
			startNode = q1.front();
			cout << startNode << " ";
			q1.pop();

		
			for (int j=0 ; j<currVertices ; ++j)
			{
				if (!visited[*i])
				{
					visited[*i] = true;
					q1.push(*i);
				}
			}
		}

	}
	

};



int main()
{

	AdjList adj1(5);
	adj1.createGraph();
	adj1.printGraph();

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
