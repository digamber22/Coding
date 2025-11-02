// https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/
// TC,SC -> O(n*d);

class Solution {
public:
    using ll = long long;
    const ll INF = 1e15;
    vector<vector<ll>>dp;
    ll n;

    ll fn(ll ind, ll days, const vector<int>& job) {

        if (days < 0) return INF;
        if (ind >= n) return (days == 0 ? 0 : INF);

        if (dp[ind][days] != -1) return dp[ind][days];

        ll ans = INF, curMax = 0;
        for (ll i = ind; i < n; ++i) {

            curMax = max(curMax, (ll)job[i]);
            ll val = fn(i + 1, days - 1, job);
            ans = min(ans, curMax + val);

        }
        return dp[ind][days] = ans;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
         n = jobDifficulty.size();
        if (n < d) return -1;

         dp.assign(n + 1, vector<ll>(d + 1, -1));

        ll res = fn(0, d, jobDifficulty);
        return res >= INF ? -1 : (int)res;
    }
};
