#include<bits/stdc++.h>
using namespace std; 
inline int max(int a, int b){
    return (a>b?a:b);
}
void buildTree(int *arr, int* tree, int start_index, int end_index, int treeNode, int* prefixSum, int* suffixSum){
    //base case
    if(start_index==end_index){
        tree[treeNode] = arr[start_index];
        return;
    }
    int mid = (start_index+end_index)/2;
    //filling left subtree
    buildTree(arr, tree, start_index, mid, 2*treeNode, prefixSum, suffixSum);
    //filling right subtree
    buildTree(arr, tree, mid+1, end_index, 2*treeNode+1, prefixSum, suffixSum);
    //filling current node
    
    //sum of left subtree
    int leftSum = prefixSum[mid]-prefixSum[start_index]+arr[start_index];
    //sum of right subtree
    int rightSum = suffixSum[mid+1]-suffixSum[end_index]+arr[end_index];

    //initialzing variables to findmax prefix and suffix sums
    int bestLeftPrefixSum=0, bestRightPrefixSum=0;

    //finding max prefix sum
    int leftSubTreeMaxSum =0;
    int cm = 0;
    for(int i=start_index;i<=mid;i++){
        cm = max(cm+arr[i], 0);
        leftSubTreeMaxSum = max(leftSubTreeMaxSum, cm);
        bestLeftPrefixSum=max(bestLeftPrefixSum, prefixSum[i]-prefixSum[start_index]+arr[start_index]);
    };

    //finding max suffix sum
    int rightSubTreeMaxSum = 0;
    cm = 0;
    for(int i=mid+1;i<=end_index;i++){
        cm = max(cm+arr[i], 0);
        rightSubTreeMaxSum = max(rightSubTreeMaxSum, cm);
        bestRightPrefixSum=max(bestRightPrefixSum, suffixSum[i]-suffixSum[end_index]+arr[end_index]);
    };

    //filling value at current node
    tree[treeNode] = leftSubTreeMaxSum;
    tree[treeNode] = max(tree[treeNode], rightSubTreeMaxSum);
    tree[treeNode] = max(tree[treeNode], leftSum+bestRightPrefixSum);
    tree[treeNode] = max(tree[treeNode], rightSum+bestLeftPrefixSum);
}

int main(){
    int n;
    cout << "Enter size of array" << endl;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){cin>>arr[i];};
    int prefixSum[n], suffixSum[n];
    //initializaing suffix and prefix arrays
    for(int i=0;i<n;i++){
        prefixSum[i] = 0;
        suffixSum[i] = 0;
    };

    //filling suffix and prefix arrays
    prefixSum[0]=arr[0], suffixSum[n-1]=arr[n-1];
    for(int i=1;i<n-1;i++){
        int j = n-i-1;
        prefixSum[i]=prefixSum[i-1]+arr[i];
        suffixSum[j]=suffixSum[j+1]+arr[j];
    }
    prefixSum[n-1] = prefixSum[n-2]+arr[n-1], suffixSum[0] = suffixSum[1]+arr[0];
    //initalizing tree array
    int tree[4*n];
    for(int i=0;i<4*n;i++){tree[i]=0;};

    //filling tree
    buildTree(arr, tree, 0, n-1, 1, prefixSum, suffixSum);
    for(int i=0;i<4*n;i++){cout << tree[i]<< " ";};
    cout << "Max subarray sum:" << tree[1] << endl;
    return 0;
}