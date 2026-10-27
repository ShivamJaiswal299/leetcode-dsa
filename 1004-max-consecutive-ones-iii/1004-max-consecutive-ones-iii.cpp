class Solution {
public:
    int longestOnes(vector<int>& a, int k) {
      int n = a.size();
      int low = 0, high = 0 ;
      int currlen = 0;
      int maxlen = 0;
      while(high<n){
        if(a[high]==1){
          currlen++;
          high++;
        }else if(a[high]==0){
          if(k==0){ //as k==0 so we will remove the extra zero
            while(a[low]==1){
              low++;
              currlen--;
            }
            k++;
            low++;
            currlen--;
          }
          k--;
          currlen++;
          high++;
        }
        maxlen=max(maxlen,currlen);
      }
      return maxlen;
    }
};