class Solution {
public:
    string result="";
    bool check(int a, int b){
      if(a>=b) return true;
      if(result[a]!=result[b]) return false;
      return check(++a,--b);
    }
    bool isPalindrome(string s) {
      for(char ch:s) if(isalnum(ch)) result+=tolower(ch);
      return check(0,result.length()-1);
      
    }
};