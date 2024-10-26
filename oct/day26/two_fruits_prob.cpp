//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(vector<int> &arr) {
        //max length subarray with at most 2 type of numbers
        //we have to pick consicutive samr no and fill in two basket insureing that is coontains max no fruits
        //brute fore tc - N2 -> N optimization using sliding window and two pointer
        //better sol O(2N) --> OPTIMIZE TO o(N )
        //what is the intution ?? -> w just have to maintain the maxlength while moving l and r pointer simaintanously .
        // brute force contain two loopes 
        
        // unordered_map<int,int> mpp;
        // int l =0,r=0,maxlen =0;
        // while(r<arr.size()){
        //     mpp[arr[r]]++;
        //     if(mpp.size()>2){
        //         while(mpp.size()>2){
        //             mpp[arr[l]]--;
        //             if(mpp[arr[l]] == 0){
        //                 mpp.erase(arr[l]);
        //                 l++;
        //             }
        //         }
        //         if(mpp.size()<=2){
        //             maxlen = max(maxlen, r-l+1);
        //         }
        //         r++;
        //     }
            
        // }
        // return maxlen;
        
        
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

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        int ans = ob.totalFruits(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
