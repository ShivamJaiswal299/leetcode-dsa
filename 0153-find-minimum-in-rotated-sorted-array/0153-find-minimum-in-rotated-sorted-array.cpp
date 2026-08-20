class Solution {
public:
    int findMin(vector<int>& a) {
        int n=a.size();
        int mid;
        int low = 0, high = n-1;
        while(low<high){
          mid = low + (high - low)/2;
          if(a[mid]<=a[high]) high=mid;
          else if(a[mid]>a[high])low=mid+1;
        }
        return a[low];
    }
};