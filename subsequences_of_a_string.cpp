#include<bits/stdc++.h>
using namespace std;
void subseq(int i, string ss, string s){
    if(i<0){
        cout << ss << endl;
        return;
    }
    subseq(i-1, ss+s[i],s);
    subseq(i-1, ss, s);

}
int main(){
    string s = "012345";
    subseq(s.size()-1, "", s);
    return 0;
    
}