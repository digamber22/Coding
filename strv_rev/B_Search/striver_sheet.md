# DSA Revision Sheet

A comprehensive collection of Data Structures and Algorithms problems, notes, and patterns.

## 📚 Table of Contents
- [Arrays](#arrays)
- [Binary Search](#binary-search)
- [Strings](#strings)
- [Recursion](#recursion)
- [Bit Manipulation](#bit-manipulation)
- [Stack and Queue](#stack-and-queue)
- [Sliding Window & Two Pointer](#sliding-window--two-pointer)
- [Heap](#heap)
- [Greedy](#greedy)
- [Graph](#graph)
- [Dynamic Programming (DP)](#dynamic-programming-dp)
- [Binary Trees](#binary-trees)
- [Binary Search Tree (BST)](#binary-search-tree-bst)
- [Trie](#trie)
- [Linked List](#linked-list)
- [Cheat Sheets & Patterns](#cheat-sheets--patterns)

---

## Arrays

| ID | Status | Problem | Notes | Link |
|:---:|:---:|:---|:---|:---:|
| 1 | | Longest subarray with sum = k | | [GFG](https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1) |
| 2 | | Two sum | | [LeetCode](https://leetcode.com/problems/two-sum/) |
| 3 | ⭐ | **Print Maximum sub array** | | [GFG](https://www.geeksforgeeks.org/print-the-maximum-subarray-sum/) |
| 4 | | Buy and sell stock | | [LeetCode](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) |
| 5 | | Next permutation | | [LeetCode](https://leetcode.com/problems/next-permutation/) |
| 6 | | Longest consecutive subsequence | | [LeetCode](https://leetcode.com/problems/longest-consecutive-sequence/) |
| 7 | | Spiral Matrix | | [LeetCode](https://leetcode.com/problems/spiral-matrix/) |
| 8 | | No. of Subarray sum = k | | [LeetCode](https://leetcode.com/problems/subarray-sum-equals-k/) |
| 9 | | 3sum | | [LeetCode](https://leetcode.com/problems/3sum/) |
| | | 4sum | *Note below* | [LeetCode](https://leetcode.com/problems/4sum/) |
| 10 | | Largest subarray sum = 0 | | [GFG](https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1) |
| 11 | | Count subarray with given XOR = k | | [GFG](https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/1) |
| 12 | | Merge interval | | [LeetCode](https://leetcode.com/problems/merge-intervals/) |
| 13 | | Count Inversion | | [GFG](https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1) |
| 14 | | Reverse Pair | | [LeetCode](https://leetcode.com/problems/reverse-pairs/) |

> **C++ Note for 4Sum:**
> ```cpp
> vector<int> temp = {nums[i], nums[j], nums[k], nums[l]}; // don’t use ( ) open bracket during initialization
> ans.push_back({nums[i], nums[j], nums[k], nums[l]});
> ```

---

## Binary Search

| Category | Problem | Notes | Link |
|:---|:---|:---|:---:|
| **1D Array** | Search in a rotated sorted array | *With duplicate (e.g., `3 1 2 3 3`). Target exists in rotated part.* | [LeetCode](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/) |
| | Find minimum in rotated sorted array | | [LeetCode](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/) |
| | Find Peak Elements | | [LeetCode](https://leetcode.com/problems/find-peak-element/) |
| | Implement `upper_bound` | | [GFG](https://www.geeksforgeeks.org/upper_bound-in-cpp/) |
| **Answers** | Square root using BS | *Similarly find nth root of no. using BS* | [LeetCode](https://leetcode.com/problems/sqrtx/) |
| | Aggressive cows | | [GFG](https://www.geeksforgeeks.org/problems/aggressive-cows/0) |
| | Allocate minimum pages | | [GFG](https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1) |
| | Min days to make m bouquets | | [LeetCode](https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/) |
| **2D Array** | Search in 2D matrix | | [LeetCode](https://leetcode.com/problems/search-a-2d-matrix/) |

---

## Strings

| ID | Status | Problem | Notes | Link |
|:---:|:---:|:---|:---|:---:|
| 1 | | Remove outermost parentheses | | [LeetCode](https://leetcode.com/problems/remove-outermost-parentheses/) |
| 2 | | Isomorphic string | | [LeetCode](https://leetcode.com/problems/isomorphic-strings/) |
| 3 | | Sort char by freq | | [LeetCode](https://leetcode.com/problems/sort-characters-by-frequency/) |
| 4 | ⭐ | **Count Substring consisting only a,b,c** | `O(n)` | [LeetCode](https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/) |
| 5 | | Longest palindrome substring | *Without DP* | [LeetCode](https://leetcode.com/problems/longest-palindromic-substring/) |

---

## Recursion

| ID | Status | Problem | Notes | Link |
|:---:|:---:|:---|:---|:---:|
| 1 | | Recursive implementation of atoi | | [LeetCode](https://leetcode.com/problems/string-to-integer-atoi/) |
| 2 | | Generate parentheses | `OpenP < n`, `closeP < OpenP` | [LeetCode](https://leetcode.com/problems/generate-parentheses/) |
| 3 | | Subsets / Power sets | Generate all subsets | [LeetCode](https://leetcode.com/problems/subsets/) |
| 4 | | Combination sum 1 | With dup | [LeetCode](https://leetcode.com/problems/combination-sum/) |
| | | Combination sum 2 | Unique | [LeetCode](https://leetcode.com/problems/combination-sum-ii/) |
| 5 | | Subsets 2 | Unique | [LeetCode](https://leetcode.com/problems/subsets-ii/) |
| 6 | ⭐ | **Letter combination of phone no.** | | [LeetCode](https://leetcode.com/problems/letter-combinations-of-a-phone-number/) |
| 7 | left.... (solve soon )
---

## Bit Manipulation

### Basic Operations Table
| Operation | Formula |
|:---|:---|
| Check Power of 2 | `(n & (n-1)) == 0` |
| Count set bits | `__builtin_popcount(n)` |
| Check if kth bit is set | `(n & (1<<k)) == 1` |
| Set rightmost unset bit |  `n or (n+1)` |
| Swap two numbers | `a = a^b; b = a^b; a = a^b;` |
| Diff bits between two nums | `__builtin_popcount(a^b)` |

### Problems
| ID | Status | Problem | Notes | Link |
|:---:|:---:|:---|:---|:---:|
| 1 | | Divide two numbers | Without `/`, `*` operators | [LeetCode](https://leetcode.com/problems/divide-two-integers/) |
| 2 | | Find XOR b/w L to R | `O(1)` Pattern found | [GFG](https://www.geeksforgeeks.org/find-xor-of-numbers-from-the-range-l-r/) |
| 3 | ⭐ | **Find two numbers appearing odd times** | `right_most_bit = (x & (x-1)) ^ x` | [LeetCode](https://leetcode.com/problems/single-number-iii/) |
| 4 | | Power set using bitmask | | [LeetCode](https://leetcode.com/problems/subsets/) |

---

## Stack and Queue

| ID | Status | Problem | Notes | Link |
|:---:|:---:|:---|:---|:---:|
| 1 | | Next greater element I | | [LeetCode](https://leetcode.com/problems/next-greater-element-i/) |
| 2 | | Trapping rain water | I & II | [LeetCode](https://leetcode.com/problems/trapping-rain-water/) |
| 3 | | No. of greatest elements to the right | Solved `N*Q`, `O(n log n)` needs merge sort where i<j , a[i]<a[j] | [GFG](https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1) |
| 4 | | Sum of subarray range | | [LeetCode](https://leetcode.com/problems/sum-of-subarray-ranges/) |
| 5 | | Asteroids collision | | [LeetCode](https://leetcode.com/problems/asteroid-collision/) |
| 6 | | Remove k digits | | [LeetCode](https://leetcode.com/problems/remove-k-digits/) |
| 7 | | Largest rectangle in a histogram | | [LeetCode](https://leetcode.com/problems/largest-rectangle-in-histogram/) |
| 8 | ⭐ | **Maximum rectangle** | | [LeetCode](https://leetcode.com/problems/maximal-rectangle/) |
| 9 | | Sliding window maximum | | [LeetCode](https://leetcode.com/problems/sliding-window-maximum/) |

---

## Sliding Window & Two Pointer

| ID | Status | Problem | Notes | Link |
|:---:|:---:|:---|:---|:---:|
| 1 | | Longest repetition char replacement | `while ((r - l + 1) - maxFreq > k)` | [LeetCode](https://leetcode.com/problems/longest-repeating-character-replacement/) |
| 2 | | Binary subarray with sum = goal | Prefix, freq (`O(n)`) | [LeetCode](https://leetcode.com/problems/binary-subarrays-with-sum/) |
| 3 | | Count nice subarrays | Same concept as problem 2 | [LeetCode](https://leetcode.com/problems/count-number-of-nice-subarrays/) |
| 4 | | No. of substring containing all 3 chars | Count valid substrings ending at `r` | [LeetCode](https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/) |
| 5 | | Minimum window substring | | [LeetCode](https://leetcode.com/problems/minimum-window-substring/) |
| 6 | | Count subarray with k diff integers | | [LeetCode](https://leetcode.com/problems/subarrays-with-k-different-integers/) |
| 7 | | Minimum window subsequence | (Left) | [GFG](https://www.geeksforgeeks.org/problems/minimum-window-subsequence/1) |

---

## Heap

| ID | Status | Problem | Notes | Link |
|:---:|:---:|:---|:---|:---:|
| 1 | | Convert min heap to max heap | (Left) | [GFG](https://www.geeksforgeeks.org/problems/convert-min-heap-to-max-heap-1666385109/1) |
| 2 | | Implement min and max heap | (Left) | [GFG](https://www.geeksforgeeks.org/problems/operations-on-binary-min-heap/1) |
| 3 | | Merge M sorted Lists | (Left) | [LeetCode](https://leetcode.com/problems/merge-k-sorted-lists/) |
| 4 | | Hands of straights | | [LeetCode](https://leetcode.com/problems/hand-of-straights/) |
| 5 | | Task Scheduler | | [LeetCode](https://leetcode.com/problems/task-scheduler/) |
| 6 | | Find median from data stream | With queries `O(n log n + m)` | [LeetCode](https://leetcode.com/problems/find-median-from-data-stream/) |
| 7 | | Maximum sum combination | Good question | [InterviewBit](https://www.interviewbit.com/problems/maximum-sum-combinations/) |

---

## Greedy

| ID | Status | Problem | Notes | Link |
|:---:|:---:|:---|:---|:---:|
| 1 | ⭐ | **Valid Parenthesis checker** | tc, sc→`O(3^n),O(n)`→`O(n^2) ,O(n^2)`→`O(n), O(1)` | [LeetCode](https://leetcode.com/problems/valid-parenthesis-string/) |
| 2 | | N meetings in one room | Sort based on ending time | [GFG](https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1) |
| 3 | | Jump game 2 | | [LeetCode](https://leetcode.com/problems/jump-game-ii/) |
| 4 | | Minimum platform | Analyse code of jump game, min platform| [GFG](https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1) |
| 5 | ⭐ | **Job Sequencing Problem** | Optimize (Disjoint Set/Sort) & solve colorful arrays from spoj| [GFG](https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1) |
| 6 | | Candy | Optimized solution | [LeetCode](https://leetcode.com/problems/candy/) |
| 7 | | LRU Cache | (Left) | [LeetCode](https://leetcode.com/problems/lru-cache/) |
| 8 | | Insert interval | Easy | [LeetCode](https://leetcode.com/problems/insert-interval/) |
| 9 | | Non overlapping intervals | Sort by end points [2.3], [1,3]| [LeetCode](https://leetcode.com/problems/non-overlapping-intervals/) |

---

## Graph

### Basic & BFS/DFS
| ID | Status | Problem | Notes | Link |
|:---:|:---:|:---|:---|:---:|
| 1 | | No. of provinces | | [LeetCode](https://leetcode.com/problems/number-of-provinces/) |
| 2 | | Rotten Orange | Handle steps | [LeetCode](https://leetcode.com/problems/rotting-oranges/) |
| 3 | | Undirected Graph cycle | Using BFS and DFS | [GFG](https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1) |
| 4 | | Word ladder I | | [LeetCode](https://leetcode.com/problems/word-ladder/) |
| 5 | | Word Ladder II | (Left) | [LeetCode](https://leetcode.com/problems/word-ladder-ii/) |
| 6 | ⭐ | **No. of distinct island** | (Left) | [LeetCode (Premium)](https://leetcode.com/problems/number-of-distinct-islands/) / [GFG](https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1) |
| 7 | | Bipartite Graph | | [LeetCode](https://leetcode.com/problems/is-graph-bipartite/) |
| 8 | | Courses Scheduling II | (Left) | [LeetCode](https://leetcode.com/problems/course-schedule-ii/) |

### Topo Sort & Safe States
| ID | Status | Problem | Notes | Link |
|:---:|:---:|:---|:---|:---:|
| 1 | | Topo sort | | [GFG](https://www.geeksforgeeks.org/problems/topological-sort/1) |
| 2 | | Alien Dictionary | (Left) | [GFG](https://www.geeksforgeeks.org/problems/alien-dictionary/1) |
| 3 | | Find the eventual safe state | | [LeetCode](https://leetcode.com/problems/find-eventual-safe-states/) |

### Shortest Path
| ID | Status | Problem | Notes | Link |
|:---:|:---:|:---|:---|:---:|
| 1 | | Shortest path in indirect graph | | [GFG](https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1) |
| 2 | | Path with min effort | Condition update | [LeetCode](https://leetcode.com/problems/path-with-minimum-effort/) |
| 3 | | Cheapest Flight with K stoppages | Dist matrix | [LeetCode](https://leetcode.com/problems/cheapest-flights-within-k-stops/) |
| 4 | | No. of ways to arrive at destination | | [LeetCode](https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/) |
| 5 | | Min multiplication to reach end | `O(1e9)`, why not TLE? | [GFG](https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1) |
| 6 | | Bellman ford Algo | Negative edge wt | [GFG](https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1) |
| 7 | | Floyd Warshall Algo | Multiple set point, -ve edge wt| [GFG](https://www.geeksforgeeks.org/problems/floyd-warshall/1) |
| 8 | | City with smallest no. of neighbours | Threshold distance | [LeetCode](https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/) |

### MST & Disjoint Set
| ID | Status | Problem | Notes | Link |
|:---:|:---:|:---|:---|:---:|
| 1 | | MST | Prim's (PQ) & Kruskal's (DSU) | [GFG](https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1) |
| 2 | | No. of ops to make network Connection | DSU / DFS | [LeetCode](https://leetcode.com/problems/number-of-operations-to-make-network-connected/) |
| 3 | | Most stone removed by same row/col | | [LeetCode](https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/) |
| 4 | | Accounts Merge | (left) | [LeetCode](https://leetcode.com/problems/accounts-merge/) |
| 5 | | Making a islands | (Left) | [LeetCode](https://leetcode.com/problems/making-a-large-island/) |

---

## Dynamic Programming (DP)

### DP Patterns
| Category | Problem | Notes | Link |
|:---|:---|:---|:---:|
| **1D / 2D** | House Robber II | | [LeetCode](https://leetcode.com/problems/house-robber-ii/) |
| | Ninja’s Training | | [GFG](https://www.geeksforgeeks.org/problems/geeks-training/1) |
| | Minimum falling Path sum | 1st Q. TLE in Memoize | [LeetCode](https://leetcode.com/problems/minimum-falling-path-sum/) |
| | Chocolate Pick Up | 3D DP | [GFG](https://www.geeksforgeeks.org/problems/chocolates-pickup/1) |
| **Subsets** | Partition Sets into 2 subsets | Min abs diff | [LeetCode](https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/) |
| | Partition with given difference | Target sum concept | [GFG](https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1) |
| | Coin Change 1 & 2 | | [coin1](https://leetcode.com/problems/coin-change/) , [coin2](https://leetcode.com/problems/coin-change-ii/description/) |
| | Unbounded Knapsack | | [GFG](https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1) |
| **LCS** | LCS | Print All LCS (Left) | [LeetCode](https://leetcode.com/problems/longest-common-subsequence/) |
| | Min steps to make palindrome | `n - LCS` | [LeetCode](https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/) |
| | Delete Operation for two strings | `N + M - 2*LCS` | [LeetCode](https://leetcode.com/problems/delete-operation-for-two-strings/) |
| | Shortest Common Supersequence | | [LeetCode](https://leetcode.com/problems/shortest-common-supersequence/) |
| | Distinct Subsequence | (Recur, memo, tab revised), ways to generate t using s  | [LeetCode](https://leetcode.com/problems/distinct-subsequences/) |
| | Edit distance | | [LeetCode](https://leetcode.com/problems/edit-distance/) |
| | WildCard Matching | | [LeetCode](https://leetcode.com/problems/wildcard-matching/) |
| **Stocks** | Best time to buy/sell | simple, with Cap, cooldown, transaction fee | [LeetCode](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/) |
| **LIS** | Longest increasing subsequence | BS `O(n log n)` | [LeetCode](https://leetcode.com/problems/longest-increasing-subsequence/) |
| | Print LIS , subset (only sort) | ( important ) | [GFG](https://www.geeksforgeeks.org/problems/printing-longest-increasing-subsequence/1),  [leetcode](https://leetcode.com/problems/largest-divisible-subset/description/) |
| | Longest string chain | | [LeetCode](https://leetcode.com/problems/longest-string-chain/) |
| | Longest bitonic subsequence | | [LeetCode](https://leetcode.com/problems/longest-bitonic-subsequence/) |
| | No. of LIS | | [LeetCode](https://leetcode.com/problems/number-of-longest-increasing-subsequence/) |
| **Partition** | MCM | `fn(1, n-1)` | [GFG](https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1) |
| | Minimum cost to cut a stick | | [LeetCode](https://leetcode.com/problems/minimum-cost-to-cut-a-stick/) |
| | Burst Balloon | | [LeetCode](https://leetcode.com/problems/burst-balloons/) |
| | Palindrome partition | `fn(0, n)` ,  ( memoize sol gives tle )  | [LeetCode](https://leetcode.com/problems/palindrome-partitioning/) |
| | Partition array for max sum | | [LeetCode](https://leetcode.com/problems/partition-array-for-maximum-sum/) |
| | Parsing a boolean expression | (Left) | [LeetCode](https://leetcode.com/problems/parsing-a-boolean-expression/) |

---

## Binary Trees

| ID | Status | Problem | Notes | Link |
|:---:|:---:|:---|:---|:---:|
| 1 | | Level order traversal | | [LeetCode](https://leetcode.com/problems/binary-tree-level-order-traversal/) |
| 2 | | Balanced Binary tree | 2 method , O(n^2) , O(n)  | [LeetCode](https://leetcode.com/problems/balanced-binary-tree/) |
| 3 | ⭐ | **Vertical Order Traversal** | | [LeetCode](https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/) |
| 4 | | Top view of BT | | [GFG](https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1) |
| 5 | | Root to Leaf Path | | [LeetCode](https://leetcode.com/problems/binary-tree-paths/) |
| 6 | | Max Width of BT | | [LeetCode](https://leetcode.com/problems/maximum-width-of-binary-tree/) |
| 7 | ⭐ | **All nodes distance k at BT** | | [LeetCode](https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/) |
| 8 | | Min time to burn from node | | [GFG](https://www.geeksforgeeks.org/problems/burning-tree/1) |
| 9 | | Construct BST from In/Post | | [LeetCode](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/) |
| 10 | | Serialize and deserialize BT | (left)| [LeetCode](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/) |
| 11 | | Morris inorder/preorder | (Left) | [GFG](https://www.geeksforgeeks.org/morris-traversal-for-preorder/) |
| 12 | | Flatten BT to Linked List | 3 methods, 1 solved| [LeetCode](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/) |
| 13 | | Min and max Element |3 methods solved | [GFG](https://www.geeksforgeeks.org/find-min-and-max-element-in-binary-tree/) |
| 14 | | Zig_zag level order Traversal | | [LeetCode](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/) |

---

## Binary Search Tree (BST)

| ID | Status | Problem | Notes | Link |
|:---:|:---:|:---|:---|:---:|
| 1 | | Insert into a BST | | [LeetCode](https://leetcode.com/problems/insert-into-a-binary-search-tree/) |
| 2 | ⭐ | **Delete Node in BST** | (Imp) | [LeetCode](https://leetcode.com/problems/delete-node-in-a-bst/) |
| 3 | | Kth smallest ele in BST | | [LeetCode](https://leetcode.com/problems/kth-smallest-element-in-a-bst/) |
| 4 | ⭐ | **Valid BST** | Other method is imp | [LeetCode](https://leetcode.com/problems/validate-binary-search-tree/) |
| 5 | | LCA in BST | | [LeetCode](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/) |
| 6 | | Construct BST from preorder | <small>2 methods (1.gen inorder then pre, ino), (2.using preorder only (left))</small>| [LeetCode](https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/) |
| 7 | | Recover BST | (Left) | [LeetCode](https://leetcode.com/problems/recover-binary-search-tree/) |
| 8 | | Merge 2 BST | (Left) | [GFG](https://www.geeksforgeeks.org/problems/merge-two-bst-s/1) |
| 9 | | Largest BST | Preorder concept | [GFG](https://www.geeksforgeeks.org/problems/largest-bst/1) |

---

## Trie 

| ID | Status | Problem | Notes | Link |
|:---:|:---:|:---|:---|:---:|
| 1 | | Implement Trie | | [LeetCode](https://leetcode.com/problems/implement-trie-prefix-tree/) |
| 2 | | Implement Trie (gfg) | | [GFG](https://www.geeksforgeeks.org/problems/trie-insert-and-search0651/1) |
| 3 | | Longest string with all prefix | | [LeetCode](https://leetcode.com/problems/longest-word-in-dictionary/) |
| 4 | | Count of distinct substring | | [GFG](https://www.geeksforgeeks.org/count-number-of-distinct-substring-in-a-string/) |
| 5 | | Maximum XOR of two numbers | | [LeetCode](https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/) |
| 6 | | Max XOR with an element from array | | [LeetCode](https://leetcode.com/problems/maximum-xor-with-an-element-from-array/) |

---

## Linked List

| ID | Status | Problem | Notes | Link |
|:---:|:---:|:---|:---|:---:|
| 1 | | Insert Node | Last, Middle, Any pos | [last](https://www.geeksforgeeks.org/problems/linked-list-insertion-1587115620/1), [middle](https://www.geeksforgeeks.org/problems/insert-in-middle-of-linked-list/1), [pos(dummy(-1)](https://www.geeksforgeeks.org/problems/insertion-at-a-given-position-in-a-linked-list/1) |
| 2 | | Delete Node |2 method-> Pointer, Normal | [LeetCode](https://leetcode.com/problems/delete-node-in-a-linked-list/) |
| 3 | | Construct DLL | | [GFG](https://www.geeksforgeeks.org/problems/introduction-to-doubly-linked-list/1) |
| 4 | | Insert/Reverse DLL | | [insert](https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1), [reverse](https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1) |
| 5 | ⭐ | **Reverse LL** | | [LeetCode](https://leetcode.com/problems/reverse-linked-list/) |
| 6 | | Cycle in LL (I & II) | 1.`slow == fast` or 2.`map<*Node, int>mpp` | [cycI](https://leetcode.com/problems/linked-list-cycle/), [cycII](https://leetcode.com/problems/linked-list-cycle-ii/description/)|
| 7 | | Palindrome of LL |reverse till mid then compare (with handle odd and even length)  | [LeetCode](https://leetcode.com/problems/palindrome-linked-list/) |
| 8 | | Odd and even | (2nd method is interesting by manipulating even and odd )  | [LeetCode](https://leetcode.com/problems/odd-even-linked-list/) |
| 9 | ⭐ | **Remove nth node from end** | Need to dry run | [LeetCode](https://leetcode.com/problems/remove-nth-node-from-end-of-list/) |
| 10 | ⭐ | **Sort LL** | | [LeetCode](https://leetcode.com/problems/sort-list/) |
| 11 | | Rotate LL | Use cycle concept | [LeetCode](https://leetcode.com/problems/rotate-list/) |
| 12 | | Intersection of LL | | [LeetCode](https://leetcode.com/problems/intersection-of-two-linked-lists/) |
| 13 | | Add 1 to the LL number |  (two method, reverse then add then reverse,  2nd back track ) | [GFG](https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1) |
| 14 | | Reverse Node in K group | | [LeetCode](https://leetcode.com/problems/reverse-nodes-in-k-group/) |
| 15 | ⭐ | **Flattening LL** | | [GFG](https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1) |
| 16 | ⭐ | **Copy list to Random pointer** | (Left) | [LeetCode](https://leetcode.com/problems/copy-list-with-random-pointer/) |

---

## Cheat Sheets & Patterns

### 1. DP Decision Table
| Type | Question | Base Case | Transition | Operator | Example |
|:---|:---|:---|:---|:---|:---|
| **(A) Decision** | Is there a subsequence sum = k? | `return sum==k ? T : F` | `take \|\| ntake` | OR | `{2,3,5}, k=5` -> `True` |
| **(B) Counting** | How many subsequences sum to k? | `return sum==k ? 1 : 0` | `take + ntake` | `+` | `{2,3,5}, k=5` -> `2` |
| **(C) Optimization** | Max length/value of subsequence sum = k? | `return sum==k ? 0 : -∞` | `max(1+take, ntake)` | `max` | `{2,3,5}, k=5` -> `2` |

### 2. Prefix Sum & XOR Patterns
| Type | Formula |Storage| Property Checked |
|:---|:---|:---|:---|
| **Sum = K** | `pf[j] - pf[i-1] = K`|Prefix sums | Exact Sum | 
| **XOR = K** | `pf[j] ^ pf[i-1] = K`|prefix xor | Bit Property |
| **Sum % K = 0** | `(pf[j] - pf[i-1]) % K = 0`|prefix mod k | Divisibility |
| **Equal 0s & 1s** | `pf[j] - pf[i-1] = 0` |prefix sums| Balance |
| **Longest Subarray** | `pf[j] - K` in map |prefix sums| Max Length |
| **2D Prefix** | Subtraction of four rectangles |matrix prefix| Matrix region sum |

### 3. Graph vs Tree
| Concept | Cycles? | Max Children | Order? | Use Case |
|:---|:---|:---|:---|:---|
| **Graph** | ✅ Yes | No limit | ❌ No | Networks, Maps |
| **Tree** | ❌ No | No limit | ❌ No | Hierarchies |
| **Binary Tree** | ❌ No | 2 | ✅ L/R | Expression Trees |
| **BST** | ❌ No | 2 | ✅ Sorted (L < Root < R) | Fast Search/Insert |

### 4. Set vs Multiset
| Feature | Set | Multiset |
|:---|:---|:---|
| **Duplicates** | ❌ Not allowed | ✅ Allowed |
| **Order** | Sorted | Sorted |
| **Insert/Erase** | `O(log n)` | `O(log n)` |
| **Count** | Returns 0 or 1 | Returns count of duplicates |

### 5. PBDS (Policy Based Data Structure)
`s = { 5, 10, 20 }`

| Function | Meaning | Example | Output |
|:---|:---|:---|:---|
| `find_by_order(k)` | k-th smallest (0-indexed) | `*s.find_by_order(0)` | `5` |
| `order_of_key(x)` | count of elements < x | `s.order_of_key(4)` | `0` |

--- 
