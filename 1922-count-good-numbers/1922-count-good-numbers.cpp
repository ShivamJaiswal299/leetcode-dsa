class Solution {
public:
    int modulator = 1000000007; 
    int countGoodNumbers(long long n) {
    return n%2==0?mypow(20,n/2):(mypow(20,n/2)*(long long)5)%modulator;
    }
private:
    int mypow(int x, long long n){
      if(n==0) return 1;
      long long half = mypow(x,n/2);
      return n%2==0?(half*half)%modulator:(((half*half)%modulator)*x)%modulator;
    }
};