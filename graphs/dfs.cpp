#include<bits/stdc++.h>
using namespace std;

void DFS(bool** Matrix, int n, int start_vertex, bool* visited){
    //checking if already visited
    if(visited[start_vertex]) return;
    cout << start_vertex << " ";
    visited[start_vertex] = true;

    //calling func on child nodes
    for(int i=0;i<=n;i++){
        if(!visited[i] && Matrix[start_vertex][i]) DFS(Matrix, n, i, visited);
    };
}
int main(){
    //number of vertices, edges
    int n, e;
    cin >> n >> e;
    //creating and initializing Adjacenct Matric
    bool** Matrix = new bool* [n+1];
    for(int i=0;i<=n;i++){
        Matrix[i] = new bool [n+1];
    };
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            Matrix[i][j] = (i==j?true:false);
        };
    };
    //taking edges input
    for(int i=0;i<e;i++){
        int vertex1, vertex2;
        cin >> vertex1 >> vertex2;
        Matrix[vertex1][vertex2] = true;
        Matrix[vertex2][vertex1] = true;
    };
 
    
    //initialiazing visited array
    bool visited[n+1];
    for(int i=0;i<=n;i++){visited[i]=false;};
    DFS(Matrix, n, 1, visited);
    // free all memory
    return 0;
}