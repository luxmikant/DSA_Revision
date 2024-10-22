class Solution {
public:
    string countOfAtoms(string formula) {
            string countOfAtoms(string formula) {
        int n = formula.length();
        stack<unordered_map<string, int>> stack;
        stack.push(unordered_map<string, int>());
        int index = 0;

        while (index < n) {
            char ch = formula[index];
            if (ch == '(') {
                stack.push(unordered_map<string, int>());
                index++;
            } else if (ch == ')') {
                unordered_map<string, int> curMap = stack.top();
                stack.pop();
                index++;
                // Find the multiplier
                string multiplier;
                while (index < n && isdigit(formula[index])) {
                    multiplier += formula[index];
                    index++;
                }
                // Multiply the count - ()n
                if (!multiplier.empty()) {
                    int m = stoi(multiplier);
                    for (auto& atom : curMap) {
                        atom.second *= m;
                    }
                }
                // Insert popped map elements into stack top
                for (auto& atom : curMap) {
                    stack.top()[atom.first] += atom.second;
                }
            } else { // Atom name and count
                // Take the uppercase letter
                string atomName;
                atomName += ch;
                index++;
                // Collect all lowercase letters
                while (index < n && islower(formula[index])) {
                    atomName += formula[index];
                    index++;
                }
                string count;
                while (index < n && isdigit(formula[index])) {
                    count += formula[index];
                    index++;
                }
                int c = count.empty() ? 1 : stoi(count);
                stack.top()[atomName] += c;
            }
        }

        map<string, int> sortedMap(stack.top());
        string res;
        for (auto& atom : sortedMap) {
            res += atom.first;
            int count = atom.second;
            if (count > 1) {
                res += to_string(count);
            }
        }
        return res;
    
    }
};