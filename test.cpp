#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    int x, y, z;
	    cin >> x >> y >>z;
	    int cnt[4];
        for(int i=0;i<4;i++){cnt[i]=0;};
	    cnt[x%4]++;
	    cnt[y%4]++;
	    cnt[z%4]++;
	    int ans=-1;
	    if(cnt[3]==3){
	        ans = 6;
	    }
	    else if(cnt[3]==2){
	        if(cnt[2]==1||cnt[1]==1) ans=5;
	        else ans = 3;
	     
	    }
	    else if(cnt[3]==1){
	        if(cnt[2]==2) ans=5;
	        else if(cnt[2]==1 && cnt[1]==1) ans=3;
	        else if(cnt[2]==1 && cnt[0]==1) ans=3;
	        else if(cnt[1]==2) ans=3;
	        else if(cnt[1]==1 && cnt[0]==1) ans=2;
	        else if(cnt[0]==2) ans=1;
	        
	    }
	    else{
	        if(cnt[2]==3) ans=4;
	        else if(cnt[2]==2 && cnt[1]==1) ans =4;
	        else if(cnt[1]==2) ans=3;
	        else if(cnt[0]==2) ans=1;
	        else ans = 2;
	    }
	   cout << ans << endl; 
	};

	return 0;
}
