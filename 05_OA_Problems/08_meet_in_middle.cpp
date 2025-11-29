// https://cses.fi/problemset/task/1628/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define md 998244353
#define ll long long
#define all(x) x.begin(), x.end()
#define vi vector<ll>
#define vii vector<pair<ll, ll>>
#define stk stack<ll>
#define que queue<ll>
#define pq priority_queue<ll>
#define st set<ll>
#define loop(i, a, b) for (ll i = a; i < b; i++)
#define lp(i, a, b) for (ll i = a; i <= b; i++)
#define rloop for (ll i = n - 1; i >= 0; i--)
#define us unordered_set<ll>
#define ump unordered_map<ll, ll>

void solve()
{
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    ll mid = n / 2;
    ll size1 = mid;
    ll size2 = n - mid;

    // generate sums for second half and count frequencies
    unordered_map<ll, ll> cnt2;
    cnt2.reserve(1 << min(20LL, size2)); // small optimization
    
    for (ll mask = 0; mask < (1LL << size2); ++mask)
    {
        ll s = 0;
        for (ll j = 0; j < size2; ++j)
        {
            if (mask & (1LL << j))
                s += a[mid + j];
        }
        cnt2[s]++;
    }

    // enumerate sums for first half and add matches
    ll ans = 0;
    for (ll mask = 0; mask < (1LL << size1); ++mask)
    {
        ll s = 0;
        for (ll j = 0; j < size1; ++j)
        {
            if (mask & (1LL << j))
                s += a[j];
        }
        ll need = x - s;
        if (cnt2.find(need) != cnt2.end())
            ans += cnt2[need];
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
