class Solution {
public:
    int findKthPositive(vector<int>& a, int k) {
        int n = a.size();
        int low=0,mid,high=n-1,missing;
        while(low<=high){
          mid = low + (high - low)/2;
          missing = a[mid] - mid - 1; 
          if(missing<k) low=mid+1;
          else if(missing>=k) high = mid - 1;
        }
        return low+k; //low+k or high+1+k both are correct , how this came? 
        //1 thing is for sure that high will always be 1 step back of low as loop first go till missing > k then come back 1 step.
        //now answer should be a[low] + k - missing, here missing = a[low]-low-1 as low==mid so by simplifying 
    }
};