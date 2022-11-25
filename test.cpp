#include<bits/stdc++.h>
using namespace std;

void buildTree(int* tree, int* arr, int startIndex, int endIndex, int treeNode){
	if(startIndex==endIndex){
		tree[treeNode] = arr[startIndex];
		return; 
	}
	int mid = (startIndex+endIndex)/2;
	buildTree(tree, arr, startIndex, mid, 2*treeNode);
	buildTree(tree, arr,mid+1,endIndex,  2*treeNode+1);
	tree[treeNode] = tree[2*treeNode]+tree[2*treeNode+1];

void updateTree(int* tree, int* arr, int startIndex, int endIndex, int treeNode, int updateIndex){
	if(startIndex==endIndex){
		arr[updateIndex] = arr[updateIndex]=='1'?'0':'1';
		tree[treeNode] = arr[updateIndex];
		return;
	}
	int mid = (startIndex+endIndex)/2;
	if(mid>updateIndex) updateTree(tree, arr, startIndex, mid, 2*treeNode, updateIndex);
	else updateTree(tree, arr, mid+1, endIndex, 2*treeNode+1, updateIndex);
	tree[treeNode] = tree[2*treeNode]+tree[2*treeNode+1];
}

string queryTree(int* tree, int* arr, int startIndex, int endIndex, int treeNode, int left, int right){
	//completely outside
	if(startIndex>right || endIndex<left) return "";
	//complete inside
	if(startIndex>=left && endIndex<=right) return tree[treeNode];
	//partially inside and partially outside
	int mid = (startIndex+endIndex)/2;
	string leftTree = queryTree(tree, arr, startIndex, mid, 2*treeNode, left, right);
	string rightTree = 	queryTree(tree, arr, mid+1, endIndex, 2*treeNode+1, left, right);
	return leftTree+rightTree;
}

int main(){
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	int* tree = new int[4*n];
	buildTree()
	return 0;
}