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

typedef struct QueueNode {
    int data;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue {
    QueueNode *front, *rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue* q, int data) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

int dequeue(Queue* q) {
    if (q->front == NULL) {
        return -1;
    }
    QueueNode* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return data;
}

bool isQueueEmpty(Queue* q) {
    return (q->front == NULL);
}

void BFS(Graph* graph, int startVertex) {
    int V = graph->V;
    bool* visited = (bool*)malloc(V * sizeof(bool));
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }
    Queue* queue = createQueue();
    visited[startVertex] = true;
    enqueue(queue, startVertex);
    printf("Breadth-First Traversal starting from vertex %d: ", startVertex);
    while (!isQueueEmpty(queue)) {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);
        AdjListNode* temp = graph->array[currentVertex].head;
        while (temp) {
            int neighbor = temp->dest;
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                enqueue(queue, neighbor);
            }
            temp = temp->next;
        }
    }
    printf("\n");
    free(visited);
    free(queue);
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

    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);

    if (startVertex < 0 || startVertex >= numVertices) {
        printf("Invalid starting vertex.\n");
        freeGraph(graph);
        return 1;
    }

    BFS(graph, startVertex);
    freeGraph(graph);

    return 0;
}
