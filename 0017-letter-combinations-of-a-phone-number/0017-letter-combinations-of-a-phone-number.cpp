class Solution {
public:
    vector<string> letter = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;
    string curr;
    vector<string> letterCombinations(string digits) {
      helper(0,digits);
      return ans;
    }
    void helper(int i,string &digits){
      if(i>=digits.size()) {
        ans.push_back(curr);
        return;
        }
      for(char ch: letter[digits[i]-'0']){
        curr.push_back(ch);
        helper(i+1,digits);
        curr.pop_back();
      }
    }
};