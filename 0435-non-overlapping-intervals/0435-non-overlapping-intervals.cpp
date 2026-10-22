class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
      //logic is same as n meetings problem , the interval that ends first is put first , then after it if some interval conflicts , it is counted as overlapping interval.
      sort(intervals.begin(),intervals.end(),[](auto &a,auto &b){
        // if(a.second==b.second) case is not required as it doesnt effect our approach.
        return a[1]<b[1];
      });
      int endInterval = INT_MIN;//as start of the interval can be negative too
      int ans=0;
      for(auto &x:intervals){
        if(endInterval>x[0]) ans++;
        else endInterval = x[1]; 
      }
      return ans;
    }
};