#include<bits/stdc++.h>

using namespace std;
bool partitionGraph(set<int>* adjList, int* visited, int x, int current_vertex){
    if(visited[current_vertex]!=-1) return true;
    visited[current_vertex] = x;
    for(auto i:adjList[current_vertex]){
        if(visited[i]==x) return false;
        if(visited[i]==-1) partitionGraph(adjList, visited, x^1, i);
    };
}
int main(){
    int v, e;
    cout << "Enter number of vertices and edges: ";
    cin >> v >> e;
    cout << "Enter edges:" << endl;
    //adjacency list to maintain edges
    set<int>* adjList = new set<int>[v];
    for(int i=0;i<e;i++){
        int a, b;
        cin >> a >> b;
        a--;b--;
        adjList[a].insert(b);
        adjList[b].insert(a);
    };
    int* visited = new int[v];
    for(int i=0;i<v;i++){visited[i]=-1;};
    bool result = partitionGraph(adjList, visited, 0, 0);
    for(int i=0;i<v;i++){cout << visited[i] << " ";}
    // if(result) {for(int i=0;i<v;i++){cout << visited[i] << " ";};}
    // else {cout << "Graph cannot be partitioned.." << endl;}
    // if(result){
    //     cout << "The sets u and v of the bipartite graph are: " <<  endl;
    //     for(auto i:u){cout << i << " ";};
    //     cout << endl;
    //     for(auto i:v){cout << i << " ";};
    //     cout << endl;
    // }else{
    //     cout << "The graph cannout be partitioned...";
    // }


    return 0;
}