#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
bool is_bipartite(vector<int>* adjList, int n){
    // no vertices in graph
    if(n==0) return true;
    unordered_set<int>* sets = new unordered_set<int>[2];
    sets[0].insert(0);
    vector<int> pending_vertices;
    pending_vertices.push_back(0);
    while(pending_vertices.size()>0){
        int current_vertex = pending_vertices.back();
        pending_vertices.pop_back();
        int currentSet = (sets[0].count(current_vertex)>0)?0:1;
        for(auto vertex:adjList[current_vertex]){
            //if it is not present in either set
            if(sets[0].count(vertex)==0 && sets[1].count(current_vertex)==0){
                pending_vertices.push_back(vertex);
                sets[currentSet^1].insert(vertex);
            }
            //if it is present in same set, graph is not bipartite
            if(sets[currentSet].count(vertex)>0) return false;
        };
    };
    return true;
}
int main(){
    int v, e;
    cout << "Enter number of vertices and edges: ";
    cin >> v >> e;
    cout << "Enter edges: " <<  endl;
    vector<int>* adjList = new vector<int>[v];
    for(int i=0;i<e;i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    };
    if(is_bipartite(adjList, v)) cout << "Graph is bipartite." << endl;
    else cout << "Graph is not bipartite." <<  endl;
    return 0;
}