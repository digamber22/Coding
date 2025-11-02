// https://leetcode.com/problems/partition-array-for-maximum-sum/
// TC, SC -> O(n*k) ; 

class Solution {
public:
    int n;
    vector<int> dp;

    int get_val(int idx, vector<int>& nums, int k) {
        if (idx == n) return 0;

        int& res = dp[idx];
        if (res != -1) return res;

        int maxi = INT_MIN, mxans = INT_MIN, len = 0;

        for (int j = idx; j < min(idx + k, n); j++) {
            len++;
            maxi = max(maxi, nums[j]);

            int scr = maxi * len + get_val(j + 1, nums, k);
            mxans = max(scr, mxans);
        }
        return res = mxans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();

        dp.assign(n, -1);
        return get_val(0, arr, k);
    }
};