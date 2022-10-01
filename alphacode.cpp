#include<bits/stdc++.h>

// hackerarth : https://www.hackerearth.com/problem/algorithm/acode-alphacode-3/

using namespace std;
int findCodes(int n, string s, int* dp){
    if(n<0) return 0;
    if(dp[n]!=-1) return dp[n];
    int total = 0;
    if(n!=0){
        if(int(s[n-1])<=2 && int(s[n])<=6) total = 1+findCodes(n-2, s, dp);
    }
    dp[n] = total+1+(findCodes(n-1, s, dp));
    return dp[n];
}

int main(){
    string s;
    cin >> s;
    int n = s.size();
    int dp[n+1];
    for(int i=0;i<n;i++){
        dp[i]=-1;
    };
    cout << findCodes(n-1, s, dp) << endl;
    return 0;
}