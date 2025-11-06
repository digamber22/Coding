#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
vector<int> A;
vector<vector<int>> adj;
vector<ll> ans;
vector<int> D; // stores divisor count for each number

// -------------------------------------------------------------------
// Precomputes the number of divisors for all integers up to maxA.
// D[x] = count of divisors of x
// Time: O(maxA * log(maxA))
void precompute_divisors(int maxA) {
    D.assign(maxA + 1, 0);
    for (int i = 1; i <= maxA; ++i)
        for (int j = i; j <= maxA; j += i)
            D[j]++;  // increment divisor count for all multiples of i
}

// -------------------------------------------------------------------
// DFS function that returns a frequency map of values in the subtree.
// cur[value] = count of 'value' in the subtree rooted at node u.
// It also calculates ans[u] = Σ (D[value] * count^2) for its subtree.
unordered_map<int, int> dfs(int u, int p) {
    unordered_map<int, int> cur;
    cur[A[u]] = 1; // initialize with its own value

    // Traverse all children
    for (int v : adj[u]) {
        if (v == p) continue;
        auto child = dfs(v, u);  // get frequency map from child subtree

        // Small-to-large merging optimization:
        // Always merge smaller map into larger one to reduce total work.
        if (child.size() > cur.size()) swap(child, cur);

        // Merge all entries from child into current map
        for (auto &pr : child)
            cur[pr.first] += pr.second;
    }

    // After merging all children, 'cur' now contains full subtree frequencies.

    // Calculate DivisorPower(u)
    // For each distinct value in subtree(u):
    // ans[u] = Σ D[value] * (count_in_subtree(value))^2
    ll val = 0;
    for (auto &pr : cur) {
        int value = pr.first;
        ll cnt = pr.second;
        val += (ll)D[value] * cnt * cnt;
    }
    ans[u] = val;  // store the final result for this node

    return cur; // return merged frequency map to parent
}

// -------------------------------------------------------------------
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    A.resize(N + 1);
    adj.assign(N + 1, {});
    int maxA = 0;

    // Input node values and track maxA for divisor precomputation
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
        maxA = max(maxA, A[i]);
    }

    // Read edges of the tree (undirected)
    for (int i = 0; i < N - 1; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // Precompute divisor counts for all numbers up to maxA
    precompute_divisors(maxA);

    ans.assign(N + 1, 0);

    // Start DFS from root (assuming node 1)
    dfs(1, 0);

    // Print DivisorPower for each node
    for (int i = 1; i <= N; ++i)
        cout << ans[i] << (i == N ? '\n' : ' ');
}
