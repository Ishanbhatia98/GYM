#include<bits/stdc++.h>

using namespace std;

int findParent(int* parent, int vertex){
    if(parent[vertex]==vertex) return vertex;
    return parent[vertex] = findParent(parent, parent[vertex]);
}

int main(){
    cout << "Enter number of vertices and edges: ";
    int v, e;
    cin >> v >> e;
    int* parent = new int [v];
    for(int i=0;i<v;i++){
        parent[i]=i;
    };
    cout << "Enter edges: " << endl;

    for(int i=0;i<e;i++){
        int v, u;
        cin >> v >>u;
        int p1 = findParent(parent, v);
        int p2 = findParent(parent, u);
        parent[p2] = p1;
    };
    int c = 0;
    set<int> s;
    for(int i=0;i<v;i++){
        int p = findParent(parent, i);
        if(s.end()==s.find(p)){
            s.insert(p);
            c++;
        }
    }
    cout << "Total connected components: " << c << endl;
    return 0;
}