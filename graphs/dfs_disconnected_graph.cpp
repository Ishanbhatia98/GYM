#include<bits/stdc++.h>


using namespace std;

void DFS(bool** edges, bool* visited, int n, int start_vertex){
    if(visited[start_vertex]) return;
    cout << start_vertex << " ";
    visited[start_vertex] = true;
    for(int i=0;i<=n;i++){
        if(!visited[i] && edges[i][start_vertex]) DFS(edges, visited, n, i);
    };
}
int main(){
    int n, e;
    cout << "Enter number of vertices and edges " << endl;
    cin >> n >> e;
    bool** edges = new bool* [n+1];
    for(int i=0;i<=n;i++){edges[i] = new bool [n+1];};
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            edges[i][j] = false;
        };
    };
    cout << "Enter edges" << endl;
    for(int i=0;i<e;i++){
        int v1, v2;
        cin >> v1 >> v2;
        edges[v1][v2] = true;
        edges[v2][v1] = true;
    };
    bool visited[n+1];
    for(int i=0;i<=n;i++){visited[i]=false;};
    for(int i=0;i<=n;i++){
        if(!visited[i]) DFS(edges, visited, n, i);
    }
    return 0;
}