// https://cses.fi/problemset/task/1647/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long

ll n;
vector<ll> a;        // values (1-indexed)
vector<ll> seg;      // segment tree

void st_build(ll idx, ll low, ll high) {
    if (low == high) {
        seg[idx] = a[low];
        return;
    }
    ll mid = (low + high) / 2;
    st_build(2*idx + 1, low, mid);
    st_build(2*idx + 2, mid + 1, high);
    seg[idx] = min(seg[2*idx + 1], seg[2*idx + 2]);
}

ll query(ll idx, ll low, ll high, ll l, ll r) {
    // no overlap
    if (r < low || l > high) return LLONG_MAX;
    // complete overlap
    if (l <= low && high <= r) return seg[idx];

    ll mid = (low + high) / 2;
    ll left = query(2*idx + 1, low, mid, l, r);
    ll right = query(2*idx + 2, mid + 1, high, l, r);
    return min(left, right);
}

void solve() {
    ll q;
    if (!(cin >> n >> q)) return;

    // keep array 1-indexed (you're reading into a[1..n])
    a.assign(n + 1, 0);
    for (ll i = 1; i <= n; ++i) cin >> a[i];

    // a bit of extra buffer for seg
    seg.assign(4 * n + 5, LLONG_MAX);

    st_build(0, 1, n);

    while (q--) {
        ll l, r;
        cin >> l >> r;
        cout << query(0, 1, n, l, r) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    while (t--) solve();
    return 0;
}
