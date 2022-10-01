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

    //fill value at current node, after filling child subtrees
    tree[treeNode] = tree[2*treeNode]+tree[2*treeNode+1];
}

void updateTree(int* arr, int* tree, int start_index, int end_index, int treeNode, int update_index, int update_value){
    //base case
    if(start_index==end_index){
        //this will only happen for the index=update_index
        arr[update_index] = update_value;
        tree[treeNode] = update_value;
        return;
    }

    //finding mid
    int mid = (start_index+end_index)/2;
    
    //checking which subtree to traverse
    if(mid>update_index){
        //traverse the left half
        updateTree(arr, tree, start_index, mid, 2*treeNode, update_index, update_value);
    }else{
        //traverse the right half
        updateTree(arr, tree, mid+1, end_index, 2*treeNode+1, update_index, update_value);
    }
    //update value at current node, after updating child subtrees
    tree[treeNode] = tree[2*treeNode]+tree[2*treeNode+1];

}

int query(int* tree, int start_index, int end_index, int treeNode, int left, int right){
    //completely outside range -> out of bound or no overlap
    if(left>end_index || right<start_index) return 0;
    
    //completely inside range
    if(left<=start_index && end_index<=right) return tree[treeNode];

    //partially inside and partially outside
    int mid = (start_index+end_index)/2;
    int ans_from_left_subtree = query(tree, start_index, mid, 2*treeNode, left, right);
    int ans_from_right_subtree = query(tree, mid+1, end_index, 2*treeNode+1, left, right);
    return ans_from_left_subtree+ans_from_right_subtree;
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
    cout << "Enter update index: ";   
    int update_index;
    cin >> update_index;
    cout << "Enter update value: ";
    int update_value;
    cin >> update_value;
    updateTree(arr, tree, 0, n-1, 1, update_index, update_value);
    cout << "The updated tree" << endl;
    for(int i=0;i<2*n;i++){cout << i <<" " << tree[i] << endl;};
    cout << "updated array" << endl;
    for(int i=0;i<n;i++){cout << arr[i] << " ";};
    cout << endl;
    cout << "Enter range for query" << endl;
    int left, right;
    cin >> left >> right;
    cout << "Answer for the range: " << query(tree, 0, n-1, 1, left, right) << endl;
    return 0;
}