#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int main() {
	int n;
	cin>>n;
	vector<int> a(n);
	vector<vector<int>> b(N);
	for(int i=0;i<n;i++){
	    cin>>a[i];
	}
	
	for(int i=2;i<N;i++){
	    if(b[i].size()==0){
	        b[i].push_back(i);
	        for(int j=2*i;j<N;j+=i){
	            b[j].push_back(i);
	        }
	    }
	}
	
	vector<int> A(N,0),B(N,0);
	
	for(int i=0;i<n;i++){
	    for(int mask=1;mask<(1<<b[a[i]].size());mask++){
	        int comb = 1;
	        int cnt = 0;
	        
	        for(int j=0;j<b[a[i]].size();j++){
	            if(mask & (1<<j)){
	                comb*=b[a[i]][j];
	                cnt+=1;
	            }
	        }
	        
	        A[comb]++;
	        B[comb]=cnt;
	    }
	}
	
	long long tot = (1l*n*(n-1))/2;
    long long res = 0;
    
    for(int i=0;i<N;i++){
        long long val = (1l*A[i]*(A[i]-1))/2;
        if(B[i]%2==1){
            res+=val;
        }
        else {
            res-=val;
        }
    }
	
	
    cout<<tot - res<<"\n";
}
