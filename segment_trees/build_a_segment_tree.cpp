#include<bits/stdc++.h>

using namespace std;

void buildTree(int* arr, int* tree, int start_index, int end_index, int treeNode){
    //base case
    if(start_index==end_index){
        tree[treeNode] = arr[start_index];
        return;
    }
    //mid is found to divide current subarray in consideration into two halves
    int mid = start_index+(end_index-start_index)/2;

    //recursive call to fill left child -> 2*treeNode (index of left child node)
    buildTree(arr, tree, start_index, mid, 2*treeNode);

    //recursive call to fill right child -> 2*treeNode+1 (index of right child node)
    buildTree(arr, tree, mid+1, end_index, 2*treeNode+1);

    //fill value at current node
    tree[treeNode] = tree[2*treeNode]+tree[2*treeNode+1];
}

int main(){
    int n;
    cout << "Enter size of array" << endl;
    cin >> n;
    cout << "Enter elements of array" << endl;
    int arr[n];
    for(int i=0;i<n;i++){cin >> arr[i];};
    // creating tree array of size 2*n(max elements in tree will be 2*n-1)
    int tree[2*n];
    for(int i=0;i<2*n;i++){tree[i]=0;};
    buildTree(arr, tree, 0, n-1, 1);
    cout << "Nodes of the filled tree:" << endl;
    for(int i=0;i<2*n;i++){cout << i <<" " << tree[i] << endl;};
    return 0;
}