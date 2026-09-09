class Solution {
public:
    string largestOddNumber(string s) {
        for(int i = s.length()-1;i>=0;i--){
          if((s[i]-'0')%2==0) s.pop_back();
          else return s;
        }
        return "";
    }
};