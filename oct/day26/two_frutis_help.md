# Two Fruits Problem

## Problem Statement
Given an array of integers representing different types of fruits, you need to find the maximum number of fruits you can collect in two baskets. Each basket can only contain one type of fruit, and you must pick the fruits consecutively.

## Approach

### Sliding Window Technique
The problem can be solved efficiently using the sliding window technique. The idea is to maintain a window that contains at most two types of fruits and to maximize the length of this window.

### Steps:
1. **Initialize Variables**:
    - `unordered_map<int, int> mpp`: To store the count of each type of fruit in the current window.
    - `int l = 0, r = 0`: Two pointers representing the left and right ends of the window.
    - `int maxlen = 0`: To store the maximum length of the window that contains at most two types of fruits.

2. **Expand the Window**:
    - Iterate through the array using the right pointer `r`.
    - Add the current fruit to the map and increment its count.

3. **Shrink the Window**:
    - If the map size exceeds 2 (more than two types of fruits in the window), increment the left pointer `l` to shrink the window until the map size is 2 or less.
    - Decrement the count of the fruit at the left pointer in the map. If the count becomes zero, remove that fruit from the map.

4. **Update Maximum Length**:
    - After adjusting the window, update `maxlen` with the maximum length of the window encountered so far.

5. **Return Result**:
    - Return `maxlen` as the result.

### Code Explanation
```cpp
class Solution {
  public:
    int totalFruits(vector<int> &arr) {
        unordered_map<int, int> mpp;
        int l = 0, r = 0, maxlen = 0;

        while (r < arr.size()) {
            mpp[arr[r]]++;
            
            while (mpp.size() > 2) {
                mpp[arr[l]]--;
                if (mpp[arr[l]] == 0) {
                    mpp.erase(arr[l]);
                }
                l++;
            }
            
            maxlen = max(maxlen, r - l + 1);
            r++;
        }
        
        return maxlen;
    }
};