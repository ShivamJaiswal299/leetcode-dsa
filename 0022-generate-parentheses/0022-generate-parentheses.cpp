class Solution {
//LOGIC-
// Add ( if we still have some left (open < n).Add ) only if it has a matching open bracket (close < open).When open == close == n, save the string, then undo the last step (backtrack) to try the other choice.
/*
THE TREE IS LIKE-
     (
    / \
   ((  ()
  / \   |
((( (() ()(
 .   .   .
 .   .   .
 */
public:
    vector<string> generateParenthesis(int n) {
      vector<string> ans;//FINAL ANS
      string curr = "";//EVERY TEMPERORY STRING
      helperfn(n,0,0,curr,ans);
      return ans;
    }
private:
    void helperfn(int n,int open,int close,string &curr,vector<string>&ans){
      if(open == close && close == n){//IF VALID STRING IS ENCOUNTERED
        ans.push_back(curr);
        return;
      }
      if(open < n){//OPEN CNT IS NOT FULL SO CAN ADD (
        curr.push_back('(');
        helperfn(n,open+1,close,curr,ans);
        curr.pop_back();//DELETE THIS ADDED PARANTHESIS SO THAT WE CAN TRY OTHER CASES
      }
      if(close < open){//CLOSED CNT IS NOT FULL SO CAN ADD )
        curr.push_back(')');
        helperfn(n,open,close+1,curr,ans);
        curr.pop_back();
      }
    }
};