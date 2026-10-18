class Solution {
public:
/*
logic - Example: 100 / 7
Biggest jump: 7 × 8 = 56 → left 44, answer 8
Next: 7 × 4 = 28 → left 16, answer 8 + 4 = 12
Next: 7 × 2 = 14 → left 2, answer 12 + 2 = 14 (2 < 7, stop)
*/
    int divide(long long divident,long long divisor) {
        // Step 1: find sign of answer (negative if exactly one is negative)
        int sign = 1;
        if(divident<0||divisor<0) sign=-1;
        if(divident<0 && divisor<0) sign=1;

        // Step 2: work with positive values (long long, so INT_MIN is safe)
        if(divident<0) divident=-divident;
        if(divisor<0) divisor=-divisor;

        long long cnt=0; // final quotient
        while(divident>=divisor){
          // Step 3: double the divisor (divisor<<i) until it is bigger than divident
          long long temp=divisor;
          long long i = 0;
          while(temp<=divident){
            i++;
            temp=divisor<<i;
          }
          i--; // go back to the last jump that fits

          // Step 4: subtract that big jump, add its count (2^i) to answer
          divident-=divisor<<i;
          cnt+=1LL<<i; // 1LL, not 1, to avoid int overflow at i=31
        }

      // Step 5: only case that overflows is INT_MIN / -1 (positive 2^31)
      if(sign==1 && cnt>INT_MAX) return INT_MAX;
      return sign==1?cnt:-cnt;
    }
};