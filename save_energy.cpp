#include<bits/stdc++.h>
using namespace std;

//https://www.codechef.com/problems/SVENGY?tab=statement

int cost(int i, int j, int* arr){
    return arr[i]*(j-i)*(1+arr[i]*(j+i));
}
int findMinCost(int n, int* arr, int* dp){
    if(n<=0) return 0;
    if(dp[n]!=-1) return dp[n];
    int ans = INT_MAX;
    for(int i=n-1;i>=0;i--){
        ans = min(ans, cost(i, n, arr)+findMinCost(i, arr, dp));
    };
    dp[n] = ans;
    return ans;
}
int main() {
	int n;
	cin >> n; 
	int arr[n], dp[n+1];
	for(int i=0;i<n;i++){
	    cin  >> arr[i];
	    dp[i] = -1;
	};
	dp[n]=-1;
	cout << findMinCost(n-1, arr, dp) << endl;
	return 0;
}
