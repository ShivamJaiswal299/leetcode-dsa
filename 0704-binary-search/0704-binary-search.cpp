class Solution {
public:
    int search(vector<int>& a, int target) {
        int low=0,high=a.size()-1;
        while(low<=high){
          int mid = low + (high - low)/2;
          if(target==a[mid]) return mid;
          else if(target>a[mid]) low=mid+1;
          else if(target<a[mid]) high=mid-1;
        }
        return -1;
    }
};