class Solution {
public:
    string removeOuterParentheses(string s) {
        int depth = 0;
        string result = "";
        for(char c : s){
          if(c=='('){
            if(depth) result+=c;
            depth++;
          }
          else if(c==')'){
            depth--;
            if(depth) result+=c;
          }
        }
      return result;
    }
};