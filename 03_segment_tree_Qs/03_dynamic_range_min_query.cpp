// https://cses.fi/problemset/task/1649   
 // step --> build Segment_tree, update , query .

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long 
vector<int>a;
vector<int>seg;
 
void sg_tree_build(int idx, int low, int high) {
  if(low==high){
   seg[idx] = a[low];
   return ;
  }

   ll mid = (low + high) /2;
  sg_tree_build(2*idx+1, low , mid);
  sg_tree_build(2*idx+2, mid+1, high);

  seg[idx] = min(seg[2*idx+1] , seg[2*idx+2] );
}

 void update(int idx, int low , int high , int pos, int val) {
    if(low==high) {
     seg[idx] = val;
     return ;
    }
    
    ll mid = (low+high)/2;
    
    if(mid>=pos) {
     update(2*idx+1, low, mid, pos, val);
    }else {
     update(2*idx+2, mid+1, high, pos, val);
    }
   
   seg[idx] = min(seg[idx*2+1], seg[2*idx+2]);
 }

 ll query(int idx, int low, int high , int l ,int r) {  
   if(low > r || high < l) return INT_MAX;
    
    if(low>=l && high <= r) return seg[idx];
   ll mid = (low+high)/2;
   
   ll left = query(2*idx+1, low ,mid , l ,r);
   ll right =  query(2*idx+2, mid+1, high , l, r);
  
  return min(left,right);
 }



void solve() {
 ll n, q; cin>>n>>q;

 a.assign(n+1,0);
 seg.assign(4*n+5, INT_MAX);  

 for(int i=1 ; i<=n ; i++) cin>>a[i];

 sg_tree_build(0,1,n);

  while(q--) {
    ll x; cin>>x; 
    if(x==1) {
    ll k, u; cin>>k>>u;
    update(0,1, n, k, u);
    }
    else {
     ll l ,r ;cin>>l>>r;
     cout<<query(0,1,n, l, r)<<endl;
    }
  }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // ll t; cin >> t;
    ll t = 1 ; 
    while (t--) {
        solve();
    }
    return 0;
}