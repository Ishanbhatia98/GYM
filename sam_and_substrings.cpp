#include <bits/stdc++.h>
#define ll long long
using namespace std;

//Problem:https://www.hackerrank.com/challenges/sam-and-substrings/problem

ll M = pow(10, 9)+7;


ll  valueOfString(int l, int r, string s, bool** flag){
    if(l>r) return 0;
    if(flag[l][r]) return 0;
    flag[l][r] = true;
    return (stoll(s.substr(l, r-l+1))+valueOfString(l+1, r, s, flag)%M+valueOfString(l, r-1 , s, flag)%M)%M;
}
ll substrings(string s) {
    int n = s.size();
    bool** flag  = new bool * [n+1];
    for(int i=0;i<=n;i++){
        flag[i] = new bool[n+1];
    };
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            flag[i][j] = false;      
        };
    };
    return valueOfString(0, n-1 , s, flag)%M;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n;
    getline(cin, n);

    ll result = substrings(n);

    fout << result << "\n";

    fout.close();

    return 0;
}
