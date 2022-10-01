#include<bits/stdc++.h>
using namespace std;
//problem: https://dmoj.ca/problem/coci13c1p4
struct Item{
    int weight;
    int value;

};
bool maxFirst(Item a, Item b){
    return a.value<b.value;
}
int main(){
    int n, k;
    Item items[n];
    for(int i=0;i<n;i++){
        cin >> items[i].weight >> items[i].value;
    };
    int bags[k];
    for(int i=0;i<k;i++){
        cin >> bags[i];
    };
    sort(items, items+n, maxFirst);
    //print sorted array
    sort(bags, bags+k, greater<int>());


    return 0;
}