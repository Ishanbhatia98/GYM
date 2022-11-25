#include<bits/stdc++.h>
using namespace std;

//problem :https://www.interviewbit.com/problems/permutation-swaps/
//status: working

int findParent(int* parent, int vertex){
    if(parent[vertex]==vertex) return vertex;
    return parent[vertex] = findParent(parent, parent[vertex]);
}

int solve(vector<int> &A, vector<int> &B, vector<vector<int> > &C) {
    int n = A.size();
    int* parent = new int[n];
    for(int i=0;i<n;i++){parent[i]=i;};
    for(auto coors:C){
        int u=coors[0]-1, v=coors[1]-1;
        int p1=findParent(parent, u);
        int p2 = findParent(parent, v);
        parent[p2] = p1;  
    };
    map<int, set<int> > connectedComponentsA, connectedComponentsB;
    set<int> parents;
    for(int i=0;i<n;i++){
        int parentI = findParent(parent, i);
        parents.insert(parentI);
        connectedComponentsA[parentI].insert(A[i]);
        connectedComponentsB[parentI].insert(B[i]);
    };

    for(auto i:parents){
        if(connectedComponentsA[i]!=connectedComponentsB[i]){
            return 0;
        }
    };
    return 1;
    
    
}

int main(){
    int n;
    vector<int> A, B;
    for(int i=0;i<n;i++){
        int inp;
        cin >> inp;
        A.push_back(inp);
    };
    for(int i=0;i<n;i++){
        int inp;
        cin >> inp;
        B.push_back(inp);
    };
    int q;
    cin >> q;
    vector<vector<int> > C;
    for(int i=0;i<q;i++){
        int u, v;
        cin >> u >> v;
        vector<int> ve;
        ve.push_back(u);
        ve.push_back(v);
        C.push_back(ve);
    };
    cout << solve(A, B, C) << endl;



    return 0;

}

