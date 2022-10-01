#include<bits/stdc++.h>

using namespace std;
//status: inefficient approach and wrong answer
struct Edge{
    int vertex1;
    int vertex2;
    int weight;
};

bool cmpEdges(Edge a, Edge b){
    return bool(a.weight<b.weight);
}

int main(){
    int n, e;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> e;

    //array to store vertices and weight of an edge
    Edge edges[2*e];

    cout << "Enter edges: " << endl;
    for(int i=0;i<2*e;i+=2){
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;

        //registering edge from v1 to v2
        edges[i].vertex1 = v1;
        edges[i].vertex2 = v2;
        edges[i].weight = wt;

        //registering edge from v2 to v1
        edges[i+1].vertex1 = v2;
        edges[i+1].vertex2 = v1;
        edges[i+1].weight = wt;
    };
    //sort edges wrt weight in ascending order
    sort(edges, edges+2*e, cmpEdges);

    //initializing visited array
    bool* visited = new bool [n];
    for(int i=0;i<n;i++){visited[i]=false;};

    
    int countEdges = 0;
    int mst = 0;

    //vector store selected edges for MST
    vector<pair<int, int> >  mstEdges;

    for(int i=0;i<2*e;i++){
        //if total count of edges is n-1 then break
        if(countEdges==n-1) break;
        
        //condition to ensure no cycles are formed
        if(!visited[edges[i].vertex1] && !visited[edges[i].vertex2]){
            //each vertex should have one incoming and one outgoing edge
            
            //marking vertex1 as visited, traversing to vertex2 (outgoing edge from vertex1 to vertex2)
            visited[edges[i].vertex1]  = true;
            
            //adding edge weight to mst
            mst+=edges[i].weight;
            
            countEdges++;

            //adding edge to MST
            pair<int, int> mstEdge;
            mstEdge.first = edges[i].vertex1;
            mstEdge.second = edges[i].vertex2;
            mstEdges.push_back(mstEdge);
        }
    };
    cout << "Total Weight of MST: " << mst << endl;
    cout << "The edges in MST are: " << endl;
    for(auto e:mstEdges){
        cout << e.first <<  "->" << e.second << endl;
    };
    return 0;
}