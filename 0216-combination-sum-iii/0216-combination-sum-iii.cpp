class Solution {
public:
    vector<vector<int>> combinationSum3(int n, int sum) {
      vector<int>a={1,2,3,4,5,6,7,8,9};
      vector<vector<int>> ans;
      vector<int>curr;
      helper(0,n,sum,a,curr,ans);
      return ans;
    }
private:
    void helper(int i,int n, int sum,vector<int> &a, vector<int> &curr, vector<vector<int>> &ans){
      //valid combination
      if(sum==0 && n==0){
        ans.push_back(curr);
        return;
      }
      if(sum<0 || n<0 || i>=a.size()){
        return;
      }
      helper(i+1,n,sum,a,curr,ans);
      curr.push_back(a[i]);
      helper(i+1,n-1,sum-a[i],a,curr,ans);
      curr.pop_back();
    }
};