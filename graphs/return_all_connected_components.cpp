#include<bits/stdc++.h>
#define pb push_back
using namespace std;


//partially complete
void getConnectedComponents(bool** edges, int n, int start_vertex,int og,int* visited){
    if(visited[start_vertex]) return;
    visited[start_vertex] = og;
    for(int i=0;i<n;i++){
        if(!visited[i] && edges[start_vertex][i]) getConnectedComponents(edges, n, i, og, visited);
    };
}
int main(){
    cout << "Enter number of vertices and edges: " ;
    int n, e;
    cin >> n >> e;
    bool** edges = new bool* [n];
    for(int i=0;i<n;i++){
        edges[i] = new bool [n];
    };
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            edges[i][j] = false;
        };
    };
    int * visited = new int [n];
    for(int i=0;i<n;i++){visited[i]  = 0;};
    cout << "Enter edges: " << endl;
    for(int i=0;i<e;i++){
        int v1, v2;
        cin >> v1 >> v2;
        edges[v1][v2] = true;
        edges[v2][v1] = true;
    };
    cout << "Printing Connected components: " << endl;
    map<int, vector<int> > connectedComponents;
    for(int og=0;og<n;og++){
        getConnectedComponents(edges, n, og, og, visited);
    };
    for(int i=0;i<n;i++){
        if(connectedComponents.count(visited[i])!=0) connectedComponents[i].pb(i);
        else{
            vector<int> v;
            v.pb(i);
            connectedComponents[visited[i]] = v;
        } 
    };
    for(std::map<int,vector<int> >::iterator it = connectedComponents.begin(); it != connectedComponents.end(); ++it) {
        vector<int> v = it->second;
        for(int i=0;i<v.size();i++){
            cout << v[i] << " ";
        };
        cout << endl;

    };

    return 0;
}