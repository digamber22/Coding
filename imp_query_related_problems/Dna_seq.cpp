// https://leetcode.com/discuss/post/6163543/dp-hard-ques-by-anonymous_user-aore/

#include <bits/stdc++.h>
using namespace std;

// Function to count number of 1-bits in a mask
int countBits(int mask) {
    return __builtin_popcount(mask);
}

long long getTotalPalindromeTransformationCost(const string &dna) {
    int n = dna.size();
    unordered_map<int, long long> freqMap;
    long long totalCost = 0;

    int prefixMask = 0;
    freqMap[prefixMask] = 1; // Empty prefix

    for (char ch : dna) {
        // Update mask: flip the bit corresponding to current character
        prefixMask ^= (1 << (ch - 'a'));

        // Substrings ending here with same mask -> all characters even -> cost = 0
        totalCost += 0; // handled below in counting

        // Count number of 1-bits = odd characters in substring
        // Cost = floor(odd_count / 2)
        for (auto &[mask, count] : freqMap) {
            int oddCount = countBits(prefixMask ^ mask);
            totalCost += oddCount / 2;
        }

        // Update map
        freqMap[prefixMask]++;
    }

    return totalCost;
}

int main() {
    string dna;
    cin >> dna;

    long long ans = getTotalPalindromeTransformationCost(dna);
    cout << ans << "\n";

    return 0;
}
