class Solution {
public:
//logic - when opening bracket then push, else compare with the top most element
    bool isValid(string s) {
      stack<char> stk;
      string open = "({[";
      for(auto x:s){
        if(open.find(x)!=string::npos){
          stk.push(x);
        }
        else{
          if(stk.empty()) return false;
          char ch = stk.top();
          if(ch=='{' && x=='}' ||ch=='(' && x==')' ||ch=='[' && x==']') stk.pop(); 
          else return false;
          
        }
      }
      if(stk.empty()) return true;
      else return false;
    }
};