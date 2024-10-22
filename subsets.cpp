class Solution {
private:
    void func(int i, int k, int sum_till_now, int n, vector<int>& subSet, vector<vector<int>>& ans) {
        if (sum_till_now > n) return;
        if (k == 0) {
            if (sum_till_now == n) {
                ans.push_back(subSet);
            }
            return;
        }

        if (k < 0)
            return;
        if (sum_till_now == n) {
            if (k == 0)
                ans.push_back(subSet);
            return;
        }

        if (i > 9)
            return;
        sum_till_now += i;
        subSet.push_back(i);
        func(i + 1, k - 1, sum_till_now, n, subSet, ans);
        sum_till_now -= i;
        subSet.pop_back();

        func(i + 1, k - 1, sum_till_now, n, subSet, ans);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> subSet;
        func(0, k, 0, n, subSet, ans);
        return ans;
    }
};