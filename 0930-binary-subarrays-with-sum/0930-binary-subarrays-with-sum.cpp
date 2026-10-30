class Solution {
public:
    int numSubarraysWithSum(vector<int>& a, int goal) {
        // Idea: exactly(goal) = atMost(goal) - atMost(goal - 1)
        // (Works because elements are non-negative, so shrinking the window lowers the sum.)
        int n = a.size();
        int low = 0, high = 0, sum = 0;
        int cnt1 = 0, cnt2 = 0;
        // Pass 1: count subarrays with sum <= goal
        while (high < n) {
            sum += a[high];// expand window on the right
            while (sum > goal) {// too big -> shrink from the left
                sum -= a[low];
                low++;
            }
            cnt1 += high - low + 1;// all valid subarrays ending at 'high'
            high++;
        }
        // Edge case: goal == 0 -> "sum <= -1" is impossible, so cnt2 = 0
        if (goal == 0) return cnt1;
        // Pass 2: count subarrays with sum <= goal - 1 (same logic)
        low = 0, high = 0, sum = 0;
        while (high < n) {
            sum += a[high];
            while (sum > goal - 1) {
                sum -= a[low];
                low++;
            }
            cnt2 += high - low + 1;
            high++;
        }
        // sum <= goal minus sum <= goal-1 leaves exactly sum == goal
        return cnt1 - cnt2;
    }
};