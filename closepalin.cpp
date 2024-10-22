#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
    long findNearestPalindrome(long firstHalf, bool isOdd){
        long res = firstHalf;
        if(isOdd){
            firstHalf/=10;
        }
        while(firstHalf>0){
            res = res *10 +(firstHalf%10);
            firstHalf/=10;
        }
        return res;

    }
public:
    string nearestPalindromic(string n) {
        int len = n.size();
        vector<long> list;
        bool isOdd = (len % 2 != 0);
        //copy first half
        int mid = (len % 2 == 0) ? (len / 2) : (len / 2 + 1);
        long firstHalf = stol(n.substr(0, mid));
        list.push_back(findNearestPalindrome(firstHalf, isOdd));
        list.push_back(findNearestPalindrome(firstHalf + 1, isOdd));
        list.push_back(findNearestPalindrome(firstHalf - 1, isOdd));
        list.push_back((long)pow(10, len - 1) - 1);
        list.push_back((long)pow(10, len) + 1);

        long num = stol(n);
        long minDiff = INT_MAX;
        long res = 0;

        for (long element : list) {
            if (element == num) continue;
            long curDiff = abs(element - num);
            if (curDiff < minDiff) {
                res = element;
                minDiff = curDiff;
            } else if (curDiff == minDiff) {
                res = min(res, element);
            }
        }
        return to_string(res);
    }
};

int main() {
    Solution s;
    cout << s.nearestPalindromic("100") << endl;
    return 0;
}