class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& a, int k) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(a.begin(),a.end());
        helper(0,a,k,curr,ans);
        return ans;
    }
private:
    void helper(int i,vector<int>& a, int k,vector<int> &curr,vector<vector<int>> &ans){
      //base conditions
      if(k==0){
        ans.push_back(curr);
        return;
      }
      if(k<0 || i>=a.size() || a[i] > k) return;
      //first making all the 'pick the number' combination as here it takes all the numbber so no duplicate combination can form
      curr.push_back(a[i]);
      helper(i+1,a,k-a[i],curr,ans);
      curr.pop_back();

      //now combinations of 'skip the pick' , here only the cases of duplicacy can occur.
      //for that we have a trick 
      int j = i+1;
      while(j<a.size() && a[j]==a[i]) j++;
      helper(j,a,k,curr,ans);
    }
};