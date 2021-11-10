#include <iostream>
#include<stack>
#include<vector>
std::vector <int> adj[9];

using namespace std;
#define SIZE 40

struct queue {
  int items[SIZE];
  int front;
  int rear;
};

struct queue* createQueue();
void enqueue(struct queue* q, int);
int dequeue(struct queue* q);
void display(struct queue* q);
int isEmpty(struct queue* q);
void printQueue(struct queue* q);

struct node {
  int vertex;
  struct node* next;
};

struct node* createNode(int);

struct Graph {
  int numVertices;
  struct node** adjLists;
  int* visited;
};

int graphItems[9];
int k=0;

void bfs(struct Graph* graph, int startVertex) {
  struct queue* q = createQueue();

  graph->visited[startVertex] = 1;
  enqueue(q, startVertex);

  while (!isEmpty(q)) {
    printQueue(q);
    int currentVertex = dequeue(q);
    cout<<"Visited: "<<currentVertex<<endl;    
    graphItems[k]=currentVertex;
    k++;

    struct node* temp = graph->adjLists[currentVertex];

    while (temp) {
      int adjVertex = temp->vertex;

      if (graph->visited[adjVertex] == 0) {
        graph->visited[adjVertex] = 1;
        enqueue(q, adjVertex);
      }
      temp = temp->next;
    }
  }
}


void bfsSearch(struct Graph* graph, int startVertex,int element) {
  struct queue* q = createQueue();

  graph->visited[startVertex] = 1;
  enqueue(q, startVertex);

  while (!isEmpty(q)) {
    int currentVertex = dequeue(q);
    struct node* temp = graph->adjLists[currentVertex];

if(currentVertex==element){
    cout<<"Found"<<endl;
    return;
}
    while (temp) {
      int adjVertex = temp->vertex;

      if (graph->visited[adjVertex] == 0) {
        graph->visited[adjVertex] = 1;
        enqueue(q, adjVertex);
      }
      temp = temp->next;
    }
  }
  cout<<"Not found"<<endl;
}

struct node* createNode(int v) {
  struct node* newNode = new node;
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}

struct Graph* createGraph(int vertices) {
  struct Graph* graph = new Graph;
  graph->numVertices = vertices;

  graph->adjLists = (struct node**)malloc(vertices * sizeof(struct node*));
  graph->visited = (int*) malloc(vertices * sizeof(int));

  int i;
  for (i = 0; i < vertices; i++) {
    graph->adjLists[i] = NULL;
    graph->visited[i] = 0;
  }

  return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
  struct node* newNode = createNode(dest);
  newNode->next = graph->adjLists[src];
  graph->adjLists[src] = newNode;

  newNode = createNode(src);
  newNode->next = graph->adjLists[dest];
  graph->adjLists[dest] = newNode;
}

struct queue* createQueue() {
  struct queue* q = new queue;
  q->front = -1;
  q->rear = -1;
  return q;
}

int isEmpty(struct queue* q) {
  if (q->rear == -1)
    return 1;
  else
    return 0;
}

void enqueue(struct queue* q, int value) {
  if (q->rear == SIZE - 1)
cout<<"Queue is full"<<endl;
  else {
    if (q->front == -1)
      q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
  }
}

int dequeue(struct queue* q) {
  int item;
  if (isEmpty(q)) {
    cout<<"Queue is empty";
    item = -1;
  } else {
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
      
      q->front = q->rear = -1;
    }
  }
  return item;
}

void printQueue(struct queue* q) {
  int i = q->front;

  if (isEmpty(q)) {
    cout<<"Queue is empty";
  } else {
    cout<<"\nQueue contains: ";
    for (i = q->front; i < q->rear + 1; i++) {
      cout<<q->items[i];
    }
  }
  cout<<endl;
}

void dfsUsingStack(int s,vector<int>adj[],bool visit[]){
  stack<int>stk;//stack in STL
  stk.push(s);
  visit[s]=true;
  while(!stk.empty()){
    int u=stk.top();
    cout<<u<<" ";
    stk.pop();
//loop for traverse
    for(int i=0;i<adj[u].size();i++){
      if(!visit[adj[u][i]]){
        stk.push(adj[u][i]);
        visit[adj[u][i]]=true;
      }
    }
  }
}

void DFS(struct Graph* graph, int vertex) {
  struct node* adjList = graph->adjLists[vertex];
  struct node* temp = adjList;

  graph->visited[vertex] = 1;
  cout<<"Visited: "<< vertex<<endl;

  while (temp != NULL) {
    int connectedVertex = temp->vertex;

    if (graph->visited[connectedVertex] == 0) {
      DFS(graph, connectedVertex);
    }
    temp = temp->next;
  }
}

bool found=false;

void dfsSearch(struct Graph* graph, int vertex,int element) {
  struct node* adjList = graph->adjLists[vertex];
  struct node* temp = adjList;

  graph->visited[vertex] = 1;
if(vertex==element){
    cout<<"Found"<<endl;
    found=true;
}
  while (temp != NULL) {
    int connectedVertex = temp->vertex;

    if (graph->visited[connectedVertex] == 0) {
      dfsSearch(graph, connectedVertex,element);
    }
    temp = temp->next;
  }

}


int main() {
  struct Graph* graph = createGraph(9);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 0, 3);
  addEdge(graph, 1, 4);
  addEdge(graph, 1, 5);
  addEdge(graph, 2, 6);
  addEdge(graph, 3, 7);
  addEdge(graph, 3, 8);
  addEdge(graph, 4, 9);

cout<<"Choose which traversal you want to perform"<<endl;
cout<<"1.BFS (Traversal using Queue) 2. DFS(Traversal using stack) 3.Search using BFS  4.Search using dfs"<<endl;

int option;
cin>>option;


if(option==1){
    bfs(graph,0);

    cout<<"\n Traversal: ";
    for(int i=0;i<9;i++){
    cout<<graphItems[i]<<" ";
    }
}
else if(option==2){
    DFS(graph,0);
}
else if(option==3){
    cout<<"Enter element you want to search: "<<endl;
    int element;
    cin>>element;
    bfsSearch(graph,0,element);
}
else if(option==4){
    cout<<"Enter element you want to search: "<<endl;
    int element;
    cin>>element;
    dfsSearch(graph,0,element);
    if(found==false){
        cout<<"Not found"<<endl;
    }
}
  



  return 0;
}