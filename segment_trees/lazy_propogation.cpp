#include<bits/stdc++.h>
//tree stores min element at every node 
using namespace std;
inline int min(int a, int b){ return (a>b?b:a);}
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
    tree[treeNode] = min(tree[2*treeNode],tree[2*treeNode+1]);
}
void updateST(int* tree, int* lazy, int si, int ei, int tN, int left, int right, int value){
    if(lazy[tN]!=0){
        //updating current node
        tree[tN]+=lazy[tN];
        //checking if child nodes exist
        if(si!=ei){
            //updating child nodes
            tree[2*tN]+=lazy[tN];
            tree[2*tN+1]+=lazy[tN];
        }
        lazy[tN] = 0;
    }
    //no overlap
    if(si>right || ei<left) return;
    //complete overlap
    if(left<=si && ei<=right){
        tree[tN]+=value;
        //checking if child nodes exist
        if(si!=ei){
            lazy[2*tN]+=value;
            lazy[2*tN+1]+=value;
        }
        return;
    }
    //partial overlap
    int mid = (si+ei)/2;
    updateST(tree, lazy, si, mid, 2*tN, left, right, value);
    updateST(tree, lazy, mid+1, ei, 2*tN+1, left, right, value);
    tree[tN] = min(tree[2*tN], tree[2*tN+1]);
}

int main(){
    int n;
    cout << "Enter size of array" << endl;
    cin >> n;
    cout << "Enter elements of array" << endl;
    int arr[n];
    for(int i=0;i<n;i++){cin >> arr[i];};
    int tree[4*n], lazy[4*n];
    for(int i=0;i<4*n;i++){tree[i]=0;lazy[i]=0;};
    buildTree(arr, tree, 0, n-1, 1);
    cout << "Enter update interval:"  << endl;
    int left, right;
    cin >> left >>right;
    cout << "Enter increment value:";
    int inc;
    cin >> inc;
    cout << "Minimum value before update: " << tree[1] << endl;
    updateST(tree, lazy, 0, n-1, 1, left, right, inc);
    cout << "Minimum value after update: " << tree[1] << endl;
    return 0;
}