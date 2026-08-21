class Solution {
public:
    int findPeakElement(vector<int>& a) {
      int n =a.size();
      int low=0,high=n-1;
      //we will move there where the higher element is present
      while(low<=high){
        int mid = low + (high-low)/2;
        // first checking wheather mid is peak or not ,keeping in mind that  -1 and n are -infinity
        if(((mid-1==-1)?1:a[mid]>a[mid-1]) && ((mid+1==n)?1:a[mid]>a[mid+1])) return mid;
        else{
          // now if mid is not peak then checking mid-1 is greater or mid+1 and then shifting the pointers accordingly. 
          if((mid-1==-1)?0:((mid+1==n)?1:(a[mid-1]>a[mid+1]))) high=mid-1;
          else low=mid+1;
        }
      }
      return -1;//just for safety
    }
};