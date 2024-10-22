class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(int i = 0;i<s.size();i++) {
            if(s[i] == '(' or s[i] == '[' or s[i] == '{' ){
                st.push(s[i]);

            }
            else {
                if(st.empty()) return false;
                char c = st.top();
                st.pop();
                if((s[i]== ')' && c == '(') || 
                   (s[i]== ']' && c == '[') || 
                   (s[i]== '}' && c == '{')) {
                    // do nothing, continue loop
                } else {
                    return true;
                }

            }
            if(st.empty()) return false;
        }
        return false;
        
    }
};