/*
    Decision Tree for digits = "23"
    (2 -> abc, 3 -> def)

    helper(i=0)                      curr = ""
         |
    +----+--------------+
    |                   |                   |
    a                   b                   c            <- digit '2' (i=0)
    |                   |                   |
 +--+--+             +--+--+             +--+--+
 |  |  |             |  |  |             |  |  |
 d  e  f             d  e  f             d  e  f         <- digit '3' (i=1)
 |  |  |             |  |  |             |  |  |
ad ae af            bd be bf            cd ce cf         <- i == size, save to ans

    Pattern : choose -> explore -> un-choose
    Depth   : number of digits
    Leaves  : answers
    Time    : O(4^n * n)
    Space   : O(n) recursion stack
*/
class Solution {
public:
    //BELOW ARE VARS DECLARED IN THE WHOLE CLASS
    const vector<string> letter = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;
    string curr;

    // MAIN FUNCTION
    vector<string> letterCombinations(string digits) {
      helper(0,digits);
      return ans;
    }
    void helper(int i,string &digits){
      //WHEN ALL DIGITS I.E. (possible letter combinations are filled) ADDING IT TO ANS
      if(i>=digits.size()) {
        ans.push_back(curr);
        return;
        }

      //HERE FOR EACH DIGIT TAKING ALL COMBINATION OF THAT DIGIT EG a b c 
      //key point - when tree has depth then at every depth recursion will be performed but at a same level like abc are in same level loop are runned.
      for(char ch: letter[digits[i]-'0']){
        curr.push_back(ch);
        helper(i+1,digits);
        curr.pop_back();
      }
    }
};