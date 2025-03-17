#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
const int mxN = 2e5;
 
int main() {
	int n,q;
	cin>>n>>q;
	vector<ll> nums(n+1);
	for(int i=1;i<=n;i++){
	    cin>>nums[i];
	}
	
	for(int i=2;i<=n;i++) nums[i]=nums[i]+nums[i-1];
	
	for(int i=0;i<q;i++){
	    int a,b;
	    cin>>a>>b;
	    ll res = nums[b]-nums[a-1];
	    cout<<res<<"\n";
	    
	}
	
 
}
