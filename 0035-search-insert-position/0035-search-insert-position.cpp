class Solution {
public:
    int searchInsert(vector<int>& a, int x) {
        //binary search
        int low = 0 , high = a.size()-1;
        int minIdx=a.size();
        while(low<=high){
            int mid = low + (high-low)/2;
            // if target is low we keep searching , if target==a[mid] we keep searching that also cuz duplicate can exists
            if(a[mid]==x || a[mid]>x)  {
                high=mid-1;
                minIdx=mid;
            }
            else if(a[mid]<x) low=mid+1;
        }
        return minIdx;
    }
};