class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0 && (n&(n-1))==0;
    }
    //A power of 2 has exactly one set bit.
    /*
    Why n & (n-1) works: subtracting 1 flips the lowest set bit to 0 and all bits after it to 1. So if n has only one set bit, n & (n-1) becomes 0

    Example: n = 8
      1000   (8)
    & 0111   (7)
    ------
      0000   → 0 → true ✔
      */
};