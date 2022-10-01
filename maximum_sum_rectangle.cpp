#include<bits/stdc++.h>
#define pb push_back
using namespace std;


inline int max(int a, int b){
    return (a>b?a:b);
}

int maximumSumRectangle(int R, int C, vector<vector<int> > M) {
    int subSum[R][C];
    
    //init
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            subSum[i][j] = 0;
        };  
    };
        
    //init of first index
    subSum[0][0] = M[0][0];
        
    //variable to store answer
    int mx = subSum[0][0];
        
    //filling first row
    for(int j=1;j<C;j++){
        subSum[0][j] = subSum[0][j-1]+M[0][j];
        mx = max(mx, subSum[0][j]);
    };
        
    //filling first column
    for(int i=1;i<R;i++){
        subSum[i][0] = subSum[i-1][0]+M[i][0];
        mx = max(mx, subSum[i][0]);
    };
        
    //filling rest of the matrix
    for(int i=1;i<R;i++){
        for(int j=1;j<C;j++){
            subSum[i][j] = subSum[i-1][j]+subSum[i][j-1]+M[i][j]-subSum[i-1][j-1];
            mx = max(mx, subSum[i][j]);
        };  
    };
    return mx;
}
int main(){
    int R, C;
    cin >> R >> C;
    vector<vector<int> > M;
    for(int i=0;i<R;i++){
        vector<int> row;
        for(int j=0;j<C;j++){
            int inp;
            cin >> inp;
            row.pb(inp);
        };
        M.pb(row);
    };
    //cout << maximumSumRectangle(r, c, matrix) << endl;
    int subSum[R][C];
    
    //init
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            subSum[i][j] = 0;
        };  
    };
        
    //init of first index
    subSum[0][0] = M[0][0];
        
    //variable to store answer
    int mx = subSum[0][0];
        
    //filling first row
    for(int j=1;j<C;j++){
        subSum[0][j] = subSum[0][j-1]+M[0][j];
        mx = max(mx, subSum[0][j]);
    };
        
    //filling first column
    for(int i=1;i<R;i++){
        subSum[i][0] = subSum[i-1][0]+M[i][0];
        mx = max(mx, subSum[i][0]);
    };
        
    //filling rest of the matrix
    for(int i=1;i<R;i++){
        for(int j=1;j<C;j++){
            subSum[i][j] = subSum[i-1][j]+subSum[i][j-1]+M[i][j]-subSum[i-1][j-1];
            mx = max(mx, subSum[i][j]);
        };  
    };
    cout << endl;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cout << subSum[i][j] << " ";
        };  
        cout <<  endl;
    };
    cout << mx << endl;
    return 0;
}