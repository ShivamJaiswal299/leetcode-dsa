class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7;

        vector<int> left(n), right(n);
        stack<int> stk;                       // stores indices

        // left = number of choices on the left (including i itself)
        // stop at previous strictly smaller element
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && arr[stk.top()] >= arr[i]) stk.pop();
            left[i] = stk.empty() ? 0 + i + 1 : i - stk.top();//IF CANT UNDERSTAND THIS DRY RUN A TEST CASE.
            stk.push(i);
        }

        while (!stk.empty()) stk.pop();       // clear the stack

        // right[i] = number of choices on the right (including i itself)
        // stop at the next SMALLER OR EQUAL element
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && arr[stk.top()] > arr[i]) stk.pop();
            right[i] = stk.empty() ? n - i : stk.top() - i;
            stk.push(i);
        }

        // arr[i] is the minimum in left[i] * right[i] subarrays
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans = (ans + (long long)arr[i] * left[i] % MOD * right[i]) % MOD;
        }
        return ans;
    }
};