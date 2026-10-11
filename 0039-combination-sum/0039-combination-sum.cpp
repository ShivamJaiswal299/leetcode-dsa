class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& a, int k) {
      vector<vector<int>> ans;
      vector<int> curr;
      helper(0,a,k,curr,ans);
      return ans;
    }
private:
    void helper(int i,vector<int>&a,int k, vector<int> &curr, vector<vector<int>> &ans){
      if(k==0) { // satisfied.
        ans.push_back(curr);
        return;
      }
      if(i>= a.size() || k<0) return; //not satisfied
      helper(i+1,a,k,curr,ans);
      //NOTE - KEEP IN MIND IF ITS A REFRENCE VARIABLE U HAVE TO UNDO THE CHANGES BUT IF ITS NORMAL VAR THEN ITS COPY IS SEND SO NO ISSUE OF POPING BACK IT OUT
      curr.push_back(a[i]);
  //KEY POINT HERE IS THAT WE CAN USE ONE ELEMENT MULTIPLE TIMES IF ITS ADDED EVEN ONCE 
      helper(i,a,k-a[i],curr,ans);//DIDNT INCREASE i
      curr.pop_back();
    }
};