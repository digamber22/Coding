// https://cses.fi/problemset/task/1651

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long

vector<ll> a;
vector<ll> seg;

void sg_tree_build(ll idx, ll low, ll high)
{
    if (low == high)
    {
        seg[idx] = a[low];
        return;
    }

    ll mid = (low + high) / 2;
    sg_tree_build(2 * idx + 1, low, mid);
    sg_tree_build(2 * idx + 2, mid + 1, high);

    seg[idx] = 0; // no update pending
}

void update(ll idx, ll low, ll high, ll l, ll r, ll val)
{
    if (low > r || high < l) return;

    if (low >= l && high <= r) {
        seg[idx] += val;
        return ;
    }
    ll mid = (low + high) / 2;

    update(2 * idx + 1, low, mid, l, r, val);
    update(2 * idx + 2, mid + 1, high, l, r, val);

}

 // imp 
ll query(ll idx, ll low, ll high, ll pos)
{   if(low==high) return seg[idx];
    
    ll mid = (low + high) / 2;
   
    if (mid >= pos) return seg[idx] + query(2 * idx + 1, low, mid, pos);    // imp add seg[idx] ; 

    else return seg[idx] + query(2 * idx + 2, mid + 1, high, pos);       // imp add seg[idx] ;
}


void solve()
{
    ll n, q;
    cin >> n >> q;

    a.assign(n + 1, 0);
    seg.assign(4 * n + 5, 0);

    for (ll i = 1; i <= n; i++)
        cin >> a[i];

    sg_tree_build(0, 1, n);

    while (q--)
    {
        ll x;
        cin >> x;

        if (x == 1)
        {
            ll l, r, u;
            cin >> l >> r >> u;
            update(0, 1, n, l, r, u);
        }

        else
        {
            ll p;
            cin >> p;
            cout << query(0, 1, n, p) << endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // ll t; cin >> t;
    ll t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}