#include<bits/stdc++.h>

using namespace std;
inline int min(int a, int b){return (a>b?b:a);}
int dijkstras(int**  edges, bool* visited, int v, int source, int target){
    if(source==target) return 0;
    for(int i=0;i<v;i++){
       if(!visited[i]){
        visited[i] = true;
        edges[source][i] = min(edges[source][i], )
        visited[i] = false;
       }
    };
}