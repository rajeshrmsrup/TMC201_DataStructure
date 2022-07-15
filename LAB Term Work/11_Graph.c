/*
Program to implement linked representation of a graph in memory using array of pointers.
*/
/*
Name:           Rajesh Kumar
Roll No:        31
Course/Sem:     MCA-2nd
Sec:            B
*/
#include<stdio.h>
#include<stdlib.h>
#define V 6
// Data structure to store a graph object
struct Graph{
	struct Node* head[V];
};
struct Node{
	int dest;
	struct Node* next;
};
struct Edge{
	int src, dest;
};
struct Graph* createGraph(struct Edge edges[], int n){
    int i;
	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
	// initialize head pointer for all vertices.
	for(i=0; i<V; i++){
		graph->head[i] = NULL;
	}

	// add edges to the directed graph one by one
	for (i=0; i<n; i++)
	{
		// get the source and destination vertex
		int src = edges[i].src;
		int dest = edges[i].dest;
		// allocate a new node of adjacency list from src to dest
		struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->dest = dest;
		newNode->next = graph->head[src];
		graph->head[src] = newNode;
	}
	return graph;
}
// Function to print adjacency list representation of a graph
void printGraph(struct Graph* graph){
    int i;
	for(i=0; i<V; i++){
		// print current vertex and all its neighbors
		struct Node* ptr = graph->head[i];
		while (ptr != NULL){
			printf("(%d -> %d) ", i, ptr->dest);
			ptr = ptr->next;
		}
		printf("\n");
	}
}

//Main Function.
int main(){
	// (x, y) pair in the array represents an edge from x to y
	struct Edge edges[] = {
		{0, 1}, {0, 2}, {0, 3}, {1, 3}, {1, 4}, {2, 1}, {2, 3}, {2,4},{4,3}
	};
	int n = sizeof(edges)/sizeof(edges[0]);
	struct Graph *graph = createGraph(edges, n);
	printGraph(graph);
}
/***************OUTPUT***************
(0 -> 3) (0 -> 2) (0 -> 1)
(1 -> 4) (1 -> 3)
(2 -> 4) (2 -> 3) (2 -> 1)

(4 -> 3)
************************************/
