class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        int n = a.size();
        sort(a.begin(), a.end());//sorting is neccesary as question doesnt guarantee sorted test cases.
        vector<vector<int>> result;
        int i=0;
        while(i<n){
          int left = a[i][0];
          int right = a[i][1];
          while(i<n-1 && right>=a[i+1][0]) {//right se isliye compare cuz it is the largest .second aur largest wala .second hi matter karta hai
            i++;
            right=max(right,a[i][1]);
          }
          result.push_back({left,right});
          i++;
        }
        return result;
    }
};