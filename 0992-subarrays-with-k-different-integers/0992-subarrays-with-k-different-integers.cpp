class Solution {
public:
    int subarraysWithKDistinct(vector<int>& a, int k) {
      // keypoint - if 2 pointer approach is not counting correctly then think of the x<=y minus x<=y-1 approach.
      // exactly(k) = atMost(k) - atMost(k-1)
      int n = a.size(); 
      int low = 0, high = 0, cnt1=0,cnt2=0; 
      unordered_map<int,int> hash;
    // phase 1 - atMost k distinct
      while(high<n){
        hash[a[high]]++;
        while(hash.size()>k){
          hash[a[low]]--;
          if(hash[a[low]]==0) hash.erase(a[low]); // must erase, else size() stays wrong
          low++;
        }
        cnt1+=high-low+1; // all valid subarrays ending at high
        high++;
      }
    // phase 2 - atMost k-1 distinct
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