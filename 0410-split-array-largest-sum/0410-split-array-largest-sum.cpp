class Solution {
public:
    int splitArray(vector<int>& a, int subarr) {
      int n = a.size(),maxofa=a[0],sumofa=0;
      for(int x:a){
        maxofa=max(maxofa,x);
        sumofa+=x;
      }
      int low = maxofa, mid, high = sumofa;
      int maxSum=sumofa;
      while(low<=high){
        int mid = low + (high - low)/2;
        int tempSum = a[0];
        int tempMax=-1,subarrLeft=subarr;
        for(int i=1;i<n;i++){
          if(tempSum+a[i]<=mid) tempSum+=a[i];
          else if(tempSum+a[i]>mid){
            tempMax=max(tempMax,tempSum);
            subarrLeft--;
            tempSum=a[i];
          }
        }
        tempMax=max(tempMax,tempSum);
        if(tempSum) subarrLeft--;
        if(subarrLeft>=0) {
          maxSum=min(maxSum,tempMax);
          high=mid-1;
          }
        else if(subarrLeft<0) low=mid+1;
      }
      return maxSum;

    }
};