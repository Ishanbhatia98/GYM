#include<bits/stdc++.h>

using namespace std;

void DFS(bool** edges, int n, int start_vertex, bool* visited){
    if(visited[start_vertex]) return;
    visited[start_vertex] = true;
    cout << start_vertex << " ";
    for(int i=0;i<n;i++){
        if(!visited[i] && edges[start_vertex][i]) DFS(edges, n, i, visited);
    };
}
int main(){
    cout << "Enter number of vertices and edges: "; 
    int n, e;
    cin >> n >> e;
    bool** edges = new bool* [n];
    for(int i=0;i<n;i++){
        edges[i] = new bool [n];
    };
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            edges[i][j] = false;
        };
    };
    cout << "Enter edges " << endl;
    for(int i=0;i<e;i++){
        int v1, v2;
        cin >> v1 >> v2;
        edges[v1][v2] = true;
        edges[v2][v1] = true;
    };
    bool* visited = new bool [n];
    for(int i=0;i<n;i++){visited[i] = false;};
    cout << "Printing Connected Components: " << endl;
    for(int i=0;i<n;i++){
        DFS(edges, n, i, visited);
        cout << endl;
    };
    return 0;
 
}