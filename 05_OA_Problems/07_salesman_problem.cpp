// https://www.geeksforgeeks.org/dsa/travelling-salesman-problem-using-dynamic-programming/

class Solution {
  public:
    int dp[21][1<<20];

    int fn(int i,int mask,vector<vector<int>>& c) {
        int n = c.size();
        
        if (mask == (1<<n) - 1) return c[i][0];
        if (dp[i][mask] != -1) return dp[i][mask];
        
        int ans = 1e9;
        
        for (int x = 0; x < n; x++) {
            if ( ((1 << x) & mask) == 0 ) {            
                ans = min(ans, c[i][x] + fn(x, mask | (1<<x), c));
            }
        }
        return dp[i][mask] = ans;
    }

    int tsp(vector<vector<int>>& c) {

        int n = c.size();
        memset(dp, -1, sizeof(dp));
        
        return fn(0, 1, c); // start at node 0 with bit 0 set
    }
};
