#include<bits/stdc++.h>
using namespace std;
using ll=long long;
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin>>n;
    set<int> val;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        val.insert(x);
    }
    cout<<val.size()<<"\n";
