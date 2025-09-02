// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/

class Solution {
public:
    bool check(int mid, int h, vector<int>& weights) {
        long long sum = 0, cnt = 1;
        for (int w : weights) {
            if (sum + w > mid) {
                cnt++;
                sum = 0;
            }
            sum += w;
        }
        return cnt <= h;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);
        int ans = r;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(mid, days, weights)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};
