class Solution {
public:
    int minBitFlips(int start, int goal) {
// x = start xor goal → 1 at every position where the bits differ
// Count the set bits in x → each one needs exactly one flip
    int x = start^goal;
    int cnt=0;
    while(x){
      cnt += x&1;
      x >>= 1;
    }
    return cnt;
    }
};