class Solution {
public:
    vector<int> searchRange(vector<int>& a, int x) {
        int n=a.size();
        int low=0,high=n-1,firstIdx=-1,lastIdx=-1;
        while(low<=high){
          int mid = low + (high-low)/2;
          if(a[mid]<x) low = mid+1;
          else if(a[mid]>x) high = mid-1;
          else if(a[mid]==x){
            firstIdx=mid;
            high=mid-1;
          }
        }
        low=0,high=n-1;
        while(low<=high){
          int mid = low + (high-low)/2;
          if(a[mid]<x) low = mid+1;
          else if(a[mid]>x) high = mid-1;
          else if(a[mid]==x){
            lastIdx=mid;
            low=mid+1;
          }
        }

      return {firstIdx,lastIdx};
    }
};