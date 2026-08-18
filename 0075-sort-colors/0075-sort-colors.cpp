class Solution {
public:
    void sortColors(vector<int>& a) {
      //DOING BY DUTCH NATIONAL FLAG ALGORITHM
      int low = 0, mid = 0, high = a.size()-1;
      while(mid<=high){
        if(a[mid]==0) swap(a[low++],a[mid++]);
        else if(a[mid]==1) mid++;
        else if(a[mid]==2) swap(a[mid],a[high--]);
      }
        
    }
};