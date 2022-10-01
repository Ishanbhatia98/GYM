#include<bits/stdc++.h>

//status: correct and working!!

using namespace std;
struct Edge{
    int source;
    int target;
    int weight;
};

bool cmpEdges(Edge a, Edge b){
    return (a.weight<b.weight?true:false);
}
//union find
int findParent(int* parent, int vertex){
    if(parent[vertex]==vertex) return vertex;
    return findParent(parent, parent[vertex]);
}

//union merge
/*modified union function where we connect the elements by changing the root of one of the element */
void merge(int* parent, int source, int target){
    int parentSource = findParent(parent, source);
    int parentTarget = findParent(parent, target);
    parent[parentSource] = parentTarget; 
}


int MST(Edge* edges, int* parent, int v, int e, int i, int edgeCount, vector<Edge>& mstEdges){
    if(edgeCount==v-1) return 0;
    if(i>=e) return 0;
    Edge edge = edges[i];
    
    //union find
    int parentSource=findParent(parent, edges[i].source);
    int parentTarget=findParent(parent, edges[i].target);
    int weight=0;
    //if not in same subset
    if(parentSource!=parentTarget){
        weight= edges[i].weight;
        //union merge
        merge(parent, edges[i].source, edges[i].target);
        edgeCount++;
        //adding edge to mst
        mstEdges.push_back(edges[i]);
    }
    return weight+MST(edges, parent, v, e, i+1, edgeCount, mstEdges);


}

int main(){
    int v, e;
    cout << "Enter number of vertices and edges: ";
    cin >> v >> e;
    Edge* edges = new Edge [e];
    cout << "Enter edges and weight: " << endl;

    //taking edges input and storing in edge list
    for(int i=0;i<e;i++){
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        edges[i].source = v1;
        edges[i].target = v2;
        edges[i].weight = wt;
    };
    //sorting edges in ascending order of weights
    sort(edges, edges+e, cmpEdges);
    //intializing the parent array
    int* parent = new int [v];
    for(int i=0;i<v;i++){parent[i]=i;};

    vector<Edge> mstEdges;
    int mst;
    mst = MST(edges, parent, v, e, 0, 0, mstEdges);
    cout << "Weight of MST: " << mst << endl;
    cout << "Edges in MST: " << endl;
    for(auto e:mstEdges){
        cout << e.source << "->" << e.target << " " << e.weight << endl;
    };
    return 0;
}