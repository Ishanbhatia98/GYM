#include<bits/stdc++.h>
#define pb push_back
//not working
using namespace std;
vector<int> getPath(bool** edges, int n, queue<int> visit_queue, int target, bool* visited, vector<int> path){
    vector<int> empty;
    if(visit_queue.empty()){
        return empty;
    }
    int source = visit_queue.front();
    visit_queue.pop();
    visited[source] = true;
    path.pb(source);
    if(edges[source][target]){
        path.pb(target);
        return path;
    }
    for(int i=0;i<n;i++){
        if(!visited[i] && edges[source][i]){
            visit_queue.push(i);
            return getPath(edges, n, visit_queue, target, visited, path);
        }
    };
    return empty;
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
    cout << "Enter edges " << endl;
    for(int i=0;i<e;i++){
        int v1, v2;
        cin >> v1 >> v2;
        edges[v1][v2] = true;
        edges[v2][v1] = true;
    };
    bool visited[n];
    for(int i=0;i<n;i++){visited[i]=false;};
    vector<int> path;
    cout << "Enter source and target vertex: ";
    int source, target;
    cin >> source >> target;
    queue<int> visit_queue;
    visit_queue.push(source);
    path = getPath(edges, n, visit_queue, target, visited, path);
    if(path.size()){cout <<"start->";for(auto p: path){cout << p <<"->";}; cout << "end";}
    else cout << "Path does not exist";
    cout << endl;
    return 0;
}