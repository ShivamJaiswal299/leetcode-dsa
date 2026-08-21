class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
      //xor method will give us time O(n) but we want O(log n) so not using it.
      int n=a.size();
      int low=0,mid,high=n-1;
      while(low<high){
        mid = low + (high - low)/2;
        if(mid%2==0){
          if(a[mid] == a[mid+1]) low=mid+2;
          else high = mid;
        }
        else{
          if(a[mid] == a[mid+1]) high=mid-1;
          else low=mid+1;
        }
      }
      return a[low];
    }
    };