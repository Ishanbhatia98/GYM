#include<bits/stdc++.h>
//status:INTUITION  not working :(
using namespace std;
inline int min(int a, int b){return (a>b?b:a);};
int shortestPath(int** edges, bool* visited, int source, int target, int v){
    if(source==target) return 0;
    int dist = INT_MAX;
    for(int i=0;i<v;i++){
        if(i!=source){
            if(!visited[i] && edges[source][i]!=-1){
                //backtracking?
                visited[i] = true;
                dist = min(dist, edges[source][i]+shortestPath(edges, visited, i, target, v));
                visited[i]  = false;
            }
        }
    }
    return dist;
}

int main(){
    int v, e;
    cout << "Enter number of vertices and edges: " ;
    cin >> v >> e;
    cout << "Enter edges: " << endl;

    //adjacency matrix
    int** edges = new int* [v];
    for(int i=0;i<v;i++){
        edges[i] = new int [v];
    };    
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            edges[i][j] = -1;
        };
    };
    for(int i=0;i<e;i++){
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        edges[v1][v2] = wt;
        edges[v2][v1] = wt;
    };

    cout << "enter source vertex: ";
    int source;
    cin >> source;


    int* minDist = new int [v];

    //initially all vertices are at infinity from source vertex
    for(int i=0;i<v;i++){minDist[i]=INT_MAX;};

    //dist b/w source - source  is 0
    minDist[source] = 0;


    // intit visited array
    bool* visited = new bool [v];
    
    for(int i=0;i<v;i++){
        for(int i=0;i<v;i++){visited[i]=false;};
        if(i!=source) minDist[i] = shortestPath(edges, visited, source, i, v);
    }
    

    cout << "Shortest paths from source: " << endl;
    for(int i=0;i<v;i++){
        cout << "Source:"  << source << " target: " << i << " Distance:" << minDist[i] << endl;
    };
    return 0;
}