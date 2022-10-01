#include<bits/stdc++.h>
using namespace std;


int main(){
    //number of vertices, edges
    int n, e;
    cin >> n >> e;
    //creating and initializing Adjacenct Matric
    bool** Matrix = new bool* [n+1];
    for(int i=0;i<=n;i++){
        Matrix[i] = new bool [n+1];
    };
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            Matrix[i][j] = (i==j?true:false);
        };
    };
    //taking edges input
    for(int i=0;i<e;i++){
        int vertex1, vertex2;
        cin >> vertex1 >> vertex2;
        Matrix[vertex1][vertex2] = true;
        Matrix[vertex2][vertex1] = true;
    };
    //printing the Adjacency matrix
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout << Matrix[i][j] << " ";
        };
        cout << endl;
    };
    

    // free all memory
    return 0;
}