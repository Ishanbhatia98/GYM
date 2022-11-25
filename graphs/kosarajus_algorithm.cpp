#include<bits/stdc++.h>

using namespace std;


//status:  working!
void PrintSCCDFS(set<int>* adjList, bool* visited, int start_vertex){
    if(visited[start_vertex]) return;
    cout << start_vertex << " ";
    visited[start_vertex]  = true;
    for(auto v:adjList[start_vertex]){
        if(!visited[v]) PrintSCCDFS(adjList, visited, v);
    };
}
void DFS(set<int>* adjList, bool* visited, int start_vertex, stack<int>&stack){
    if(visited[start_vertex]) return;
    visited[start_vertex] = true;
    for(auto v:adjList[start_vertex]){
        if(!visited[v]) DFS(adjList, visited, v, stack);
    };
    stack.push(start_vertex);
}

int main(){
    int v, e;
    cout << "Enter number of vertices and edges: ";
    cin >> v >> e;
    set<int>* adjList = new  set<int>[v];
    cout << "Enter edges: " << endl;
    //creating adjacency list
    for(int i=0;i<e;i++){
        int a, b;
        cin >> a >> b;
        adjList[a].insert(b);
    };
    //adjacency list for transpose graph
    set<int>* TadjList = new set<int>[v];
    for(int i=0;i<v;i++){
        for(auto ve:adjList[i]){
            TadjList[ve].insert(i);
        };
    };

    bool* visited = new bool [v];
    for(int i =0;i<v;i++){visited[i]=false;};
    stack<int> stack;
    DFS(adjList, visited, 0, stack);
    for(int i =0;i<v;i++){visited[i]=false;};
    while(!stack.empty()){
        int current_vertex = stack.top();
        stack.pop();
        if(!visited[current_vertex]) PrintSCCDFS(TadjList, visited, current_vertex);
        cout << endl;
    };
    return 0;
}