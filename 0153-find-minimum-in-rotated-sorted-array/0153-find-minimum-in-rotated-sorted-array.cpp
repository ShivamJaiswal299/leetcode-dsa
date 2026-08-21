class Solution {
public:
    int findMin(vector<int>& a) {
        int n=a.size();
        int mid;
        int low = 0, high = n-1;
        while(low<high){
          mid = low + (high - low)/2;
          if(a[mid]<=a[high]) high=mid; //this means min will be low->mid
          else if(a[mid]>a[high])low=mid+1;//this means min will be mid+1->high
        }
        return a[low];//here a[low] or a[mid] both works as the loop will only stop when high == low , and mid cant be cuz mid will be calculated after high and low are calculated and that too in the next iteration and the next(last) iteration will never.
    }
};