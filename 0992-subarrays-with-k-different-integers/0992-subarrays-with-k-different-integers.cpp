class Solution {
public:
    int subarraysWithKDistinct(vector<int>& a, int k) {
      // keypoint - if 2 pointer approach is not counting correctly then think of the x<=y minus x<=y-1 approach.
      int n = a.size(); 
      int low = 0, high = 0, cnt1=0,cnt2=0; 
      unordered_map<int,int> hash;
    // phase 1
      while(high<n){
        hash[a[high]]++;
        while(hash.size()>k){
          hash[a[low]]--;
          if(hash[a[low]]==0) hash.erase(a[low]);
          low++;
        }
        cnt1+=high-low+1;
        high++;
      }
    // phase 2
    hash.clear();
    low=0,high=0; //reset.
      while(high<n){
        hash[a[high]]++;
        while(hash.size()>k-1){
          hash[a[low]]--;
          if(hash[a[low]]==0) hash.erase(a[low]);
          low++;
        }
        cnt2+=high-low+1;
        high++;
      }
      return cnt1-cnt2;
    }
};