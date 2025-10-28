// https://cses.fi/problemset/task/1687

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define md 998244353
#define ll long long

vector<vector<int>>tre(200001);
int up[200001][20];

void binary_lifting(int src, int par) {
    up[src][0] = par;

  // first for src 
    for (int i = 1; i < 20; i++) {
        if (up[src][i - 1] != -1)
            up[src][i] = up[ up[src][i - 1] ][i - 1];
        else
            up[src][i] = -1;
    }
  
  // similarly for its child 
    for (int child : tre[src]) {
        if (child != par)
            binary_lifting(child, src);
    }
}

int ans_query(int node, int jump_required) {
    if (node == -1 || jump_required == 0)       // either reach (gives node) or out (give -1 as node)
        return node;

    for (int i = 19; i >= 0; i--) {
        if (jump_required >= (1 << i)) {
            return ans_query(up[node][i], jump_required - (1 << i));
        }
    }
    return node;
}

void solve() {
    ll n, q;
    cin >> n >> q;

    // clear tre and initialize
    for (int i = 1; i <= n; i++) {
        tre[i].clear();
        for (int j = 0; j < 20; j++) up[i][j] = -1;
    }

    // read edges (parent for nodes 2..n)
    for (int i = 2; i <= n; i++) {
        ll x;
        cin >> x;
        tre[x].push_back(i);
        tre[i].push_back(x);
    }

    // build binary lifting table
    binary_lifting(1, -1);

    // process queries
    while (q--) {
        int node, k;
        cin >> node >> k;
        cout << ans_query(node, k) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
