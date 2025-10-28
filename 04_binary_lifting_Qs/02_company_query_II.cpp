// https://cses.fi/problemset/task/1688

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long

const int N = 200001;

vector<vector<ll>> tre(N);
int up[N][20];
int depth[N];

void binary_lift(int src, int par) {
    up[src][0] = par;   // represent src with (2^0 i.e 1) level up par. 

    // Precompute ancestors
    for (int i = 1; i < 20; i++) {
        if (up[src][i - 1] != -1)
            up[src][i] = up[up[src][i - 1]][i - 1];
        else
            up[src][i] = -1;
    }

    for (auto child : tre[src]) {
        if (child != par) {
            depth[child] = depth[src] + 1;   // Take care of depth store 
            binary_lift(child, src);
        }
    }
}

// Lift a node by k levels up
int lift_node(int node, int k) {

    for (int i = 0; i < 20; i++) {
        if (node == -1) break;
        if (k & (1 << i))
            node = up[node][i];
    }
    return node;
}

int get_ans(int a, int b) {
    // ensure a is deeper
    if (depth[a] < depth[b])
        swap(a, b);

    // lift a up to the same level as b
    int diff = depth[a] - depth[b];
    a = lift_node(a, diff);

    if (a == b) return a;

    // lift both until their parents match
    for (int i = 20 - 1; i >= 0; i--) {
        if (up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }
    // now parent of both is LCA
    return up[a][0];
}

void solve() {
    ll n, q;
    cin >> n >> q;

    for (int i = 0; i <= n; i++) {
        tre[i].clear();
        depth[i] = 0;
        for (int j = 0; j < 20; j++) up[i][j] = -1;
    }

    for (int i = 2; i <= n; i++) {
        ll x;
        cin >> x;
        tre[x].push_back(i);
        tre[i].push_back(x);
    }

    depth[1] = 0;
    binary_lift(1, -1);

    while (q--) {
        ll a, b;
        cin >> a >> b;
        cout << get_ans(a, b) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
