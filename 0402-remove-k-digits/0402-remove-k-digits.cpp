class Solution {
public:
    string removeKdigits(string a, int k) {
        stack<char> stk;
        for (char x : a) {
            // pop bigger digits 
            while (k > 0 && !stk.empty() && stk.top() > x) {
                stk.pop();
                k--;
            }
            stk.push(x); //now doesnt matter stk is empty or not, we can easily push the current element.
        }

        // still k left? this means stack is increasing, remove from the end as end one are greater.
        while (k > 0 && !stk.empty()) {
            stk.pop();
            k--;
        }

        // stack to string
        string s;
        while (!stk.empty()) {
            s.push_back(stk.top());
            stk.pop();
        }
        reverse(s.begin(), s.end());

        // remove leading zeros (erase once)
        int i = 0;
        while (i < s.size() && s[i] == '0') i++;
        s.erase(0, i);
        return s.empty() ? "0" : s;
    }
};