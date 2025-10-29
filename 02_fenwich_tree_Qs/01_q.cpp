#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define md 998244353
#define ll long long
 // tc -> O(Q log n ) , sc -> O(n) ; 

vector<int> bit;
int n, q;

void update(int i, int val) {
    for (; i <= n; i += (i & -i))
        bit[i] += val;
}

int q_sum(int i) {
    int sum = 0;
    for (; i > 0; i -= (i & -i))
        sum += bit[i];
    return sum;
}

void solve() {
    cin >> n >> q;
    vector<int> a(n + 1); // 1-based indexing for BIT
    bit.assign(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        update(i, a[i]); // build BIT as we read input
    }

    vector<pair<int, int>> qur;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        qur.push_back({l, r});
    }

    vector<int> ans;
    for (auto it : qur) {
        ans.push_back(q_sum(it.second) - q_sum(it.first - 1));
    }

    for (auto it : ans)
        cout << it << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
