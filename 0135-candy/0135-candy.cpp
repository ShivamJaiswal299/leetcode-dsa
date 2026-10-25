class Solution {
public:
    int candy(vector<int>& ratings) {
      int n = ratings.size();
      vector<int> left(n,1),right(n,1);

      // left[i] = the minimum candies child i needs to satisfy the left rule.
      for(int i=1;i<n;i++){
        if(ratings[i]>ratings[i-1]){
          left[i]=left[i-1]+1;
        }
      }
      // right[i] = the minimum candies child i needs to satisfy the right rule.
      for(int i=n-2;i>=0;i--){
        if(ratings[i]>ratings[i+1]){
          right[i]=right[i+1]+1;
        }
      }
      // cnt will be the max of left[i] and right[i]
      int cnt = 0;
      for(int i=0;i<n;i++){
        cnt+= max(left[i],right[i]);
      }
      // why max? the answer must be at least max(left[i], right[i]), because both minimums must hold. And max itself is enough, so it is also the smallest possible value.
      return cnt;
    }
};