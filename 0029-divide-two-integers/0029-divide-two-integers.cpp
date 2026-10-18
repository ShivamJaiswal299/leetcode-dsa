class Solution {
public:
    int divide(long long divident,long long divisor) {
        int sign = 1;
        if(divident<0||divisor<0) sign=-1;
        if(divident<0 && divisor<0) sign=1;

        if(divident<0) divident=-divident;
        if(divisor<0) divisor=-divisor;
        long long cnt=0;
        while(divident>=divisor){
          long long temp=divisor;
          long long i = 0;
          while(temp<=divident){
            i++;
            temp=divisor<<i;
          }
          i--;
          divident-=divisor<<i;
          cnt+=1LL<<i;
        }
      
      if(sign==1 && cnt>INT_MAX) return INT_MAX;
      return sign==1?cnt:-cnt; 
    }
};