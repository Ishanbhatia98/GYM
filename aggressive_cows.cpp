#include<bits/stdc++.h>
#define ll long long

using namespace std;

bool check(ll* a, ll k, ll curr, ll prev, ll n, ll d){
    if(k<=0) return true;
    if(curr>=n) return false;
    if(a[curr]-a[prev]>=d) return check(a, k-1, curr+1, curr, n, d);
    return check(a, k, curr+1, prev, n, d);
}

ll bs(ll l, ll r, ll k, ll* a, ll n){
    if(l>r) return l;
    ll m = r+(r-l)/2;
    if(check(a, k, 1, 0, n, m)) return bs(m+1, r, k, a, n);
    return bs(l, m-1, k, a, n);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        ll a[n];
        for(ll i=0;i<n;i++){
            cin >> a[i];
        };
        sort(a, a+n);
        cout << bs(0, a[n-1]-a[0], k, a, n) << endl;
    };
    return 0;
}