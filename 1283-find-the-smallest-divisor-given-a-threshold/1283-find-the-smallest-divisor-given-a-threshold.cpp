class Solution {
public:
    int smallestDivisor(vector<int>& a, int threshold) {
      int n =a.size(),maxNum=0;
      for(int i=0;i<n;i++) maxNum=max(maxNum,a[i]);
      int low=1,high=maxNum,mid,minDiv=maxNum+1;
      while(low<=high){
        int mid = low + (high - low)/2;
        int temp=0;
        for(int i=0;i<n;i++) temp+=(a[i]%mid==0)?(a[i]/mid):(a[i]/mid)+1;
        if(threshold>=temp) {
          minDiv=min(minDiv,mid);
          high=mid-1;
        }else{
          low=mid+1;
        }
      }
      return minDiv;
    }
};