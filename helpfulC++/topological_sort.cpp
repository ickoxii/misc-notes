/**
 * this contains code taken from geeksforgeeks.org
 *
 * https://www.geeksforgeeks.org/cpp-program-for-topological-sorting/
 * */

// A C++ program to print topological sorting of a DAG
#include <iostream>
#include <list>
#include <stack>
using namespace std;

// class to represent a graph
class Graph {
    int V; // number of vertices
    list<int>* adj; // pointer to array containing adjacency listsList
    // function used by topologicalSort
    void topologicalSortUtil(int v, bool visited[], stack<int>& Stack);

public:
    Graph(int V); // constructor
    
    // function to add an edge to graph
    void addEdge(int v, int w);

    // prints a Topological Sort of the complete graph
    void topologicalSort();
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); // add w to v's list
}

void Graph::topologicalSortUtil(int v, bool visited[],
                                stack<int>& Stack) {
    // Mark the current node as visited
    visited[v] = true;

    // recurse for all vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i!= adj[v].end(); ++i) {
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack);
    }

    // Push current vertex to stack which stores result
    Stack.push(v);
}

// The function to do topological Sort. It uses the recursive
// topologicalSortUtil
void Graph::topologicalSort() {
    stack<int> Stack;

    // Mark all the vertices as not visited
    bool* visited = new bool[V];
    for (int i = 0; i < V; ++i)
        visited[i] = false;

    // Call the recursive helper function to store Topological
    // Sort starting from all vertices one by one
    for (int i = 0; i < V; ++i)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, Stack);

    // Print contents of stack
    while (Stack.empty() == false) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}

// Driver program to test above functions
int main() {
    // create a graph
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << "Following is a Topological Sort of the given graph: ";
    g.topologicalSort();
    cout << endl;
    cout << "Expected: 5 4 2 3 1 0" << endl;

    return 0;
}
