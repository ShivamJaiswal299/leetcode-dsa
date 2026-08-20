class Solution {
public:
// this is same as the one with no duplicates just a type of test case can break it which is the element at low mid and high are same i.e. our method wont be able to select the sorted array in that case so we will check 1 more thing i.e. a[low]==a[mid] && a[mid]==a[high].
    bool search(vector<int>& a, int x) {
        int n = a.size();
        int low=0,high=n-1;
        while(low <= high){
          int mid = low + (high-low)/2;
          if(a[mid]==x) return true;
          else{
            //checking left half is sorted or not
            if(a[low]==a[mid] && a[mid]==a[high]){
              low++;
              high--;
              //in this way we can ignore the edge duplicate values and judge which is sorted.
            }
            else if(a[low]<=a[mid] ) {
              if(a[low]<=x && a[mid]>=x) high=mid-1;
              else low=mid+1;
              }
            else{
              if(a[mid]<=x && a[high]>=x) low=mid+1;
              else high=mid-1;
            }
          } 
        }
        return false;
    }
};