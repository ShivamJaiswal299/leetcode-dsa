class Solution {
public:
    int numberOfSubarrays(vector<int>&a, int k) {
        // Idea: odd -> 1, even -> 0, so "exactly k odd numbers" = "subarray sum == k"
        // exactly(k) = atMost(k) - atMost(k - 1)
        int n = a.size();
        // Convert to binary array (modifies input in place)
        for (int i = 0; i < n; i++) a[i] %= 2;
        int low = 0, high = 0, sum = 0;
        int cnt1 = 0, cnt2 = 0;
        // Phase 1: count subarrays with sum <= k
        while (high < n) {
            sum += a[high];// expand window on the right
            while (sum > k) {// too many odds -> shrink from the left
                sum -= a[low++];
            }
            cnt1 += high - low + 1;// all valid subarrays ending at 'high'
            high++;
        }
        // Phase 2: count subarrays with sum <= k - 1 (same logic)
        low = 0, high = 0, sum = 0;
        while (high < n) {
            sum += a[high];
            while (sum > k - 1) {
                sum -= a[low++];
            }
            cnt2 += high - low + 1;
            high++;
        }
        // (sum <= k) minus (sum <= k-1) leaves exactly sum == k
        return cnt1 - cnt2;
    }
};