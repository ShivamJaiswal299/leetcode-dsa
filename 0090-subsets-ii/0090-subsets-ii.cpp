class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& a) {
      vector<vector<int>> ans;
      vector<int> curr;
      sort(a.begin(),a.end());
      helper(0,a,curr,ans);
      return ans;
    }
private:
    void helper(int i, vector<int>&a, vector<int>&curr,vector<vector<int>>&ans){
      //checking subset validity
      if(i>=a.size()){
        ans.push_back(curr);
        return;
      }
      //normal for right side of tree
      curr.push_back(a[i]);
      helper(i+1,a,curr,ans);
      curr.pop_back();
      // extra trick to skip duplicate from the left side
      int j = i+1;
      while(j<a.size() && a[j]==a[i])j++;
      helper(j,a,curr,ans);
    }
};