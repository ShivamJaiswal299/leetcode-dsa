class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> startInterval;
        vector<int> endInterval;
        for (auto&x : intervals) {
            startInterval.push_back(x[0]);
            endInterval.push_back(x[1]);
        }
        sort(startInterval.begin(), startInterval.end());
        sort(endInterval.begin(), endInterval.end());
        int start = 0;
        int end = 0;
        int grpcnt=0;
        int ans = 0;
        while (start < intervals.size() && end < intervals.size()) {
            if (startInterval[start]<=endInterval[end]){
              grpcnt++;
              start++;
            }else{
              grpcnt--;
              end++;
            }
            ans=max(ans,grpcnt);
        }
        while(start<intervals.size()){
              grpcnt++;
              start++;
        }
        while(end<intervals.size()){
              grpcnt--;
              end++;
        }
        ans=max(ans,grpcnt);
        return ans;
    }
};