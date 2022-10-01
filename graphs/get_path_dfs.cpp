#include<bits/stdc++.h>
#define pb push_back
using namespace std;

vector<int> getPath(bool** edges, int n, int source, int target, bool* visited, vector<int> path){
    path.pb(source);
    visited[source] = true;
    if(edges[source][target]){
        path.pb(target);
        return path;
    }
    for(int i=0;i<n;i++){
        if(!visited[i] && edges[source][i]) return getPath(edges, n, i, target, visited, path);
    };
    vector<int> empty;
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
    path = getPath(edges, n, source, target, visited, path);
    if(path.size()){cout <<"start->";for(auto p: path){cout << p <<"->";}; cout << "end";}
    else cout << "Path does not exist";
    cout << endl;
    return 0;
}