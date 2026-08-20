class Solution {
public:
    int search(vector<int>& a, int x) {
        int n = a.size();
        int low=0,high=n-1;
        while(low <= high){
          int mid = low + (high-low)/2;
          if(a[mid]==x) return mid;
          else{
            //checking left half is sorted or not
            if(a[low]<=a[mid]) {
              if(a[low]<=x && a[mid]>=x) high=mid-1;
              else low=mid+1;
              }
            else{
              if(a[mid]<=x && a[high]>=x) low=mid+1;
              else high=mid-1;
            }
          } 
        }
        return -1;
    }
};