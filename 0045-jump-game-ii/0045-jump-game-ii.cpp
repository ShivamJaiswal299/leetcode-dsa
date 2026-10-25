class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        // [l, r] = range of indices we can stand on after 'jumps' jumps
        int l = 0, r = 0;
        int jumps = 0;

        // keep going until our range reaches the last index
        while (r < n - 1) {

            // farthest index we can reach from ANY index in current range
            int farthest = 0;
            for (int i = l; i <= r; i++) {
                farthest = max(farthest, i + nums[i]);
            }

            // next range starts right after the current one
            l = r + 1;

            // next range ends at the farthest index we found
            r = farthest;

            // moving to the next range costs exactly 1 jump
            jumps++;
        }

        return jumps;
    }
};