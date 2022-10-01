#include<bits/stdc++.h>

using namespace std;

bool checkPath(bool** edges, int n, int source, int target, bool* visited){
    //source and target are adjacent
    if(edges[source][target]) return true;
    visited[source]=true;
    for(int i=0;i<n;i++){
        if(!visited[i] && edges[source][i]) return checkPath(edges, n, i, target, visited);
    };
    return false;
}
int main(){
    int n, e;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> e;
    n++;
    bool** edges = new bool* [n];
    for(int i=0;i<n;i++){
        edges[i] = new bool [n];
    };
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
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
    bool visited[n];
    for(int i=0;i<n;i++){visited[i]=false;};
    int source, target;
    cout << "Enter source and target vertex: ";
    cin >> source >> target;
    if(checkPath(edges, n, source, target, visited)){
        cout << "Path exists" << endl;
    }else{
        cout << "Path does not exist" << endl;
    }
    return 0;
}