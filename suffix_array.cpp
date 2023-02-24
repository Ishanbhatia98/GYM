#include<bits/stdc++.h>

using namespace std;

int main(){
    cout << "Enter String: ";
    string s;
    cin >> s;
    s+="$";
    int n = s.size();
    pair<char, int>* a = new pair<char, int>[n];
    for(int i=0;i<n;i++){
        a[i].first = s[i];
        a[i].second = i;
    }
    sort(a, a+n);
    //to store positions
    int* p = new int[n];
    for(int i=0;i<n;i++){p[i] = a[i].second;};
    //to store equivalent classes
    int* c = new int[n];
    c[p[0]] = 0;
    for(int i=1;i<n;i++){
        if(a[i].first==a[i-1].first) c[p[i]]=c[p[i-1]];
        else c[p[i]]=1+c[p[i-1]];
    };
    int k=0;
    while(k<n){
        pair<pair<int, int>, int>* a = new pair<pair<int, int>, int>[n];
        for(int i=0;i<n;i++){
            pair<int, int> p(c[i], c[(i+(1<<k))%n]);
            a[i].first = p;
            a[i].second = i;
        };
        sort(a,a+n);
        for(int i=0;i<n;i++){p[i] = a[i].second;};
        c[p[0]] = 0;
        for(int i=1;i<n;i++){
            if(a[i].first==a[i-1].first) c[p[i]]=c[p[i-1]];
            else c[p[i]]=1+c[p[i-1]];
        };
        k = 1 << k;
    };
    for(int i=0;i<n;i++){cout << p[i] <<  " ";};
    return 0;
}