class Solution {
public:
    int totalFruit(vector<int>& a) {
      int n = a.size();
      int low=0 , high=0;
      int maxfruits = 0;
      unordered_map<int, int> mp;
      while(high<n){
        mp[a[high]]++;
        //now checking was it possible
        while(mp.size()>2){
          mp[a[low]]--;
          if(mp[a[low]]==0) mp.erase(a[low]);
          low++;
        }
        maxfruits=max(maxfruits,high-low+1);
        high++;
      }

      return maxfruits;
    }
};