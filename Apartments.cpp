#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld = long double;
using db = double; 
using str = string; 
 
using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;
 
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvb = vector<vb>;
using vvl = vector<vl>;
using vd = vector<db>; 
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>; 
using vpd = vector<pd>;
 
using si = unordered_set<int>;
using sl = unordered_set<ll>;
using tsi = set<int>;
using tsl = set<ll>;
 
using mii = unordered_map<int, int>;
using mll = unordered_map<ll, ll>;
using tmii = map<int, int>;
using tmll = map<ll, ll>;
 
#define mp make_pair
#define f first
#define s second
 
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend() 
#define sor(x) sort(all(x)) 
#define rsz resize
#define ins insert 
#define ft front() 
#define bk back()
#define pf push_front 
#define pb push_back
#define eb emplace_back 
#define lb lower_bound 
#define ub upper_bound 
 
#define rep(i,a) repp(i,0,a)
#define repp(i,a,b) for (int i = (a); i < (b); ++i)
#define reppp(i, a, b, d) for (int i = (a); (d) > 0 ? i < (b) : i > (b); i += (d))
 
#ifndef ONLINE_JUDGE
#include "template.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif
 
void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	vector<int> a(n);
	vector<int> b(m);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		cin>>b[i];
	}
	sort(all(a));
	sort(all(b));
 
	int i = 0;
	int j = 0;
	int matches = 0;
	while(i<n){
		while(j<m && b[j]<a[i]-k){
			j++;
		}
		if(abs(a[i]-b[j]) <= k){
			matches++;
			i++;
			j++;
		}
		else i++;
	}
 
	cout<<matches<<"\n";
	
 
 
}
 
int main()
{	
	int t = 1;
	// cin>>t;
	for(int i=0;i<t;i++){
		solve();
	}
	return 0;
}
