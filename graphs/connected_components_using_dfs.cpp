#include<bits/stdc++.h>

using namespace std;



void DFS(int** edges, bool* visited, int vertex, int v){
    if(visited[vertex]) return;
    visited[vertex]=true;
    for(int i=0;i<v;i++){
        if(edges[vertex][i]==1 && !visited[i]){
            DFS(edges, visited, i, v);
        }
    }
}


int main(){
    cout << "Enter number of vertices and edges: ";
    int v, e;
    cin >> v >> e;

    cout << "Enter edges: " << endl;
    int** edges = new int* [v];
    for(int i=0;i<v;i++){
        edges[i] = new int [v];
    };
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            edges[i][j]=0;
        };
    };
    for(int i=0;i<e;i++){
        int v, u;
        cin >> v >>u;
        edges[v][u] = 1;
        edges[u][v] = 1;
    };


    bool* visited = new bool [v];
    for(int i=0;i<v;i++){visited[i]=false;};

    int c = 0;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            c++;
            DFS(edges, visited, i, v);
        }
    };
    cout << "Total connected components: " << c << endl;
    return 0;
}