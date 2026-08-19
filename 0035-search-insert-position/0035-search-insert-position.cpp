class Solution {
public:
    int searchInsert(vector<int>& a, int x) {
        int low = 0 , high = a.size()-1;
        int idx=a.size();
        while(low<=high){
            int mid = low + (high-low)/2;
            //here we will find lower bound i.e. equal or just next one
            if(a[mid]==x || a[mid]>x)  {
                high=mid-1;
                idx=mid;
            }
            else if(a[mid]<x) low=mid+1;
        }
        return idx;
    }
};