class Solution {
public:
    int findPeakElement(vector<int>& a) {
      int n =a.size();
      int low=0,high=n-1;
      while(low<=high){
        int mid = low + (high-low)/2;
        if(((mid-1==-1)?1:a[mid]>a[mid-1]) && ((mid+1==n)?1:a[mid]>a[mid+1])) return mid;
        else{
          if((mid-1==-1)?0:((mid+1==n)?1:(a[mid-1]>a[mid+1]))) high=mid-1;
          else low=mid+1;
        }
      }
      return -1;
    }
};