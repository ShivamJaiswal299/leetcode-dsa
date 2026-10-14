class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<string>> partition(string s) {
      vector<string> curr;
      helper(0,s,curr);
      return ans;
    }
    void helper(int i,string s,vector<string> &curr){
      if(i==s.length()){
        ans.push_back(curr);
        return;
      }
      for(int j = i; j<s.length();j++){
        if(isPalindrome(s,i,j)){
          curr.push_back(s.substr(i, j - i + 1));
          helper(j+1,s,curr);
          curr.pop_back();
        }
      }
    }
    bool isPalindrome(string s, int start, int end){
      while(start<=end){
        if(s[start++]!=s[end--]) return false;
      }
      return true;
    }
};