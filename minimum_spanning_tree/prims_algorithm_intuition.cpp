#include<bits/stdc++.h>

using namespace std;
//status: Incomplete, giving up lol

int main(){
    int v, e;
    cout << "Enter number of vertices and edges: " ;
    cin >> v >> e;
    set<int> adjacent_vertices[v];
    map<pair<int, int>, int> edge_weights;
    cout << "Enter edges and weight:" << endl;
    for(int i=0;i<e;i++){
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        adjacent_vertices[v1].insert(v2);
        adjacent_vertices[v2].insert(v1);

        //adding v1->v2
        pair<int, int> edgev12(v1, v2);
        edge_weights[edgev12] = wt;

        //adding v2->v1
        pair<int, int> edgev21(v2, v1);
        edge_weights[edgev21] = wt;

    };

    //initiating parent array
    int* parent = new int [v];
    for(int i=0;i<v;i++){parent[i]=i;};

    //initiating weight array
    int* weight = new int [v];
    for(int i=0;i<v;i++){weight[i]=INT_MAX;};

    //weight for root is 0(source/starting vertex)
    weight[0] = 0;

    //visited & unvisited set
    set<int> visited = {};
    set<int> unvisited = {};
    for(int i=1;i<v;i++){unvisited.insert(i);};

    vector<pair<int, int> > mstEdges;

    int mst =0;
    mst = MST(visited, unvisited, v, e, weight, adjacent_vertices, edge_weights,  )


    
    return 0;
}