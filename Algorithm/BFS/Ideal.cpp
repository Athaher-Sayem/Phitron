#include <bits/stdc++.h>
using namespace std;

vector<int> adjacencyList[100]; // Adjacency list to store graph
bool isVisited[100]; // Array to track visited nodes
int nodeLevel[100]; // Array to store level of each node
int parentNode[100]; // Array to store parent of each node

// Breadth-First Search (BFS) function
void BFS(int startNode) { // O(N+E) Complexity
    queue<int> q;
    q.push(startNode);
    isVisited[startNode] = true;
    nodeLevel[startNode] = 0; // Start node level is 0

    while (!q.empty()) {
        int currentNode = q.front(); // Get front node from queue
        q.pop();

        cout << currentNode << " "; // Print current node

        for (int neighbor : adjacencyList[currentNode]) { // Traverse all neighbors
            if (!isVisited[neighbor]) {
                isVisited[neighbor] = true; // Mark neighbor as visited
                q.push(neighbor); // Push neighbor into queue
                nodeLevel[neighbor] = nodeLevel[currentNode] + 1; // Set level of neighbor
                parentNode[neighbor] = currentNode; // Store parent of neighbor
            }
        }
    }
    cout << endl;
}

int main() {
    int numNodes, numEdges;
    cin >> numNodes >> numEdges; // Input number of nodes and edges

    // Initialize arrays
    memset(isVisited, false, sizeof(isVisited));
    memset(nodeLevel, -1, sizeof(nodeLevel));
    memset(parentNode, -1, sizeof(parentNode));

    // Read edges
    while (numEdges--) {
        int nodeA, nodeB;
        cin >> nodeA >> nodeB;
        adjacencyList[nodeA].push_back(nodeB);
        adjacencyList[nodeB].push_back(nodeA); // Since it's an undirected graph
    }

    int sourceNode, targetNode;
    cin >> sourceNode >> targetNode; // Input source and destination node

    BFS(sourceNode); // Perform BFS

    // Find the shortest path from source to targetNode
    vector<int> shortestPath;
    int currentNode = targetNode;

    while (currentNode != -1) { // Traverse back using parent array
        shortestPath.push_back(currentNode);
        currentNode = parentNode[currentNode];
    }

    reverse(shortestPath.begin(), shortestPath.end()); // Reverse to get correct order

    for (int node : shortestPath) cout << node << " "; // Print shortest path
}



/*
    Example Graph:
    
        0 -- 1 -- 2
        |    |
        3 -- 4
       
    Input:
    5 5  // Nodes = 5, Edges = 5
    0 1
    1 2
    0 3
    1 4
    3 4
    0 2  // Source = 0, Target = 2

    BFS Execution:
    
    Queue Process:   [0] → [1, 3] → [3, 4, 2] → [4, 2] → [2] → []
    Visited Order:   0 → 1 → 3 → 4 → 2
    Level Mapping:   0(0) → 1(1) → 3(1) → 4(2) → 2(2)

    Parent Mapping:
    Node:      0   1   2   3   4
    Parent:   -1   0   1   0   1

    Shortest Path from 0 to 2:
    Reverse(2 ← 1 ← 0) → Path: 0 → 1 → 2
*/
