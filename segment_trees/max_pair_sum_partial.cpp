#include<bits/stdc++.h>
using namespace std;

struct Node{
    int max=INT_MIN;
    int s_max=INT_MIN;
};
void buildTree(int* arr, Node* tree, int start_index, int end_index, int treeNode){
    //base case
    if(start_index==end_index){
        tree[treeNode].max = arr[start_index];
        return;
    }
    int mid = (start_index+end_index)/2;
    //filling left subtree
    buildTree(arr, tree, start_index, mid, 2*treeNode);
    //filling right subtree
    buildTree(arr, tree, mid+1, end_index, 2*treeNode+1);
    //filling current node
    //left child -> 2*treeNode, right child -> 2*treeNode+1
    if(tree[2*treeNode].max>tree[2*treeNode+1].max) {
        tree[treeNode].max = tree[2*treeNode].max;
        tree[treeNode].s_max = (tree[2*treeNode].s_max>tree[2*treeNode+1].max?tree[2*treeNode].s_max:tree[2*treeNode+1].max);
    }
    else {
        tree[treeNode].max = tree[2*treeNode+1].max;
        tree[treeNode].s_max = (tree[2*treeNode+1].s_max>tree[2*treeNode].max?tree[2*treeNode+1].s_max:tree[2*treeNode].max);
    }
}

int main(){
    int n;
    cout << "Enter size of array" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter elements of array" << endl;
    for(int i=0;i<n;i++){cin >> arr[i];};
    Node tree[4*n];
    buildTree(arr, tree, 0, n-1, 1);
    cout << "Max pair sum:" << tree[1].max+tree[1].s_max << endl;
    return 0;
}