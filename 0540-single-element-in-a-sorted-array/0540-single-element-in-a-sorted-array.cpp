class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
      //xor method will give us time O(n) but we want O(log n) so not using it.
      int n=a.size();
      int low=0,mid,high=n-1;
      //the logic is - a new pair will always start from even index, if the pair is starting at odd index, then something is wrong before or at it.
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
      return a[high];//high or low , anything can work as loop stops when low==high.
    }
    };