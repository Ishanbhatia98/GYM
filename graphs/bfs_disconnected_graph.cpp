#include<bits/stdc++.h>
using namespace std;


void BFS(bool** edges, bool* visited, int n, queue<int> visit_queue){
    if(visit_queue.empty()) return;
    int current_vertex = visit_queue.front();
    if(visited[current_vertex]) return;
    cout << current_vertex << " ";
    visited[current_vertex] = true;
    visit_queue.pop();
    for(int i=0;i<=n;i++){
        if(!visited[i] && edges[i][current_vertex]){
            visit_queue.push(i);
            BFS(edges, visited, n, visit_queue);
        }
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
    bool visited[n+1];
    for(int i=0;i<=n;i++){visited[i]=false;};
    queue<int> visit_queue;
    visit_queue.push(0);
    cout << "Enter edges" << endl;  
    for(int i=0;i<e;i++){
        int v1, v2;
        cin >> v1 >> v2;
        edges[v1][v2] = true;
        edges[v2][v1] = true;
    };
    for(int i=0;i<=n;i++){
        if(!visited[i]) BFS(edges, visited, n, visit_queue);
    };
    return 0;
}