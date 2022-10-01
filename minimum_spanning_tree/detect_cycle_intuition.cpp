#include<bits/stdc++.h>
using namespace std;
//status: not working
//use union find to detect cycles!
bool checkCycle(bool* visited, int n, int current_vertex, int** edges){
    int c=0;
    for(int i=0;i<n;i++){
        if(visited[i] && edges[i][current_vertex]!=-1) c++;
        if(c>1) return true;
    };
    return false;
}
bool detectCycle(int** edges, int n, int current_vertex, bool* visited){
    if(checkCycle(visited, n, current_vertex, edges)) return true;
    visited[current_vertex] = true;
    bool ans = false;
    for(int i=0;i<n;i++){
        if(!visited[i] && edges[current_vertex][i]!=-1) ans|=checkCycle(visited, n, i, edges);
    };
    return ans;
}

int main(){
    int n, e;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> e;
    int** edges = new int* [n];
    for(int i=0;i<n;i++){
        edges[i] = new int [n];
    };
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            edges[i][j] = -1;
        };
    };
    cout << "Enter edges: " << endl;
    for(int i=0;i<n;i++){
        int v1, v2;
        cin >> v1 >> v2;
        edges[v1][v2] = 1;
        edges[v2][v1] = 1;
    };
    bool* visited = new bool [n];
    for(int i=0;i<n;i++){
        visited[i] = false;
    };
    if(detectCycle(edges, n, 0, visited)){
        cout << "Cycle detected" << endl;
    }else{
        cout << "No cycles in graph" << endl;
    }
    return 0;
}