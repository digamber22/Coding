// https://cses.fi/problemset/task/1136

#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

using pbds = tree<double , null_type, less_equal<double>, rb_tree_tag, tree_order_statistics_node_update >;

#define md 998244353
#define ll long long

const int N = 200001;
vector<vector<int>> tre(N);
int up[N][20];
int depth[N];
ll cnt[N];

void binary_lift(int src, int par) {
    up[src][0] = par;
    for (int i = 1; i < 20; i++) {
        if (up[src][i-1] != -1)
            up[src][i] = up[ up[src][i-1] ][i-1];
        else
            up[src][i] = -1;
    }
    for (auto child : tre[src]) {
        if (child == par) continue;
        depth[child] = depth[src] + 1;
        binary_lift(child, src);
    }
}

int lift_node(int node , int k) {
    for (int i = 0; i < 20 && node != -1; i++) {
        if (k & (1 << i)) node = up[node][i];
    }
    return node;
}

int get_lca(int a, int b) {

    if (depth[a] < depth[b]) swap(a, b);
    int diff = depth[a] - depth[b];

    a = lift_node(a, diff);
    if (a == b) return a;

    for (int i = 19; i >= 0; i--) {
        if (up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}

void dfs_count(int src, int par) {
    for (auto child : tre[src]) {
        if (child == par) continue;
        dfs_count(child, src);
        cnt[src] += cnt[child];   // prefix sum 
    }
}

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    // clear graph and arrays for nodes 1..n
    for (int i = 1; i <= n; i++) {
        tre[i].clear();
        depth[i] = 0;
        cnt[i] = 0;
        for (int j = 0; j < 20; j++) up[i][j] = -1;
    }

    // read edges
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        tre[u].push_back(v);
        tre[v].push_back(u);
    }

    // preprocess (root at 1)
    depth[1] = 0;
    binary_lift(1, -1);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        int lca = get_lca(a, b);
        // differenc array technique ;
        cnt[a]++;           // add at a
        cnt[b]++;           // add at b
        cnt[lca]--;         // subtract at lca
        if (up[lca][0] != -1)
            cnt[ up[lca][0] ]--; // subtract at parent(lca) if exists
    }

    // aggregate from children to parent
    dfs_count(1, -1);

    // output
    for (int i = 1; i <= n; i++) {
        cout << cnt[i] << " ";
    }
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
