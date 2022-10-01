#include<bits/stdc++.h>
using namespace std;
void BFS(bool** edges, int n, bool* visited, queue<int> visit_queue){
    //if queue is empty, all vertices are visited
    if(visit_queue.size()==0) return;

    //removing first element in queue
    int vertex = visit_queue.front();
    visit_queue.pop();

    //checking if vertex is alread visited
    if(visited[vertex]) return;
    visited[vertex] = true;
    cout << vertex << " ";

    //iterating and adding adjacent nodes to visit_queue
    for(int i=0;i<=n;i++){
        if(!visited[i] && edges[i][vertex]){
            visit_queue.push(i);
        }
    };
    //calling BFS function to visit child nodes
    BFS(edges, n, visited, visit_queue);
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
    //printing the Adjacenct matrix
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout << Matrix[i][j] << " ";
    //     };
    //     cout << endl;
    // };
    
    //initialiazing visited array
    bool visited[n+1];
    for(int i=0;i<=n;i++){visited[i]=false;};
    //initializing queue
    queue<int> visit_queue;
    //adding start vertex to queue
    int start_vertex;
    cout << "Enter start vertex for bfs: ";
    cin >> start_vertex; 
    visit_queue.push(start_vertex);
    //printing the graph
    BFS(Matrix, n, visited, visit_queue);
    // free all memory
    return 0;
}