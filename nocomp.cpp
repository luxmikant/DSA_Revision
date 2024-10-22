#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int findComplement(int n) {
    string res = "";
    while(n!=1){
        if(n%2==1) res+='1';
        else res+='0';
        n = n/2;
    }
    reverse(res.begin(), res.end());
    return stoi(res);
}

int main(){
    int n = 5;
    cout<<findComplement(n);
    return 0;
}