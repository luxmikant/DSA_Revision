#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    // struct mancher{
    //     vector<int> p;

    //     void run_manacher(string s){
    //         int n = s.length();
    //         p.assign(n,1);
    //         int l=1,r=1;
    //         for(int i = 1;i<n;i++){
    //             p[i] = max(0,min(r-i,p[l+r-i]));
    //             while(i+p[i]<n && i-p[i]>=0 && s[i+p[i]] == s[i-p[i]]){
    //                 p[i]++;
    //             };
    //         }
    //             if(i+p[i]>r){
    //                 l = i-p[i];
    //                 r = i+p[i];
    //             }
    //         }
    //         for(auto v:p){
    //             cout<<v<<"";

    //         }
    //     cout<<endl;
    //     }
    //     void build(string s){
    //         string t ;
    //         for(auto v:s){
    //             t += string("#")+v;

    //         }
    //         run_manacher(t +"#");
    //     }
    // };
    
    string longestPalindrome(string s) {
        int n = s.length();
        if (n < 2) {
            return s;
        }
        int start = 0, maxLen = 1;
        for (int i = 0; i < n; ) {
            if (n - i <= maxLen / 2) {
                break;
            }
            int left = i, right = i;
            while (right < n - 1 && s[right + 1] == s[right]) {
                right++;
            }
            i = right + 1;
            while (right < n - 1 && left > 0 && s[right + 1] == s[left - 1]) {
                right++;
                left--;
            }
            int currLen = right - left + 1;
            if (currLen > maxLen) {
                start = left;
                maxLen = currLen;
            }
        }
        return s.substr(start, maxLen);
    }
};