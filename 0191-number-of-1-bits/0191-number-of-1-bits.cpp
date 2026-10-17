class Solution {
public:
    int hammingWeight(int n) {
      short int cnt=0;
      while(1){
        if(n%2==1) cnt++;
        n/=2;
        if(n==0) break;
      }
      return cnt;
    }
};