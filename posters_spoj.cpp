#include<bits/stdc++.h>
#define ll long long
using namespace std;
//PROBLEM:https://www.spoj.com/problems/POSTERS/
//not working

inline int max(int a, int b){return (a>b?a:b);}
struct Poster{
    ll left;
    ll right;
};

void updateST(ll* tree, ll* lazy, int si, int ei, int tN, int left, int right, ll value){
    if(si>ei) return;
    if(lazy[tN]!=0){
        tree[tN] =lazy[tN];
        //if not a leaf node
        if(si!=ei){
            lazy[2*tN] = lazy[tN];
            lazy[2*tN+1] = lazy[tN];
        }
        lazy[tN] = 0;
    }
    //completely outside
    if(si>right || ei<left) return;
    //completely inside
    if(si>=left && ei<=right){
        tree[tN] = value;
        //if not a leaf node
        if(si!=ei){
            lazy[2*tN] = value;
            lazy[2*tN+1] = value;
        }
        return;
    }
    //partially inside
    int mid = (si+ei)/2;
    updateST(tree, lazy, si, mid, 2*tN, left, right, value);
    updateST(tree, lazy, mid+1, ei, 2*tN+1, left, right, value);

}

int main(){
    int t;
    cin  >> t;
    while(t--){
        int n;
        cin >> n;
        Poster posters[n];    
        ll maxRight = 0;
        for(int i=0;i<n;i++){
            cin >> posters[i].left >> posters[i].right;
            maxRight = max(maxRight, posters[i].right);
        };    
        n = maxRight;
        int on = n;
        ll tree[4*n], lazy[4*n];
        for(int i=0;i<4*n;i++){
            tree[i] = 0;
            lazy[i] = 0;
        };
        for(int i=0;i<on;i++){
            updateST(tree, lazy, 0, 4*n-1, 1, posters[i].left, posters[i].right, i+1);
        };
        set<ll> s;
        for(int i=0;i<4*n;i++){
            //replace with lazy tree?
            s.insert(tree[i]);
        };

        cout << s.size()-1 << endl;
    };
    return 0;


}