// https://leetcode.com/problems/palindrome-pairs/description/
 // solve this using 4 method, hashMap --> O(n*k) , map , trie --> O(n * k^2) , Brute force -> O(n^2 * k) ;  

 // USING hashMap
 
 #include <bits/stdc++.h>
using namespace std;
#define ll long long 
// TC ,SC -> O(n*k) ; 

struct WordHash {
    vector<ll> pref, suff, powp;
    ll base = 131, mod = 1e9 + 7;

    WordHash(string &s) {
        int n = s.size();
        pref.assign(n + 1, 0);
        suff.assign(n + 2, 0);
        powp.assign(n + 1, 1);

        for (int i = 1; i <= n; i++) 
            powp[i] = (powp[i - 1] * base) % mod;

        for (int i = 0; i < n; i++)
            pref[i + 1] = (pref[i] * base + s[i]) % mod;

        for (int i = n - 1; i >= 0; i--)
            suff[i] = (suff[i + 1] * base + s[i]) % mod;
    }

    ll get_pref(int l, int r) {
        return (pref[r + 1] - pref[l] * powp[r - l + 1] % mod + mod) % mod;
    }

    ll get_suff(int l, int r, int n) {
        return (suff[l] - suff[r + 1] * powp[r - l + 1] % mod + mod) % mod;
    }

    bool is_pal(int l, int r, int n) {
        return get_pref(l, r) == get_suff(l, r, n);
    }
};

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        unordered_map<string, int> idx;
        vector<vector<int>> ans;

        // Step 1: store all reversed words
        for (int i = 0; i < n; i++) {
            string t = words[i];
            reverse(t.begin(), t.end());
            idx[t] = i;
        }

        // Step 2: for each word, check all splits
        for (int i = 0; i < n; i++) {
            string &w = words[i];
            int len = w.size();
            WordHash H(w);

            for (int cut = 0; cut <= len; cut++) {
                // left = w[0..cut-1], right = w[cut..len-1]

                // Case 1: prefix palindrome → need reverse(right)
                if (cut > 0 && H.is_pal(0, cut - 1, len)) {
                    string t = w.substr(cut);
                    if (idx.count(t) && idx[t] != i)
                        ans.push_back({idx[t], i});
                }

                // Case 2: suffix palindrome → need reverse(left)
                if (H.is_pal(cut, len - 1, len)) {
                    string t = w.substr(0, cut);
                    if (idx.count(t) && idx[t] != i)
                        ans.push_back({i, idx[t]});
                }
            }
        }

        return ans;
    }
};