class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
      //logic is that the vector can be divided into 3 parts - 1.before overlapping 2. overlapping part that is to be merged 3.after overlapping part.
        vector<vector<int>> ans;
        int n = intervals.size();
        int i = 0;

        // 1. intervals completely before newInterval
        while (i < n && intervals[i][1] < newInterval[0]) {
            ans.push_back(intervals[i]);
            i++;
        }

        // 2. intervals overlapping with newInterval: merge
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        ans.push_back(newInterval);

        // 3. intervals completely after
        while (i < n) {
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};