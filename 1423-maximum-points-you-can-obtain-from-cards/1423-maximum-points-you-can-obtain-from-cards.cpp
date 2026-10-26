class Solution {
public:
    int maxScore(vector<int>& points, int k) {
      // method 1 - standard 2 pointer sliding window (trick sliding method is below)

      int n = points.size();
      int leftsum = 0, rightsum = 0;
      for(int i = 0;i<k;i++){
        leftsum+=points[i];
      }
      int maxsum = 0;
      maxsum = max(maxsum,leftsum+rightsum);
      int left = k-1;
      int right = n-1;
      while(left>=0){
        leftsum-=points[left--];
        rightsum+=points[right--];
        maxsum = max(maxsum,leftsum+rightsum);
      }
      return maxsum;
    }
    /*
      //this question has a trick , here we can get the answer by a trick i.e. we have to find the subarray of size n-k such that the sum is minimum.
    int maxScore(vector<int>& points, int k) {
      int n = points.size();
      int arrsum=0;
      for(int i=0;i<n;i++) arrsum+=points[i];
      if(k==n) return arrsum; //if we have to pick all cards

      int left = 0, right =0;
      int subarrlen=n-k;
      int currsum = 0;
      //adding till we get the desired length
      while(right-left+1<=subarrlen){
        currsum+=points[right++];
      }
      //traversing ahead
      int minsum = currsum;
      while(right<n){
        currsum+=points[right];
        right++;
        currsum-=points[left];
        left++;
        minsum=min(minsum,currsum);
      }
      //now we have the minimum sum , ans will be the array sum - minsum
      return arrsum-minsum;
    }*/
};