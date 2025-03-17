#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
typedef int item;
// struct item{
//     ll seg,pref,suff,sum;
// };
struct segtree{
    int size;
    vector<item> values;
    
    item NEUTRAL_ELEMENT = INT_MAX;
    
    item single(int v){
        return v;
    }
 
    item combine(item a, item b){
        return min(a,b);
    }
 
    void init(int n){
        size = 1;
        while(size<n) size*=2;
        values.resize(2*size);
    }
 
    void build(vector<int> &a){
        size = 1;
        while(size<(int)a.size()) size*=2;
        values.resize(2*size);
        build(a,0,0,size);
    }
 
    void build(vector<int> &a,int x, int lx,int rx){
        if(rx-lx==1){
            if(lx<(int)a.size())
            {
                values[x]=single(a[lx]);
            }
            return;
        }
 
        int mx = (lx + rx) / 2;
        build(a,2*x+1, lx, mx);
        build(a,2*x+2, mx, rx);
        values[x] = combine(values[2*x+1], values[2*x+2]);
    }
 
    void set(int i, int v){
        set(i,v,0,0,size);
    }
 
    void set(int i, int v, int x, int lx, int rx){
        if(rx-lx==1){
            if(x<values.size()){
                values[x]=single(v);
                return;
            }           
        }
 
        int mx = (lx + rx) / 2;
        if(i<mx) set(i,v,2*x+1,lx,mx);
        else set(i,v,2*x+2,mx,rx);
        values[x]=combine(values[2*x+1],values[2*x+2]);
    }
 
    item calc(int l, int r){
        return calc(l,r,0,0,size);
    }
 
    item calc(int l, int r,int x, int lx, int rx){
        if(lx>=r || rx<=l){
            return NEUTRAL_ELEMENT;
        }
        
        if(lx>=l && rx<=r){
            return values[x];
        }
 
        int mx = (lx + rx)/2;
        auto left = calc(l,r,2*x+1,lx,mx);
        auto right = calc(l,r,2*x+2,mx,rx);
        return combine(left,right);
    }
    
    int find(int k,int x,int lx,int rx){
        if(rx-lx==1){
            return lx;
        }
        int m = (lx+rx)/2;
        
        int sl = values[2*x+1];
        if(k<sl){
            return find(k,2*x+1,lx,m);
        }
        else{
            return find(k-sl,2*x+2,m,rx);
        }
    }
    
    int find(int k){
        return find(k,0,0,size);
    }
    
    int first_above(int v,int l,int x,int lx,int rx){
        if(values[x]<v){
            return -1;
        }
        if(rx<=l){
            return -1;
        }
        if(rx-lx==1){
            return lx;
        }
        int m = (lx + rx)/2;
        int res = first_above(v,l,2*x+1,lx,m);
        if(res==-1) res = first_above(v,l,2*x+2,m,rx);
        return res;
        
    }
    
    int first_above(int v,int l){
        return first_above(v,l,0,0,size);
    }
};
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n,m;
    cin>>n>>m;
    segtree st;
    vector<int> a(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    st.build(a);

    while(m--){
        int a,b;
        cin>>a>>b;
        a--;
        b;
        cout<<st.calc(a,b)<<"\n";
        
    }
 
    return 0;
}
