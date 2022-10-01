#include<bits/stdc++.h>

using namespace std;
/*
Algorithm:
Create a set mstSet that keeps track of vertices already included in MST. 
Assign a key value to all vertices in the input graph. Initialize all key values as INFINITE. Assign the key value as 0 for the first vertex so that it is picked first. 
While mstSet doesn’t include all vertices 
Pick a vertex u which is not there in mstSet and has a minimum key value. 
Include u in the mstSet. 
Update the key value of all adjacent vertices of u.
To update the key values, iterate through all adjacent vertices. For every adjacent vertex v, 
if the weight of edge u-v is less than the previous key value of v, 
update the key value as the weight of u-v
*/

//status: partially working
inline int min(int a, int b){return (a>b?b:a);}
int MST(int** edges, set<int>* adjacencyList, int* weights, int v, int e, set<int> mstSet, vector<int>& mstEdges){
    //if all vertices have been visited
    if(mstSet.size()==v) return 0;

    int vertex=-1, minWeight=INT_MAX;
    for(int i=0;i<v;i++){
        //if vertex is not present in mst
        if(mstSet.find(i)==mstSet.end()){
            //if vertex has minimum weight
            if(minWeight>weights[i]){
                vertex=i;
                minWeight=weights[i];
            }
        }
    };
    //check
    if(vertex==-1) return 0;
    //added vertex to mst
    mstSet.insert(vertex);
    mstEdges.push_back(vertex);

    set<int> adjacentVertices = adjacencyList[vertex];
    int numberOfAdjacentVertices = adjacentVertices.size();
    for(auto adjV: adjacentVertices){
        //updating k-v for adjacent vertices
        weights[adjV] = min(weights[adjV], edges[vertex][adjV]);
    };

    return minWeight+MST(edges, adjacencyList, weights, v, e, mstSet, mstEdges);



}

int main(){
    int v, e;
    cout << "Enter number of vertices and edges: ";
    cin >> v >> e;
    cout << "Enter number of edges:" << endl;
    //to store adjacent vertices
    set<int> adjacencyList[v];
    //to store edge weights
    int** edges = new int* [v];
    for(int i=0;i<v;i++){
        edges[i] = new int [v];
    };
    for(int i=0;i<e;i++){
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        edges[v1][v2] = wt;
        edges[v2][v1] = wt;
    };

    //to store weights(key-value), initializing with inf
    int weights[v];
    for(int i=0;i<v;i++){weights[i]=INT_MAX-1;};

    //setting weight of start vertex as 0
    weights[0]=0;

    //set to store vertices already in mst
    set<int> mstSet;

    int mst;

    //vector to store edges
    vector<int>  mstEdges;
    mst = MST(edges, adjacencyList, weights, v, e, mstSet, mstEdges);
    cout << "MST weight: " << mst <<  endl;
    cout << "Edges in mst:" << endl;
    for(int i=0;i<v-1;i++){
        cout << mstEdges[i] << "->" << mstEdges[i+1] << endl;
    };
    return 0;
}