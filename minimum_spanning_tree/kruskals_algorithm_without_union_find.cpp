#include<bits/stdc++.h>
#define pb push_back
using namespace std;
/*
status: inefficient approach
The problem with this approach is when we assing the same parent 'P' to vertices with two different parents
we will need to assign to all vertices having either of the parents to the same parent 'P' as well -> o(n**2)
*/
struct Edge{
    int vertex1;
    int vertex2;
    int weight;
};

bool cmp(Edge a, Edge b){
    return (a.weight<b.weight);
}

void assignParents(int* parent, int vertex1, int vertex2, int n){
    //union merge!
    int parentV1 = parent[vertex1];
    int parentV2 = parent[vertex2];
    for(int i=0;i<n;i++){
        if(parent[i]==parentV2) parent[i] = parentV1;
    };
    return;
}
int KruskalsAlgorithm(Edge* edge_list, int* parent, int n, int e, int count, int i, vector<pair<int, int> >& mst){
    if(i>=e) return 0;
    if(count==n-1) return 0;
    Edge edge = edge_list[i];
    int v1=edge.vertex1, v2=edge.vertex2, wt=0;
    //union find
    if(parent[v1]!=parent[v2]){
        count++;
        //this is the problem!
        //parent[v1] = parent[v2];
        assignParents(parent, v1, v2, n);
        pair<int, int> mstEdge;
        mstEdge.first = v1;
        mstEdge.second = v2;
        mst.pb(mstEdge);
        wt = edge.weight;

    }
    return wt+KruskalsAlgorithm(edge_list, parent, n, e, count, i+1, mst);
}

int main(){
    int n, e;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> e;
    // int** edges = new int* [n];
    // for(int i=0;i<n;i++){
    //     edges[i] = new int [n];
    // };
    cout << "Enter edges with weight: " << endl;

    Edge edge_list[e];
    //creating the adjacency matrix
    for(int i=0;i<e;i++){
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        // edges[v1][v2] = wt;
        // edges[v2][v1] = wt;

        //adding edge to edge list v1->v2
        edge_list[i].vertex1 = v1;
        edge_list[i].vertex2 = v2;
        edge_list[i].weight = wt;

    }; 
    //sorting the edge list
    sort(edge_list, edge_list+e, cmp);
    //initiate the parent matrix
    int* parent = new int [n];
    for(int i=0;i<n;i++){parent[i]=i;};
    //initiate the visited array
    // bool* visited = new bool [n];
    // for(int i=0;i<n;i++){visited[i]=false;};

    
    vector<pair<int, int> > mst;
    int mstWeight;
    mstWeight = KruskalsAlgorithm(edge_list, parent, n, e, 0, 0, mst);
    
    cout << "Mst: " << mstWeight << endl;
    return 0;
}