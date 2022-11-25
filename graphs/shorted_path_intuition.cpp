#include<bits/stdc++.h>

using namespace std;
inline int min(int a, int b){return (a>b?b:a);}
int shortestPath(int** edges, bool* visited, int v, int source, int target){
    if(source==target) return 0;
    int dist = 100000;
    for(int i=0;i<v;i++){
        if(!visited[i] && edges[source][i]!=-1) {
                //backtracking
                visited[i] = true;
                dist = min(dist, edges[source][i]+shortestPath(edges, visited, v, i, target));
                visited[i] = false;
            }

    };
    return dist;
}
int main(){
    int v, e;
    cout << "Enter number of vertices and edges: ";
    cin >> v >> e;
    cout << "Enter edges and weights:  "  << endl;
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

    //visited array
    bool* visited = new bool [v];
    int* minDist = new int  [v];
    
    cout << "Enter source vertex: ";
    int source;
    cin >> source;


    //dist b/w source->source = 0
    minDist[source] = 0;
    for(int i=0;i<v;i++){
        minDist[i] = shortestPath(edges, visited, v, source, i);
    };
    for(int i=0;i<v;i++){
        cout << source <<  " -> " << i << ": " << minDist[i] << endl;
    };
    


    return 0;
}