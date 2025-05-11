#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct AdjListNode {
    int dest;
    struct AdjListNode* next;
} AdjListNode;

typedef struct AdjList {
    AdjListNode* head;
} AdjList;

typedef struct Graph {
    int V;
    AdjList* array;
} Graph;

AdjListNode* newAdjListNode(int dest) {
    AdjListNode* newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->array = (AdjList*)malloc(V * sizeof(AdjList));
    for (int i = 0; i < V; ++i) {
        graph->array[i].head = NULL;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

void DFSUtil(Graph* graph, int v, bool* visited) {
    visited[v] = true;
    printf("%d ", v);

    AdjListNode* temp = graph->array[v].head;
    while (temp != NULL) {
        int neighbor = temp->dest;
        if (!visited[neighbor]) {
            DFSUtil(graph, neighbor, visited);
        }
        temp = temp->next;
    }
}

void DFS(Graph* graph, int startVertex) {
    int V = graph->V;
    bool* visited = (bool*)malloc(V * sizeof(bool));
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    printf("Depth-First Traversal starting from vertex %d: ", startVertex);
    DFSUtil(graph, startVertex, visited);
    printf("\n");

    free(visited);
}

void freeGraph(Graph* graph) {
    if (graph == NULL) return;
    for (int i = 0; i < graph->V; i++) {
        AdjListNode* current = graph->array[i].head;
        while (current != NULL) {
            AdjListNode* next = current->next;
            free(current);
            current = next;
        }
    }
    free(graph->array);
    free(graph);
}

int main() {
    int numVertices, numEdges, startVertex, src, dest;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);

    if (numVertices <= 0) {
        printf("Number of vertices must be positive.\n");
        return 1;
    }

    Graph* graph = createGraph(numVertices);

    printf("Enter the number of edges in the graph: ");
    scanf("%d", &numEdges);

    if (numEdges < 0) {
        printf("Number of edges cannot be negative.\n");
        freeGraph(graph);
        return 1;
    }

    printf("Enter the edges (source destination) one by one:\n");
    for (int i = 0; i < numEdges; i++) {
        printf("Edge %d: ", i + 1);
        if (scanf("%d %d", &src, &dest) != 2) {
            printf("Invalid edge input.\n");
            freeGraph(graph);
            return 1;
        }
        if (src >= 0 && src < numVertices && dest >= 0 && dest < numVertices) {
            addEdge(graph, src, dest);
        } else {
            printf("Invalid vertex indices for edge %d.\n", i + 1);
        }
    }

    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);

    if (startVertex < 0 || startVertex >= numVertices) {
        printf("Invalid starting vertex.\n");
        freeGraph(graph);
        return 1;
    }

    DFS(graph, startVertex);
    freeGraph(graph);

    return 0;
}
