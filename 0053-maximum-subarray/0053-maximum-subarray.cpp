class Solution {
public:
//BY KADANE'S ALGORITHM
    int maxSubArray(vector<int>& a) {
        int currSum=0,maxSum=INT_MIN;
        for(int i=0;i<a.size();i++){
          currSum+=a[i];
          maxSum=max(maxSum,currSum);
          if(currSum<0) currSum=0;
        }
        return maxSum;
    }
};